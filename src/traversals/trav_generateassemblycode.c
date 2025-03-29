/**
 * @file
 *
 * Traversal: GenerateAssemblyCode
 * UID      : GAC
 */

#include <stdarg.h>  // Add this for va_list support
#include <stdio.h>
#include <string.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include "global/globals.h"
#include "user/symbolTable/symbol_table.h"
#include "user/tables/exportTable/export_table.h"
#include "user/tables/variableTable/variable_table.h"

static void write_output(FILE *output, const char *format, ...);
static void print_exports(FILE *output, node_st *node);
static void print_imports(FILE *output, node_st *node);

static void write_output(FILE *output, const char *format, ...) {
  va_list args;
  va_start(args, format);
  if (output) {
    vfprintf(output, format, args);
  } else {
    vprintf(format, args);
  }
  va_end(args);
}

static void print_exports(FILE *output, node_st *node) {

  export_table_st *export_table = PROGRAM_EXPORT_TABLE(node);
  if (!export_table) {
    return;
  }

  export_entry_st *current = export_table->entries;

  while (current) {

    if(current->entry_type == EXPORT_FUNCTION) {



      write_output(output,
                   ".exportfun \"%s\" %s %s\n",
                   current->name,
                   typeToString(current->data.func.return_type),
                   current->name);
    } else if (current->entry_type == EXPORT_VARIABLE) {
      write_output(output,
                   ".exportvar \"%s\" %s\n",
                   current->name,
                   typeToString(current->data.var.var_type));
    }

    // write_output(output,
    //              ".exportfun \"%s\" %s %s\n",
    //              current->name,
    //              typeToString(current->entry_type),
    //              current->name);
    current = current->next;
  }
}

static void print_imports(FILE *output, node_st *node) {
  import_table_st *import_table = PROGRAM_IMPORT_TABLE(node);
  if (!import_table) {
    return;
  }

  import_entry_st *current = import_table->entries;

  while (current) {
    write_output(output,
                 ".importvar \"%s\" %s\n",
                 current->name,
                 typeToString(current->entry_type));
    current = current->next;
  }
}

static void print_globals(FILE *output, node_st *node) {


    

  
}

//calculates the amount of locals for the esr
int calculate_locals(node_st *node) {
  int locals = 0;

  node_st *parameters = FUNDEF_PARAMS(node);

  // Count the parameters as locals
  while (parameters) {
    locals++;
    parameters = PARAM_NEXT(parameters);
  }

  node_st *funbody = FUNDEF_BODY(node);

  node_st *iterator = FUNBODY_FUNCONTENTS(funbody);

  while (iterator) {
    
    node_st *funcontent = FUNCONTENTS_FUNCONTENT(iterator);

    if (NODE_TYPE(funcontent) == NT_VARDECL) {
      locals++;
    }
    iterator = FUNCONTENTS_NEXT(iterator);
  }

  return locals;
}

void GACinit() {
}

void GACfini() {

}

/**
 * @fn GACprogram
 */
node_st *GACprogram(node_st *node) {

  struct data_gac *data = DATA_GAC_GET();

  data->program = node;
  
  FILE *output_stream = stdout;


  write_output(data->output_file, "Generating assembly code...\n");

  if (global.output_file) {
    output_stream = fopen(global.output_file, "w");
    if (!output_stream) {
      fprintf(stderr, "Error: Could not open file '%s'\n", global.output_file);
      exit(EXIT_FAILURE);
    }
  }

  data->output_file = output_stream;

  print_globals(output_stream, node);

  TRAVchildren(node);

  print_exports(output_stream, node);
  print_imports(output_stream, node);

  if (output_stream != stdout) {
    fclose(output_stream);
  }

  return node;
}

/**
 * @fn GACfundef
 */
node_st *GACfundef(node_st *node) {
  struct data_gac *data = DATA_GAC_GET();
  
  data->output_file;

  const char *name = FUNDEF_NAME(node);
  write_output(data->output_file, "%s:\n", name);

  int locals = calculate_locals(node);

  write_output(data->output_file, "    esr %d\n", locals);

  TRAVchildren(node);
  return node;
}


/**
 * @fn GACvardecl
 */
node_st *GACvardecl(node_st *node) {



  //find the vardecl in the 
  // glob_var_entry_st *current = VTget(var_table, VARDECL_NAME(node));

  TRAVchildren(node);

  return node;
}

/**
 * @fn GACvar
 */
node_st *GACvar(node_st *node) {
  struct data_gac *data = DATA_GAC_GET();

  stable_st *symbol_table = VAR_TABLE(node);

  // TODO
  // Huidig situatie maakt een vardecl node in de buildvariable table een index aan.
  // Deze index staat dan op de vardecl node in de symbol table.
  // We willen de index van de vardecl node gebruiken in de assembly code.
  // We kunnen misschien of de index toevoegen aan de symbol table bij het aanmaken in builtsymboltable
  // Of var nodes linken aan de vardecl ofzo

  
  //get the index which is saved in the index nodeset
  // var_entry_st *result = STlookupVar(symbol_table, VAR_NAME(node), true);

  // glob_var_table_st *var_table = PROGRAM_VAR_TABLE(data->program);

  // glob_var_entry_st *current = VTget(var_table, INDEX_INDEX(node));

  // write_output(data->output_file, "    iload_%d\n", current->index);
  return node;
}

/**
 * @fn GACreturn
 */
node_st *GACreturn(node_st *node) {
  struct data_gac *data = DATA_GAC_GET();

  TRAVchildren(node);

  write_output(data->output_file, "    return\n");
  return node;
}

/**
 * @fn GACnum
 */
node_st *GACnum(node_st *node) {
  struct data_gac *data = DATA_GAC_GET();

  glob_var_table_st *var_table = PROGRAM_VAR_TABLE(data->program);
  
  write_output(data->output_file, "    iloadc %d\n", INDEX_INDEX(node));
  return node;
}


/**
 * @fn GACbinop
 */
node_st *GACbinop(node_st *node) {
  struct data_gac *data = DATA_GAC_GET();

  TRAVchildren(node);

  switch(BINOP_OP(node)) {
    case BO_add:
      write_output(data->output_file, "    iadd\n");
      break;
    case BO_sub:
      write_output(data->output_file, "    isub\n");
      break;
    case BO_mul:
      write_output(data->output_file, "    imul\n");
      break;
    case BO_div:
      write_output(data->output_file, "    idiv\n");
      break;
    case BO_mod:
      write_output(data->output_file, "    imod\n");
      break;
    default:
      // fprintf(stderr, "Error: Unknown binary operator\n");
      // exit(EXIT_FAILURE);
      break;
  }
  
  return node;
}




solve_expr(node_st *node) {
  // solve the expression
  node_st *expr = ASSIGN_EXPR(node);
  TRAVdo(expr);
  return expr;
}

/**
 * @fn GACassign
 */

node_st *GACassign(node_st *node) {
  TRAVchildren(node);

  struct data_gac *data = DATA_GAC_GET();
  glob_var_table_st *var_table = PROGRAM_VAR_TABLE(data->program);

  //solve assignment expression



  write_output(data->output_file, "    istore %d\n", INDEX_INDEX(node));


  return node;
}
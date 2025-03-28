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
    write_output(output,
                 ".exportfun \"%s\" %s %s\n",
                 current->name,
                 typeToString(current->return_type),
                 current->label);
    current = current->next;
  }
}

static void print_imports(FILE *output, node_st *node) {
  import_table_st *import_table = PROGRAM_IMPORT_TABLE(node);
  if (!import_table) {
    return;
  }

  import_entry_st *current = import_table->entries;
  // while (current) {
  //     write_output(output, ".importfun \"%s\" %s ",
  //                 current->func_name,
  //                 typeToString(current->return_type));

  //     param_entry_st *param = current->parameters;
  //     while (param) {
  //         write_output(output, "%s ", typeToString(param->type));
  //         param = param->next;
  //     }
  //     write_output(output, "\n");
  //     current = current->next;
  // }
}

static void print_globals(FILE *output, node_st *node) {
  global_var_table_st *var_table = PROGRAM_VAR_TABLE(node);
  if (!var_table) {
    return;
  }

  global_var_entry_st *current = var_table->globals;

  while (current) {
    write_output(output,
                 ".exportfun \"%s\" %s %s\n",
                 current->name,
                 typeToString(current->type),
                 current->name);
    current = current->next;

    global_extern_var_entry_st *current = var_table->externs;

    while (current) {
      write_output(output,
                   ".importvar \"%s\" %s\n",
                   current->name,
                   typeToString(current->type));
      current = current->next;
    }
  }
}

/**
 * @fn GACprogram
 */
node_st *GACprogram(node_st *node) {
  FILE *output_stream = stdout;

  if (global.output_file) {
    output_stream = fopen(global.output_file, "w");
    if (!output_stream) {
      fprintf(stderr, "Error: Could not open file '%s'\n", global.output_file);
      exit(EXIT_FAILURE);
    }
  }

  print_globals(output_stream, node);
  print_exports(output_stream, node);
  print_imports(output_stream, node);
  TRAVchildren(node);

  if (output_stream != stdout) {
    fclose(output_stream);
  }

  return node;
}

/**
 * @fn GACfundef
 */
node_st *GACfundef(node_st *node) {
  TRAVchildren(node);
  return node;
}

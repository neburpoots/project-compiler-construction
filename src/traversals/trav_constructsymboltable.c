/**
 * @file
 *
 * Traversal: ConstructSymbolTable
 * UID      : CST
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"

void CSTinit() { return; }
void CSTfini() { return; }

/**
 * @fn CSTprogram
 */
node_st *CSTprogram(node_st *node)
{
    printf("test");

    struct data_cst *data = DATA_CST_GET();
    // printf("test");
    // struct node_st *list = ASTtableentrylist(ASTtableentry("Test", CT_int), NULL);
    // struct node_st *table = ASTsymboltable(NULL, "Global");
    // PROGRAM_TABLE(node) = ASTsymboltable(NULL, "Global");
    // if(!PROGRAM_TABLE(node)) {
    //     PROGRAM_TABLE(node) = ASTsymboltable(NULL, "Global");
    // }
    // SYMBOLTABLE_LIST(PROGRAM_TABLE(node)) = ASTtableentrylist(NULL, NULL);
    PROGRAM_TEST(node) = 1;
    PROGRAM_TABLE(node) = ASTsymboltable();
    // data->symbolTables = ASTsymboltablelist(NULL, NULL);

    // PROGRAM_TABLE(node) = table;

    // TRAVchildren(node);
    // free(data->symbolTables);
    // CCNfree(data->symbolTables);
    // MEMfree(data->symbolTables);
    return node;
}

/**
 * @fn CSTfundef
 */
node_st *CSTfundef(node_st *node)
{

    // struct data_cst *data = DATA_CST_GET();

    // //add self to symbol table as entry
    // struct node_st *temp_list = data->symbolTables;
    // // struct NODE_DATA_SYMBOLTABLE *temp_table = temp_list->symboltablelist_children.symboltablelist_children_st.table;
    // // struct NODE_DATA_TABLEENTRYLIST *entry = temp_table->symboltable_children.symboltable_children_st.list;
    
    // //add to existing symbol table
    
    // node_st *parent_table = SYMBOLTABLELIST_TABLE(temp_list);
    // node_st *parent_list = SYMBOLTABLE_LIST(parent_table);
    // struct node_st *new_list = ASTtableentrylist(ASTtableentry(FUNDEF_NAME(node), FUNDEF_TYPE(node)), parent_list);

    // SYMBOLTABLE_LIST(parent_table) = new_list;

    // //create new symbol table for new scope
    // struct node_st *list = ASTtableentrylist(NULL, NULL);
    // struct node_st *table = ASTsymboltable(list, "fundef");

    // data->symbolTables = ASTsymboltablelist(table, data->symbolTables);

    // //construct new symboltables object with the current travdata list and the new one.
    // FUNDEF_PARENTSYMBOLTABLES(node) = ASTsymboltablelist(table, data->symbolTables);

    // TRAVchildren(node);

    // //remove self from symbol table  
    // data->symbolTables = temp_list;
    

    return node;
}

/**
 * @fn CSTfundec
 */
node_st *CSTfundec(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn CSTglobdef
 */
node_st *CSTglobdef(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn CSTglobdecl
 */
node_st *CSTglobdecl(node_st *node)
{
    TRAVchildren(node);


    return node;
}


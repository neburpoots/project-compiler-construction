#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef struct stable stable_st;
typedef struct var_entry var_entry_st;
typedef struct func_entry func_entry_st;

//create new table
stable_st *STnew(stable_st *parent);

//insert a var into the symbol table linked list
var_entry_st *STinsertVar(stable_st *table, const char *name);

//insert a func into the symbol table linked list
func_entry_st *STinsertFunc(stable_st *table, const char *name);

//lookup a var in the symbol table
var_entry_st *STlookupVar(stable_st *table, const char *name);

//lookup a func in the symbol table
func_entry_st *STlookupFunc(stable_st *table, const char *name);

//free the symbol table vars and fucns
void STfree(stable_st *table);
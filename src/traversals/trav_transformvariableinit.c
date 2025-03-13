/**
 * @file
 *
 * Traversal: TransformVariableInit
 * UID      : TVI
 *
 *
 */

 #include "ccn/ccn.h"
 #include "ccngen/ast.h"
 #include "ccngen/trav.h"
 #include <stdio.h>

 
 void TVIfini()
 {
     struct data_tvi *data = DATA_TVI_GET();
     
     if (data->assignments != NULL) {
         // Since we're using the nodes in the AST, we don't want to free them here
         Stackfree(data->assignments, false);
         data->assignments = NULL;
     }
 }
 
 void TVIinit()
 {
     struct data_tvi *data = DATA_TVI_GET();
     
     // Create a new stack for the assignment statements
     data->assignments = Stacknew(100);
 }
 
 /**
  * @fn TVIprogram
  */
 node_st *TVIprogram(node_st *node)
 {
    //  init_function = ASTfundef(NULL, ASTfunbody(NULL), "init", CT_void, false);

     TRAVchildren(node);
     return node;
 }
 
 /**
  * @fn TVIfundef
  */
 node_st *TVIfundef(node_st *node)
 {
     TRAVchildren(node);
     return node;
 }
 
 /**
  * @fn TVIfunbody
  */
 node_st *TVIfunbody(node_st *node)
 {
     TRAVchildren(node);
     return node;
 }
 
 /**
  * @fn TVIglobdef
  */
 node_st *TVIglobdef(node_st *node)
 {
     TRAVchildren(node);
     return node;
 }
 
 /**
  * @fn TVIvardecl
  */
 node_st *TVIvardecl(node_st *node)
 {
     // Process children first (dimensions might need processing)
     TRAVchildren(node);
     
     if (VARDECL_INIT(node)) {
         // Create a new varlet node with a copy of the name
         node_st *varlet = ASTvarlet(NULL, strdup(VARDECL_NAME(node)));
         
         // Create an assignment node with the initialization expression
         node_st *init = VARDECL_INIT(node);
         node_st *assign = ASTassign(varlet, init);
         
         // Save assignment in traversal data stack
         struct data_tvi *data = DATA_TVI_GET();
         Stackpush(data->assignments, assign);
         
         // Detach the init from the vardecl (don't free it)
         VARDECL_INIT(node) = NULL;
     }
     
     return node;
 }
 
 /**
  * @fn TVIfuncontents
  */
 node_st *TVIfuncontents(node_st *node)
 {
     // First, traverse the current function content
     if (FUNCONTENTS_FUNCONTENT(node)) {
         FUNCONTENTS_FUNCONTENT(node) = TRAVdo(FUNCONTENTS_FUNCONTENT(node));
     }
     
     // Check if the current function content is a variable declaration
     if (FUNCONTENTS_FUNCONTENT(node) && NODE_TYPE(FUNCONTENTS_FUNCONTENT(node)) == NT_VARDECL) {
         struct data_tvi *data = DATA_TVI_GET();
         
         // If we have assignments to insert after this declaration
         if (!StackisEmpty(data->assignments)) {
             node_st *assign = Stackpop(data->assignments);
             
             // Create a new function contents node that will come after the current one
             node_st *assign_funcontents = ASTfuncontents(assign, FUNCONTENTS_NEXT(node));
             FUNCONTENTS_NEXT(node) = assign_funcontents;
         }
     }
     
     // Continue with the next node in the list
     if (FUNCONTENTS_NEXT(node)) {
         FUNCONTENTS_NEXT(node) = TRAVdo(FUNCONTENTS_NEXT(node));
     }
     
     return node;
 }
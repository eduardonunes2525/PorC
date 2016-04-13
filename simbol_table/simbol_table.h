/*simbol_table.h
The data struct implemented is a binary tree with basic operations without
the operations of remove.
*/

// The content of each node, witch receive the data from compiler
struct data{
    char  name; // Name of variable identify by compiler 
    char  type; // The type of variable 
    int  value; // The actual value of a variable
} ;

struct node{
    struct data  content;
    struct node * node_left;
    struct node * node_rigth;
} ;

int insert(struct data,struct node raiz);

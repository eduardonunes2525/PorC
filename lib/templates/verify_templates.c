#include "verify_templates.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//const int NOT_FOUND = 0;
//const int INVALID_TYPE = 1;
//const int VALID_TYPE = 2;
char valid_types_list[4][10] = {
    "int", "double", "string", "char"
};

int verify_type(SimbolTable* simbols, char* name, char* type) {
    printf("\nDEBUG - Params of input %s %s\n", name, type);

    Variable* variable = SimbolTable_find(simbols, name); // Get the variable if exist in simbol table
    int valid = 0;

    if(variable != NULL) {
        printf("\nDEBUG - Value of type %s\n", variable->type);

        if(strcmp(type, variable->type) == 0) {
            printf("\nDEBUG - Type is equals");
            // Verify if the type os value is the same of variable
            valid = 1;
        }else{
            yyerror("Type of variable is different of value");
            exit(0);
           //valid = INVALID_TYPE;
        }
    }else{
        yyerror("Variable name not found");
        exit(0);
        //valid = NOT_FOUND;
        //Variable not found
    }

    return valid;
}


unsigned short is_number(SimbolTable* simbols, char* name) {
    assert(name != NULL);
    unsigned short valid_number = 0;

    Variable* variable = SimbolTable_find(simbols, name);

    if (variable != NULL) {
        if (strcmp(variable->type, valid_types_list[0]) == 0 ||
            strcmp(variable->type, valid_types_list[1]) == 0) {
            valid_number = 1;
        }
    }

    return valid_number;
}


static unsigned short valid_types(char* type) {
    assert(type != NULL);
    unsigned short is_a_valid_type = 0;

    for (int i = 0; i < 4; ++i) {
        if (strcmp(type, valid_types_list[i]) == 0) {
            is_a_valid_type = 1;
            break;
        }
    }

    return is_a_valid_type;
}

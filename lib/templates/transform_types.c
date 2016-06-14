#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "transform_types.h"
#include "../util/log.h"

char* transform_int_string(char* destiny_pointer, int value_tobe_converted) {
    destiny_pointer = malloc(MAX_NUMBER_OF_CARACTERS*sizeof (char));

    if (destiny_pointer != NULL) {
        sprintf(destiny_pointer, "%d", value_tobe_converted);
    } else{
        printf("\nERROR - Could not alloc memory for int -> str conversion\n");
        exit(1);
    }

    return destiny_pointer;
}

char* transform_double_string(char* destiny_pointer, double value_tobe_converted){
    destiny_pointer = malloc(MAX_NUMBER_OF_CARACTERS*sizeof (char));

    if (destiny_pointer != NULL) {
        sprintf(destiny_pointer, "%lf", value_tobe_converted);
    } else {
        printf("\nERROR - Nao foi possivel alocar memoria\n");
        exit(1);
    }

    return destiny_pointer;
}

char* transform_simbol_comparator(char* simbol_comparator){

    if (simbol_comparator != NULL) {
    	if(strcmp(simbol_comparator,"<>") == 0)
	{
	   strcpy(simbol_comparator,"!=");
	}
	if(strcmp(simbol_comparator,"=") == 0)
        {
           strcpy(simbol_comparator,"==");
        }
	else{
	   //Do nothing		
	}
    } else {
        printf("\nERROR - Nao foi possivel alocar memoria\n");
        exit(1);
    }

    return simbol_comparator;
}
char* transform_type_inital_value(char* type){
    // Only uses cut circuit to not use malloc function
    if (!strcmp(type,"int")){
        return "0";
    }else if(!strcmp(type,"char")){
        return "' '";
    }else if(!strcmp(type,"double")){
        return "0.0";
    }else if(!strcmp(type,"bool")){
        return "0";
    }else{
        Log_error("Invalid type transformation");
        exit(0);
    }
}


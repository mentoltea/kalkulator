#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "read_args.h"



char** filter_args(char* input, size_t len, char* operations, size_t operations_len) {
    char* sep = NULL;
    for (int i = 0; i<operations_len; i++) {
        sep = strchr(input, operations[i]);
        if (sep != NULL) {
            break;
        }
    }
    if (sep==NULL) {
        printf("Supportable operation was not found\n");
        exit(1);
    }
    printf("operation: %c\n", *sep);
    char** result = (char**)malloc(3*sizeof(char*));

    if (sep==input) {
        char* arg1 = substr(input, 1, strlen(input));
        result[0] = arg1;
        result[1] = sep;
        result[2] = arg1;
        return result;
    }
    else {
        char *arg1 = (char*) malloc((sep-input+1)*sizeof(char));
        char *arg2 = (char*) malloc(((input-sep)+len+1)*sizeof(char));

        arg1 = memcpy(arg1, input, (sep-input)*sizeof(char));
        arg1[sep-input+1]='\0';

        arg2 = memcpy(arg2, sep+1, ((input-sep)+len+1)*sizeof(char));
        if (strlen(arg2)==1) {
            printf("Arg2 is empty!\n");
            exit(1);
        }
        printf("arg1: %s\narg2: %s\n", arg1, arg2);

        char* operation[1];
        operation[0]=*sep;
        
        result[0] = arg1;
        result[1] = operation;
        result[2] = arg2;
        return result;
    }
}
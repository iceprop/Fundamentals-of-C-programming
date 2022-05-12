//
// Created by Demien on 11/05/2022.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10
#define ROWS 3

int main(int argc, char **argv){
    if(argc < 4){
        printf("Non sono presenti i 3 elementi necessari");
        exit(EXIT_FAILURE);
    }

    char* temp;
    for (int i = 0; i < argc-1; ++i) {
        for (int j = 0; j < argc-1; ++j) {
            if(strcmp(argv[i], argv[i+1]) > 0){
                temp = argv[i];
                argv[i] = argv[i+1];
                argv[i+1] = temp;
            }
        }
    }
    printf("Stringhe in ordine di lunghezza: \n");
    for (int i = 1; i < argc; ++i) {
        printf("%s\n", argv[i]);
    }

    int totalLength = 0;
    for (int i = 1; i < argc; ++i) {
        totalLength += strlen(argv[i]);
    }
    char *concatStrP;
    concatStrP = (char*)calloc(totalLength, sizeof(int));
    for (int i = 1; i < argc; ++i) {
        strcat(concatStrP, argv[i]);
    }
    printf("\nConcatenazione delle stringhe:\n%s\n\n", concatStrP);
    free(concatStrP);

    printf("Stringhe che iniziano con una lettera maiuscola:\n");
    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] >= 'A' && argv[i][0] <= 'Z') printf("%s\n", argv[i]);
    }

    return 0;
}
//
// Created by Demien on 13/05/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void map(int (fun) (int, int), int X[], int Y[], int Z[]) {
    int i;
    for (i=0; i<5; i++) {
        Z[i] = fun(X[i], Y[i]);
    }
}

int somma(int a, int b) {
    return(a+b);
}

int sottrazione(int a, int b) {
    return(a-b);
}

int prodotto(int a, int b) {
    return(a*b);
}

int divisione(int a, int b) {
    return(a/b);
}

int applica(int (*ptrfun) (int, int), int n, int m){
    return ptrfun(n, m);
}

int main(int argc, char **argv) { // argc contiene il numero di stringhe inserite dall'utente a riga di comando
    int a = 4, b = 5;             // argv è l'array che contiene le stringhe inserite, ogni elemento dell'array è un puntatore a char
    int (*ptrFun) (int, int);

    ptrFun = somma;
    printf("La somma tra %d e %d \x8a: %d.\n", a, b, applica(ptrFun, a, b));

    ptrFun = sottrazione;
    printf("La sottrazione tra %d e %d \x8a: %d.\n", a, b, applica(ptrFun, a, b));

    ptrFun = prodotto;
    printf("Il prodotto tra %d e %d \x8a: %d.\n", a, b, applica(ptrFun, a, b));

    ptrFun = divisione;
    printf("La divisione tra %d e %d \x8a: %d.\n", a, b, applica(ptrFun, a, b));


    printf("----------------------------------------\n");

    if (argc > 1) {
        printf("Operazione con gli argomenti:\n");
        a = atoi(argv[1]); // convertitore da stringa ad intero
        b = atoi(argv[2]);
        switch (*argv[3]) {
            case '+':
                ptrFun = somma;
                break;
            case '-':
                ptrFun = sottrazione;
                break;
            case '*':
                ptrFun = prodotto;
                break;
            case '/':
                ptrFun = divisione;
                break;
            default:
                printf("Operazione non valida");
                exit(EXIT_FAILURE);
        }
        printf("Il risultato dell'operazione tra %d e %d \x8a: %d.\n", a, b, applica(ptrFun, a, b));
    }

    if (argc <= 1) {
        char operator;
        printf("\nOperazioni da riga di comando:\n");
        while (true) {
            printf("Inserisci il primo numero:");
            scanf("%d", &a);
            printf("Inserisci il secondo numero:");
            scanf("%d", &b);
            printf("Inserisci l'operatore:");
            scanf(" %c", &operator);
            switch (operator) {
                case '+':
                    ptrFun = somma;
                    break;
                case '-':
                    ptrFun = sottrazione;
                    break;
                case '*':
                    ptrFun = prodotto;
                    break;
                case '/':
                    ptrFun = divisione;
                    break;
                default:
                    printf("Operazione non valida");
                    exit(EXIT_FAILURE);
            }
            printf("Il risultato dell'operazione tra %d e %d \x8a: %d.\n", a, b, applica(ptrFun, a, b));
        }
    }

    return 0;
}
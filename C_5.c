//
// Created by Demien on 09/05/2022.
//

#include <string.h>
#include <stdio.h>
#include <malloc.h>

#define N 10

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main(){
    printf("Versione con malloc\n");
    int *p1 = (int*)malloc((N * sizeof(int)));
    for(int i=0; i<N; ++i){
        *p1++ = fib(i);
    }

    p1 -= N;
    int i = 0;
    while (i < N) {
        printf("Il numero %d dei numeri di fibonacci \x8a: %d\n", i++, *p1++);
    }

    p1 -= N;
    free(p1);

    printf("-------------------------------------------\n");

    printf("Versione con calloc\n");
    int *p2 = (int*)calloc(N, sizeof(int));
    for (int j = 0; j < N; ++j) {
        *p2++ = fib(j);
    }

    p2 -= N;
    int j = 0;
    while (j < N){
        printf("Il numero %d dei numeri di fibonacci \x8a: %d\n", j++, *p2++);
    }

    p2 -= N;
    free(p2);


}

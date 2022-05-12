//
// Created by Demien on 08/05/2022.
//

#include <stdio.h>
#include <stdbool.h>
#define N 15
#define LENGHT(x) (sizeof(x) / sizeof((x)[0]))

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int verifica(int n){
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p, i;
    int m = sizeof(arr1)/sizeof(arr1[0]);
    p = arr1;
    for(i=0; i<m; ++i)
        if(n == p[i])
            return true;

    return false;
}

int restituisci(int i, int arr[]){
    int *p;
    p = arr;
    if(p[i]){
        return arr[i];
    }else{
        return 0;
    }
}

int somma(int arr[], int len){
    int risultato = 0;
    for(int i=0; i<len; ++i){
        risultato = risultato + arr[i];
    }
    return risultato;
}

int sonoUguali(int arr1[], int arr2[]){
    int *p1, *p2, i;
    p1 = arr1;
    p2 = arr2;
    int n = sizeof(p1);
    for(i=0; i<=n; i++){
        if(p1[i] == p2[i]){
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int *p, i, vet[N];
    p = vet;
    for (i = 0; i < N; ++i) {
        p[i] = fib(i);
    }
    for (i = 0; i < N; ++i) {
        printf("Il numero %d dei numeri di Fibonacci \x8a: %d\n", i, p[i]);
    }

    printf("-------------------------\n");

    printf("Il valore \x8a nell'array?\n%d\n", verifica(15));

    printf("-------------------------\n");

    int arr[] = {3, 8, 2, 15, 5, 39, 75, 69, 21, 110, 3};
    printf("Restituisci:\n%d", restituisci(5, arr));

    printf("\n-------------------------\n");

    printf("La somma dell'array \x8a: %d\n", somma(arr, LENGHT(arr)));

    printf("-------------------------\n");

    int arrey[] = {3, 8, 2, 15, 5, 39, 75, 69, 21, 110};
    printf("I 2 array sono uguali?\n%d\n", sonoUguali(arr, arrey));

    return 0;
}

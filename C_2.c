//
// Created by Demien on 08/05/2022.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define N 3

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

void soloVocaliMinuscole(char stringa[]) {
    int len = strlen(stringa);
    char nuovaStringa[100];
    int j = 0;
    for (int i = 0; i < len; ++i) {
        if (stringa[i] == 'a' || stringa[i] == 'e' || stringa[i] == 'i' || stringa[i] == 'o' || stringa[i] == 'u') {
            nuovaStringa[j] = stringa[i];
            j++;
        }
    }
    printf("La stringa contenente solo le vocali minuscole \x8a: %s\n", nuovaStringa);
}

struct numeroComplesso {
    float parteIntera;
    float parteImmaginaria;
};

bool sonoUguali(struct numeroComplesso num1, struct numeroComplesso num2) {
    return (num1.parteIntera == num2.parteIntera && num1.parteImmaginaria == num2.parteImmaginaria);
}

struct numeroComplesso somma(struct numeroComplesso num1, struct numeroComplesso num2) {
    struct numeroComplesso num = {num1.parteIntera + num2.parteIntera, num1.parteImmaginaria + num2.parteImmaginaria};
    return num;
}

int main() {
    int fibArr[] = {fib(0), fib(1), fib(2), fib(3), fib(4)};
    for (int i = 0; i < 5; ++i) {
        printf("Il numero %d dei numeri di Fibonacci \x8a: %d\n", i, fibArr[i]);
    }

    printf("----------------------------------------\n");

    int fibArr2[N];
    for (int i = 0; i < N; ++i) {
        fibArr2[i] = fib(i);
    }
    for (int i = 0; i < N; ++i) {
        printf("Il numero %d dei numeri di Fibonacci \x8a: %d\n", i, fibArr2[i]);
    }

    printf("----------------------------------------\n");

    soloVocaliMinuscole("Ciaone");

    printf("----------------------------------------\n");

    struct numeroComplesso num1 = {1, 5};
    struct numeroComplesso num2 = {1, 5};
    printf("num1 \x8a: %f + i%f\n", num1.parteIntera, num1.parteImmaginaria);
    sonoUguali(num1, num2) ? printf("I due numeri sono uguali\n") : printf("I due numeri non sono uguali\n");
    printf("La somma tra num1 e num2 \x8a:  %f + i%f\n", somma(num1, num2).parteIntera, somma(num1, num2).parteImmaginaria);

    return 0;
}

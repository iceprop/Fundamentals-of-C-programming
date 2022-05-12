//
// Created by Demien on 08/05/2022.
//
#include <stdio.h>
#include <stdbool.h>

typedef struct numeroComplesso{
    float parteIntera;
    float parteImmaginaria;
}numeroComplesso;

typedef enum tipoNumero{
    INTERO,
    REALE,
    REALEDOPPIO,
    COMPLESSO
}tipoNumero;

typedef struct num{
    tipoNumero tipo;
    union{
        int intero;
        double reale;
        long double doppio;
        numeroComplesso complesso;
    }valore;
}numero;

bool sonoUguali(numeroComplesso num1, numeroComplesso num2) {
    return (num1.parteIntera == num2.parteIntera && num1.parteImmaginaria == num2.parteImmaginaria);
}

numeroComplesso somma(numeroComplesso num1, numeroComplesso num2) {
    numeroComplesso num = {num1.parteIntera + num2.parteIntera, num1.parteImmaginaria + num2.parteImmaginaria};
    return num;
}

numeroComplesso stampaNumero(numero num){
    switch (num.tipo) {
        case INTERO:
            printf("Tipo: INTERO, valore %d\n", num.valore.intero);
            break;
        case REALE:
            printf("Tipo: REALE, valore %f\n", num.valore.reale);
            break;
        case REALEDOPPIO:
            printf("Tipo: REALEDOPPIO, valore %Lf\n", num.valore.doppio);
            break;
        case COMPLESSO:
            printf("Tipo: NUMERO COMPLESSO, valore %f i%f\n", num.valore.complesso);
            break;
    }
}

int main(){
    numeroComplesso num1 = {1, 5};
    numeroComplesso num2 = {3, 7};

    sonoUguali(num1, num2) ? printf("I 2 numeri sono uguali\n") : printf("I 2 numeri sono diversi\n");
    printf("La somma dei 2 numeri \x8a:%f i%f\n", somma(num1, num2).parteIntera, somma(num1, num2).parteImmaginaria);

    printf("------------------------------------------\n");

    numero intero;
    intero.tipo = INTERO;
    intero.valore.intero = 5;
    stampaNumero(intero);

    numero reale;
    reale.tipo = REALE;
    reale.valore.reale = 5.484887;
    stampaNumero(reale);

    numero complesso;
    complesso.tipo = COMPLESSO;
    complesso.valore.complesso = num1;
    stampaNumero(complesso);

    return 0;
}
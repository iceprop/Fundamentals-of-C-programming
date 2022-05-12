//
// Created by Demien on 11/05/2022.
//

#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main(int argc, char **argv) {
    char **end_ptr = NULL;
    if(argc == 2){
        printf("fib(%lu): %d\n", strtol(argv[1], end_ptr, 10), fib(strtol(argv[1], end_ptr, 10)));
        return 0;
    }

    if(argc > 1){
        for (int i = 0; i < argc; ++i) {
            printf("fib(%lu): %d\n", strtol(argv[1], end_ptr, 10), fib(strtol(argv[1], end_ptr, 10)));
        }
        return 0;
    }

    if(argc <= 1){
        int n;
        printf("Not an argument. Please digit the argument:\n");
        scanf("%d", &n);
        printf("fib(%d): %d\n", n, fib(n));
    }
}


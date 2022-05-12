//
// Created by Demien on 03/05/2022.
//
int global = 0;

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

void firstFiveFib() {
    printf("I primi 5 numeri di Fibonacci sono: ");
    for (int i = 0; i < 8; ++i) {
        printf("%d, ", fib(i));
    }
}

void fun1() {
    global++;
}

void callFun1() {
    fun1();
    printf("Chiamate di fun1(): %d.\n", global);
}

int fun2() {
    static int local = 0;
    local++;
    return local;
}

void callFun2() {
    printf("Chiamate di fun2(): %d.\n", fun2());
}

int main() {
    printf("Il settimo numero di Fibonacci \x8a %d.\n", fib(7));
    firstFiveFib();
    callFun1();
    callFun2();
    callFun2();

    return 0;
}



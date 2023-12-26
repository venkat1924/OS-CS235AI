#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Did not pass in argument.\n", argv[0]);
        return 1;
    }

    int num = atoi(argv[1]);

    if (num < 0) {
        printf("Please provide a non-negative number.\n");
        return 1;
    }

    unsigned long long fact = factorial(num);
    printf("Factorial of %d is %llu\n", num, fact);

    return 0;
}

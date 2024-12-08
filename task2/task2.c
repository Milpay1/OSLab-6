#include <stdio.h>
#include <stdlib.h>

/* Function prototypes for the operations */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int exit_program(int a, int b); // Match return type to int

/* Main function */
int main(void) {
    // Array of function pointers
    int (*operations[5])(int, int) = {add, subtract, multiply, divide, exit_program};

    // Two predefined integers
    int x = 6, y = 3;

    // Display operands
    printf("Operand ‘a’ : %d | Operand ‘b’ : %d\n", x, y);

    // Prompt user for input
    printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
    char input = getchar();

    // Validate input and execute corresponding operation
    if (input >= '0' && input <= '4') {
        int index = input - '0'; // Convert character to integer index
        printf("x = %d\n", operations[index](x, y));
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}

/* Function definitions */
int add(int a, int b) {
    printf("Adding ‘a’ and ‘b’\n");
    return a + b;
}

int subtract(int a, int b) {
    printf("Subtracting ‘b’ from ‘a’\n");
    return a - b;
}

int multiply(int a, int b) {
    printf("Multiplying ‘a’ and ‘b’\n");
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero.\n");
        exit(1);
    }
    printf("Dividing ‘a’ by ‘b’\n");
    return a / b;
}

int exit_program(int a, int b) {
    printf("Exiting program.\n");
    exit(0);
    return 0; // To satisfy the return type
}

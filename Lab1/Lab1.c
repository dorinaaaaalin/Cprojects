#include <stdio.h>
#include <stdlib.h>

/* This program read two inputs from the user
 * and generates outputs (sum of two numbers, difference of two numbers
 * square of the first number, square of the second number, division of the two numbers)
 */
int main(int argc, char** argv) 
{
    //create variables inputnumbers
    int inputNumber1=0;
    int inputNumber2=0;
    
    //ask the users to put into numbers
    printf("Enter First Number: ");
    scanf("%d", &inputNumber1);
    printf("Enter Second Number: ");
    scanf("%d", &inputNumber2);
    
    //create variables sum, dif, squ, squ2, div
    int sum = inputNumber1 + inputNumber2;
    int dif = inputNumber1 - inputNumber2;
    int squ = inputNumber1 * inputNumber1;
    int squ2 = inputNumber2 * inputNumber2;
    int div = inputNumber2 / inputNumber1;
    
    //print the final output
    printf("Sum: %d \n Difference: %d \n Square of Number 1: %d \n Square of Number 2: %d \n Division: %d \n", sum, dif, squ,squ2,div);
    
    return (EXIT_SUCCESS);
}


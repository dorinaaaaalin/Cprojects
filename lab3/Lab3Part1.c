#include <stdio.h>
#include <stdlib.h>

/* This program acts like a calculator.  
 * It asks the user to input two numbers and a character.
 */
 
int main(int argc, char** argv) {
    
    //create variables
    double inputNumber1 = 0;
    double inputNumber2 = 0;
    char calculationCommand = 'z';
    double output = 0;
    
    //Prompt the user to input two double typed numbers and a character
    printf("Enter first number: ");
    scanf("%lf", &inputNumber1);
    
    printf("Enter second number: ");
    scanf("%lf", &inputNumber2);
    
    printf("Enter calculation command (one of a, s, m, or d): ");
    scanf("%s", &calculationCommand);
    
    //if or else if loop for adding, subtraction, multiplication, division
    if(calculationCommand == 'a'){
        output = inputNumber1 + inputNumber2;
        printf("Sum of %0.2lf and %0.2lf is %0.2lf", inputNumber1, inputNumber2, output);
    }
    else if(calculationCommand == 's'){
        output = inputNumber1 - inputNumber2;
        printf("Difference of %0.2lf from %0.2lf is %0.2lf", inputNumber1, inputNumber2, output);
    }
    else if(calculationCommand == 'm'){
        output = inputNumber1 * inputNumber2;
        printf("Product of %0.2lf and %0.2lf is %0.2lf", inputNumber1, inputNumber2, output);
    }
    
    //for division, there are two cases 
    if(calculationCommand == 'd' && inputNumber2 != 0){
        output = inputNumber1 / inputNumber2;
        printf("Division of %0.2lf by %0.2lf is %0.2lf", inputNumber1, inputNumber2, output);
    }
    else if (calculationCommand == 'd' && inputNumber2 == 0){
        printf("Error, trying to divide by zero");
    }
    
    
    if(calculationCommand != 'a' && calculationCommand != 's' && calculationCommand != 'm' && calculationCommand!= 'd'){
        printf("Error, unknown calculation command given");
    }
    

    return (EXIT_SUCCESS);
}


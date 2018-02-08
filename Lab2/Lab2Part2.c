#include <stdio.h>
#include <stdlib.h>

/* This system helps Afshin to ask the user to enter and encrypted four digit code
 *  and it will print the real four digit code
 */
int main(int argc, char** argv) {
    
    int fourDigitCode;
    
    //Prompt the user to enter an encrypted four digit code
    printf("Enter an encrypted 4-digit code: ");
    scanf("%d", &fourDigitCode);
    
    //created variables for different digits
    int firstDigit = fourDigitCode/1000;
    int secondDigit = (fourDigitCode/100)%10;
    int thirdDigit = (fourDigitCode/10)%10;
    int fourthDigit = fourDigitCode%10;
    
    // swap the second digit and third digit
    int newSecondDigit = thirdDigit;
    int newThirdDigit = secondDigit;
    
    // replace the first digit and fourth digit by its 9's complement
    int newFirstDigit = 9 - firstDigit;
    int newFourthDigit = 9 - fourthDigit;
    
    //prints the real four digit code
    printf("The real 4-digit code is: %d%d%d%d", newFirstDigit, newSecondDigit, newThirdDigit, newFourthDigit);
    
    return (EXIT_SUCCESS);
}
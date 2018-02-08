
#include <stdio.h>
#include <stdlib.h>

/* This program can predicting the stock market 
   by using the given formula
 */
int main(int argc, char** argv){
    //create the variables
    int consistency;
    double D1,D2,D3;
    const double CONSTANT = 1.2;
    const int CONSTANTSECOND = 10;
    
    //Prompt the user to enter yesterday's stock market value
    printf("Enter the stock market value yesterday (D1): ");
    scanf("%lf", &D1);
    
    //Prompt the user to enter the stock market value two days ago
    printf("Enter value two days ago (D2): ");
    scanf("%lf", &D2);
    
    //Prompt the user to enter the stock market value three days ago
    printf("Enter value three days ago (D3): ");
    scanf("%lf", &D3);
    
    //Prompt the user the consistency
    printf("Enter consistency, from 1 to 10: ");
    scanf("%d", &consistency);
    
    //Compute the prediction of stock market
    double prediction = D1 + ((((D1 - D2) + (D2 - D3) / CONSTANT)/2) * consistency/ CONSTANTSECOND );
    
    //output the result
    printf("Prediction of stock market is %5.2lf", prediction);
    return (EXIT_SUCCESS);
}


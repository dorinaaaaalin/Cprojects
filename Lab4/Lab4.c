#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * 
 */
double gaussFunc(double x, double spread){
    double function = exp(- pow(x, 2)/ spread);
    return function;
}

int main(int argc, char** argv) {
    double userSpread = -1;
    int n = 1;
    double a,b;
    double integral;
    
    while(userSpread <= 0){
        printf("Enter the spread value (must be >0): ");
        scanf("%lf", &userSpread);
    }
    
    while(n >= 1){
        int n;
        printf("Please enter the number of rectangles (n): ");
        scanf("%d", &n);
        
        if(n < 1){
            printf("Exiting.");
            exit(0);
        }
        else{
            double a = 3.0;
            double b = 1.0;
            while(a > b)
            {
                printf("Enter the interval of integration (a b): ");
                scanf("%lf %lf", &a, &b);
                if(a > b)
                {
                    printf("Invalid interval!\n");
                }
            }
            double width = (b-a)/n;
            
            for(double userX = a + width/2; userX <= b; userX = userX + width)
            {
                integral = integral + width * gaussFunc(userX,userSpread);
        
            }
            printf("Integral of Gaussian with spread %.3lf on [%.3lf, %.3lf] with n = %d is: %.3lf\n\n", userSpread, a, b, n, integral);
            integral = 0;
        }
    }
    return (EXIT_SUCCESS);
}


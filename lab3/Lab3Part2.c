#include <stdio.h>
#include <stdlib.h>

/*The program asks the user to guess a number thats 
 * generated from the program. 0----> exit the program
 */
int main(void) {
    //creates variables
    int seed = 0;
    int numberGenerated ;
    int numberGuessed ;
    
    //prompt the user to enter seed
    printf("Enter seed: ");
    scanf("%d", &seed);
    
    //random the seed
    srand(seed);
    //srand(time(NULL));
    
    
    while(numberGuessed > 0 ){
        //prompt the user to enter the guessed number
        printf("Guess a number from 1 to 7 (<=0 to quit): ");
        scanf("%d", &numberGuessed);
        //if guessed number is too high then print try again
        if(numberGuessed > 7)
        {
            printf("Number too high, guess again!\n");
        }
        //generate a random number between 1 and 7
        if(numberGuessed <=7)
        {
        numberGenerated = rand()%7 + 1;
        }           
        //if numberGenerated does not equal to numberGuessed then print sorry try again
        if(numberGenerated != numberGuessed && numberGuessed <= 7 && numberGuessed != 0)
        {
            printf("Number picked: %d\n", numberGenerated);
            printf("Sorry, try again!\n");
            //numberGenerated = rand()%7 + 1;
        }
        //number guessed is the same as the number generated
        else if(numberGuessed == numberGenerated )
        {
            printf("Number picked: %d\n", numberGenerated);
            printf("Good guess!\n");
        }
        //if user wants to exit the program 
        if(numberGuessed == 0)
        {
            printf("Goodbye");
            exit(0);
        }
    }
    
   
    
    return (EXIT_SUCCESS);
}


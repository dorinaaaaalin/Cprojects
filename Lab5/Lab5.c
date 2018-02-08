
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * 
 */

char* readSequence(int sequenceLength,char userInput[sequenceLength]){
    char * sequenceInput;
    sequenceInput = &userInput;
    for(int i=0; i < sequenceLength; i++){
        scanf(" %c", &userInput[i]);
    }
    return sequenceInput;
}
void searchSequence(char DNA[],int sequenceLength, char userInput[sequenceLength]){
    int index;
    int count = 0;
    bool work = false;
        for(int i=0; i <= 100 && !work; i++){
            count = 0; //Checks DNA
            for(int j=0; j < sequenceLength && !work; j++){ //Checks the userInput
                if(DNA[i+j]==userInput[j] || userInput[j]=='*'){ //&& DNA[i+1]==userInput[j+1])
                    index = i;
                    count++;
                }
                if (count == sequenceLength && (index+sequenceLength)<100) {
                    printf("Match of search sequence found at element %d\n", index);
                }
        }
    }
    
}
int main(int argc, char** argv) {
    int length;
    bool work = true;
    
    char DNA[] = {'A', 'G', 'C', 'G', 'G', 'G', 'A', 'C', 'C', 'G', 'T', 'C', 
	      'C', 'C', 'G', 'A', 'C', 'A', 'T', 'T', 'G', 'A', 'T', 'G', 
	      'A', 'A', 'G', 'G', 'G', 'T', 'C', 'A', 'T', 'A', 'G', 'A', 
	      'C', 'C', 'C', 'A', 'A', 'T', 'A', 'C', 'G', 'C', 'C', 'A', 
	      'C', 'C', 'A', 'C', 'C', 'C', 'C', 'A', 'A', 'G', 'T', 'T', 
	      'T', 'T', 'C', 'C', 'T', 'G', 'T', 'G', 'T', 'C', 'T', 'T', 
	      'C', 'C', 'A', 'T', 'T', 'G', 'A', 'G', 'T', 'A', 'G', 'A', 
	      'T', 'T', 'G', 'A', 'C', 'A', 'C', 'T', 'C', 'C', 'C', 'A', 
	      'G', 'A', 'T', 'G', '\0'};
    
    printf("Enter length of DNA sequence to match: ");
    scanf("%d", &length);
    
    char userInput[length];
    while(length>0 && work){
    printf("Enter %d characters (one of AGTC*) as a search sequence: ", length);
       
             readSequence(length, userInput);
             for(int i=0; i<length; i++){
                 if(userInput[i]!='A'&& userInput[i]!='G'&& userInput[i]!='C'&& userInput[i]!='T'&& userInput[i]!='*'){
                     printf("Erroneous character input '%c' exiting\n", userInput[i]);
                     work=false;
                 }
             }
             searchSequence(DNA, length, userInput);
             if(work){
             printf("Enter length of DNA sequence to match: ");
             scanf("%d", &length);
             }
    
    }
    printf("Goodbye");
    return (EXIT_SUCCESS);
    
}


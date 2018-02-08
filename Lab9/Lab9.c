//
// APS105-F15 Lab 9 Lab9.c
//
// Author: Xinzhe Lin
// Student Number: 1003571075
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>



// Note this is a change from the previous version of this lab
// which used a const int MAX_LENGTH = 1024
// which didnt compile on some machines
// Please use this syntax exactly (which hasnt been taught in class):
#define MAX_LENGTH 1024

typedef struct song {
    char songName[MAX_LENGTH] ;
    char artist[MAX_LENGTH] ;
} Song ;

// Same change here:
#define MAX_LIBRARY_SIZE 100



// Declarations of support functions
// See below the main function for descriptions of what these functions do

void getStringFromUserInput(char s[], int arraySize);
void songNameDuplicate(char songName[]);
void songNameFound(char songName[]);
void songNameNotFound(char songName[]);
void songNameDeleted(char songName[]);
void artistFound(char artist[]);
void artistNotFound(char artist[]);
void printMusicLibraryEmpty(void);
void printMusicLibraryTitle(void);

void printList(Song Library[],int size){
    for(int i=0;i<size;i++){
        
            printf("\n%s\n",Library[i].songName);
            printf("%s\n",Library[i].artist);
          //  printf("\n");
       
    }
}

void cocktailSort(Song Library[], int size){
    Song temp;
    bool swap = true;
    //bubble sort sorts from bottom to top
    for(int top=size-1,bottom=0; top>bottom && swap; top--,bottom++){ //BOTTOM<SIZE? BOTTOM <SIZE-1
        swap=false;
        for(int i=0;i<top; i++){
            if(strcmp(Library[i].artist,Library[i+1].artist)>0){
                temp=Library[i];
                Library[i]=Library[i+1];
                Library[i+1]=temp;
                swap=true;
            }
            //if the artsits are the same
            else if(strcmp(Library[i].artist,Library[i+1].artist)==0){
                if(strcmp(Library[i].songName,Library[i+1].songName)>0){
                    temp=Library[i];
                    Library[i]=Library[i+1];
                    Library[i+1]=temp;
                    swap=true;
                }
            }
        }
        //sorts from top to bottom
        for(int j=size-1;j>bottom;j--){
            if(strcmp(Library[j].artist,Library[j-1].artist)<0){
                temp=Library[j];
                Library[j]=Library[j-1];
                Library[j-1]=temp;
                swap=true;
            }
            //if the artists are the same
            else if(strcmp(Library[j].artist,Library[j-1].artist)==0){
                if(strcmp(Library[j].songName,Library[j-1].songName)<0){
                    temp=Library[j];
                    Library[j]=Library[j-1];
                    Library[j-1]=temp;
                    swap=true;
                }
            }
       }
       
    }
}

int main(void) {
    // Declare the head of the linked list.
  
    //   ADD YOUR STATEMENT(S) HERE
    int size = 0;
    Song Library[MAX_LIBRARY_SIZE] ;
    
    // Announce the start of the program
    printf("%s", "Personal Music Library.\n\n");
    printf("%s", "Commands are I (insert), S (sort by artist),\n"
         "P (print), Q (quit).\n");
    
    char response;
    char input[MAX_LENGTH + 1];
    do {
        printf("\nCommand?: ");
        getStringFromUserInput(input, MAX_LENGTH);

        // Response is the first character entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if (response == 'I') {
            // Insert a song into the linked list.
            // Maintain the list in alphabetical order by song name.
            //   ADD STATEMENT(S) HERE
            
            // USE THE FOLLOWING PRINTF STATEMENTS WHEN PROMPTING FOR DATA:
             printf("Song name: ");
                getStringFromUserInput(Library[size].songName, MAX_LENGTH);
                
             printf("Artist: ");
                getStringFromUserInput(Library[size].artist, MAX_LENGTH);
                
            size++;
        }
        else if (response == 'S') {
            // Search for a song by its name.
            if(size==0)
                printMusicLibraryEmpty();
            else{
                cocktailSort(Library,size);
                 printMusicLibraryTitle();
                printList(Library,size);
            }
           // printf("not ryt now");
        }
        else if (response == 'P') {
            // Print the music library.
            if(size==0)
                printMusicLibraryEmpty();
            else{
                printMusicLibraryTitle();
                printList(Library,size);
            }
            //   ADD STATEMENT(S) HERE

        }
        else if (response == 'Q') {
            //printf("\n");
            //printList(head);
            ; // do nothing, we'll catch this below
        }
        else {
            // do this if no command matched ...
            printf("\nInvalid command.\n");
        }
    } while (response != 'Q');
   
    return 0;
}

// Support Function Definitions

// Prompt the user for a string safely, without buffer overflow
void getStringFromUserInput(char s[], int maxStrLength) {
    int i = 0;
    char c;

    while (i < maxStrLength && (c = getchar()) != '\n')
      s[i++] = c;

    s[i] = '\0';
}

// Function to call when the user is trying to insert a song name 
// that is already in the personal music library.
void songNameDuplicate(char songName[])
{
    printf("\nA song with the name '%s' is already in the music library.\n"
           "No new song entered.\n", songName);
}

// Function to call when a song name was found in the personal music library.
void songNameFound(char songName[])
{
    printf("\nThe song name '%s' was found in the music library.\n",
           songName);
}

// Function to call when a song name was not found in the personal music library.
void songNameNotFound(char songName[])
{
    printf("\nThe song name '%s' was not found in the music library.\n",
           songName);
}

// Function to call when a song name that is to be deleted
// was found in the personal music library.
void songNameDeleted(char songName[])
{
    printf("\nDeleting a song with name '%s' from the music library.\n",
           songName);
}

// Function to call when printing an empty music library.
void printMusicLibraryEmpty(void)
{
    printf("\nThe music library is empty.\n");
}

// Function to call to print a title when the entire music library is printed.
void printMusicLibraryTitle(void)
{
    printf("\nMy Personal Music Library: \n");
}



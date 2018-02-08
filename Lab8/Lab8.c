//
// APS105-F15 Lab 8 Lab8.c
//
// This is a program written to maintain a personal music library, 
// using a linked list to hold the songs in the library.
//
// Author: Xinzhe Lin
// Student Number: 1003571075
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// A node in the linked list

// Each string in the node is declared as a character pointer variable,
// so they need to be dynamically allocated using the malloc() function,
// and deallocated using the free() function after use.

typedef struct node
{
    char *songName;
    char *artist;
    char *genre;
    struct node *link;
} Node;

// Declarations of linked list functions
//
// Declare your own linked list functions here.
//
// ADD YOUR STATEMENT(S) HERE

Node *newNode(char *song,char *art, char *gen, Node *link);
Node *insertIntoOrderedList(Node *head, char *song, char *art, char *gen); 
Node *search(Node *head, char *song);
void printList(Node *head);
Node *deleteFirstOccurrence(Node *head, char *song) ;
Node *deleteAllNodes(Node *head);


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


const int MAX_LENGTH = 1024;

int main(void) {
    // Declare the head of the linked list.
    Node *head = NULL;
    Node *n = head;
    //   ADD YOUR STATEMENT(S) HERE
    char songName[MAX_LENGTH+1];
    char artist[MAX_LENGTH+1];
    char genre[MAX_LENGTH+1];
    
    // Announce the start of the program
    printf("%s", "Personal Music Library.\n\n");
    printf("%s", "Commands are I (insert), D (delete), S (search by song name),\n"
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
                getStringFromUserInput(songName, MAX_LENGTH);
                
             printf("Artist: ");
                getStringFromUserInput(artist, MAX_LENGTH);
                
             printf("Genre: ");
                getStringFromUserInput(genre, MAX_LENGTH);
                
            n = search(head,songName);
            if(n != NULL)
                songNameDuplicate(songName);
            else{
                head = insertIntoOrderedList(head,songName,artist,genre);
            }
        }
        else if (response == 'D') {
            // Delete a song from the list.

            printf("\nEnter the name of the song to be deleted: ");
                getStringFromUserInput(songName, MAX_LENGTH);
            
                if(search(head,songName)!= NULL){
                    head = deleteFirstOccurrence(head,songName);
                    songNameDeleted(songName);
                }
                else
                    songNameNotFound(songName);
            //   ADD STATEMENT(S) HERE

        }
        else if (response == 'S') {
            // Search for a song by its name.
            
            printf("\nEnter the name of the song to search for: ");
            getStringFromUserInput(songName, MAX_LENGTH);
            
            
            n = search(head,songName);
            if(n != NULL){
                songNameFound(songName);
                printf("\n");
                printf("%s\n",n->songName);
                printf("%s\n",n->artist);
                printf("%s\n",n->genre);
            }
            else
                songNameNotFound(songName);
            //   ADD STATEMENT(S) HERE

        }
        else if (response == 'P') {
            // Print the music library.
            if(head==NULL)
                printMusicLibraryEmpty();
            else{
                
                printMusicLibraryTitle();
                printList(head);
            }
            //   ADD STATEMENT(S) HERE

        }
        else if (response == 'Q') {

            //printList(head);
            ; // do nothing, we'll catch this below
        }
        else {
            // do this if no command matched ...
            printf("\nInvalid command.\n");
        }
    } while (response != 'Q');
    head = deleteAllNodes(head);
            
    
    // Delete the entire linked list.
    //   ADD STATEMENT(S) HERE
    printMusicLibraryEmpty();
    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE

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


Node *newNode(char *song,char *art, char *gen, Node *link){
    Node *new;
    new = (Node *)malloc(sizeof(Node));
    
    new->songName = (char *)malloc(sizeof(char)*(strlen(song)+1));
    new->artist = (char *)malloc(sizeof(char)*(strlen(art)+1));
    new->genre = (char *)malloc(sizeof(char)*(strlen(gen)+1));
    
    if(new != NULL){
        strcpy(new->songName,song);
        strcpy(new->artist,art);
        strcpy(new->genre,gen);
        new -> link = link; 
    }
    
    return new;
}

//insert one node to the ordered list
Node *insertIntoOrderedList(Node *head, char *song, char *art, char *gen) {
    //int compare1 = strcmp(song, head->songName);                                                       ???????????????????????????????????? SEGMENTATION FAULT
    //special case: when the node is null
    if (head == NULL || strcmp(song, head->songName) < 0 )
     return newNode(song,art,gen,head); // a new head of the list

   Node *current = head;
   
   //int compare2 = strcmp(song, current -> link -> songName);
   while (current -> link != NULL && strcmp(song, current -> link -> songName) > 0)
     current = current -> link;

   current -> link = newNode(song, art, gen, current -> link);
   return head;
}

//search if theres any node thats the same as input
Node *search(Node *head, char *song){
    Node *current = head;
    bool found = false;
    while(current != NULL && found == false){
        if(strcmp(current->songName, song) == 0) found = true;
        else current = current->link;
    }
    return current;
}

//print the entire list
void printList(Node *head){
    Node *current = head;
    while(current != NULL){
        printf("\n");
        printf("%s\n%s\n%s\n", current ->songName, current -> artist, current-> genre);
        //printf("\n\n");
        current = current->link;
    }
}

// Deleting the first occurrence of a search key from a linked list
Node *deleteFirstOccurrence(Node *head, char *song) {
  if (head == NULL)
    return NULL;

  // If the first node is to be deleted
  if (strcmp(head->songName, song) == 0) {
     Node *secondNode = head -> link;
     free(head->artist);
     free(head->songName);
     free(head->genre);
     return secondNode;
  }

  bool found = false;
  Node *current = head;

  while (!found && current -> link != NULL) {
    if (strcmp(current -> link -> songName, song) == 0 )
      found = true;
    else
      current = current -> link;
  }

  // if there exists a node to be deleted
  if (current -> link != NULL)
  {
      Node *nodeToRemove = current -> link;
      current -> link = current -> link -> link;
     free(nodeToRemove->artist);
     free(nodeToRemove->songName);
     free(nodeToRemove->genre);
     
     free(nodeToRemove);
  }

  return head;
}

// Deleting all the nodes in the linked list
Node *deleteAllNodes(Node *head) {
  while (head != NULL) {
    Node *firstNode = head;
    songNameDeleted(head->songName);
     head = head -> link;
     free(firstNode->songName);
     free(firstNode->artist);
     free(firstNode->genre);
     
     free(firstNode);
     // Alternatively...

     // node * secondNode = head -> link;
     // free(head);
     // head = secondNode;
  }
  return NULL;
}
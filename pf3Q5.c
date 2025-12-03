#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

char **lines = NULL;   // dynamic array of lines
int maxLines = 0;      // number of lines currently stored
int memory = 0;        // currently allocated slots in 'lines'

// Ensures lines array has enough memory for 'neededMemory' lines
void AvailableMemory(int neededMemory){     // during functions insertLine and deleteLine this function helps with allocation
    if(memory >= neededMemory){             // so we do not have to repeat the code for allocation
        return;
    }

    char **tempMemory = realloc(lines, neededMemory * sizeof(char*));
    if(!tempMemory){
        perror("Memory allocation failed");
        exit(1);
    }
    lines = tempMemory;
    memory = neededMemory;
}

// Insert a line at 'index', shifting other lines to the right
void insertLine(int index, const char *text) {
    if(index < 0 || index > maxLines){     // check bounds
        printf("Your index is out of bound\n");
        return;
    }

    AvailableMemory(maxLines + 1);  // allocating memory in the array lines to store more lines of text

    if(index < maxLines)     // if we have to store at an index for example 2 when the max lines pointer is at 6 we need to shift 
        memmove(&lines[index + 1], &lines[index], (maxLines - index) * sizeof(char*));   // everything to the right to make space at that index

    lines[index] = malloc(strlen(text) + 1);   // allocating exact memory required (plus one for the terminator \0)
    if(lines[index] == NULL) {
        perror("Memory allocation has failed\n");   // error if index empty during allocation
        exit(1);
    }
    strcpy(lines[index], text);   // copy the text to the desired index in the string array lines

    maxLines++;  // update number of stored lines
}

// Delete a line at 'index', shift lines to the left, shrink memory
void deleteLine(int index){
    if(index < 0 || index >= maxLines){
        printf("Your index is out of bound\n");
        return;
    }
    free(lines[index]);   // freeing up the memory filled by the text at index specified by the user in the lines array

    if(index < maxLines - 1){    // moves everything to the left, if index is the same as maxLines-1 which means current line was deleted
        memmove(&lines[index], &lines[index + 1], (maxLines - index - 1) * sizeof(char*));    // which means no shifting required
    }

    maxLines--; 

    if(maxLines == 0){
        free(lines);  // frees up the space if maxLines are zero and initializes the array lines with null
        lines = NULL;
        memory = 0;
    } else {
        char **temp = realloc(lines, maxLines * sizeof(char*));  // shrinks the array of lines to just the amount occupied
        if(temp == NULL){
            perror("Memory shrinking failed\n");
            exit (1);
        }  
        lines = temp;
        memory = maxLines;
    }
}

// Print all stored lines
void PrintAll(){
    int i;
    if(maxLines == 0){
        printf("There are no lines to print\n");
        return;
    } else {
        for(i = 0; i < maxLines; i++){
            printf("%d) %s\n", i , lines[i]);
        }
    }
}

// Free all lines and the lines array
void FreeAll(){
    int i;
    if(maxLines == 0 || lines == NULL){
        printf("Nothing to free\n");
        return;
    }
    for(i = 0; i < maxLines; i++){
        free(lines[i]); // makes sure all the memory used is freed which ensures efficient use of space unlike the predeclared arrays
    }
    free(lines);
    lines = NULL;
    maxLines = 0; 
    memory = 0;
}

int main(){
    int choice;

    while(1){
        printf("\nMain Menu\n");
        printf("1-Inserting\n");
        printf("2-Deleting\n");
        printf("3-Displaying\n");
        printf("4-Freeing memory\n");
        printf("5-Exit\n");
        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1){  // input validation
            printf("Invalid input!\n");
            continue;
        }

        switch(choice){

        
            case 1: {
                printf("Enter your sentence: ");

                int lenght = 0, s;  // count of characters
                char *bufferMemory = malloc(1);  // dynamically initializes the memory 1 byte
                if(bufferMemory == NULL){
                    perror("Memory was not allocated properly\n");
                    exit(1);
                }

                getchar(); // reads one leftover newline character

                while((s = getchar()) != '\n' && s != EOF){   // reads until user presses enter
                    char *temp = realloc(bufferMemory, lenght + 2);  // dynamic memory allocated exact to store a character (+1 for null terminator)
                    if(temp == NULL){
                        perror("Memory was not reallocated properly");
                        free(bufferMemory);
                        exit(1);
                    }
                    bufferMemory = temp;   // these characters are then stored into the bufferMemory in the shape of a character array
                    bufferMemory[lenght] = (char)s;
                    lenght++;
                }

                bufferMemory[lenght] = '\0';   // adding a null terminator to stop reading the sentence

                insertLine(maxLines, bufferMemory);  // insertLine function called 
                free(bufferMemory);
                break;
            }


            case 2: {
                int index;
                printf("Enter the number of index to delete (Consider from 0): ");
                if(scanf("%d", &index) != 1){
                    printf("Invalid input!\n");
                   
                    break;
                }
                deleteLine(index);
                break;
            }

     
            case 3:
                PrintAll();
                break;

   
            case 4:
                FreeAll();
                printf("All memory freed.\n");
                break;
            case 5:
                FreeAll();
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice, try again.\n");
        }
    }
}


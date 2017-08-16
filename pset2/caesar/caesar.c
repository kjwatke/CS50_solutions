#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // Validate a positive int is passed in to the command line, quit program unsuccessfully if no args passed in.
    if (argc != 2)
    {
        printf("%s\n", "Insufficient arguments, you must pass in a positive int as the second arg");
        return 1;
    }
    else
    {
        // Convert 2nd command line arg to a integer.
        int key = atoi(argv[1]);
        printf("%d\n", key);
        
        // Promput user for text to cipher.
        printf("%s\n", "Enter the text to cypher: ");
        string txt = get_string();

        // Set the size of the text entered by the user.
        int strSize = strlen(txt);
        
        // determines the number of places to move through an ascii chart.
        int moveBy;
        
        printf("plaintext:   %s\n", txt);
        
        printf("%s", "ciphertext:  ");
        // Algorithm to cipher user text based on key provided. All non aplha chars will be left alone.
        for (int i = 0; i < strSize; i += 1)
        {

             // Current char is alphabetical.
             if (isalpha(txt[i]))
             {
                 // Handle lowercase cases.
                 if (islower(txt[i]))
                 {
                     moveBy = txt[i];
                     moveBy -= 97;
                     moveBy = (moveBy + key) % 26;
                     printf("%c", moveBy + 97);
                 }
                 
                 // Handle uppercase cases.
                 else if (isupper(txt[i]))
                 {
                     moveBy = txt[i];
                     moveBy -= 65;
                     moveBy = (moveBy + key) % 26;
                     printf("%c", moveBy + 65);
                 }
             }
             else
             {
                 printf("%c", txt[i]);
             }
        }
        
        printf("%s", "\n");
         
         return 0;   
    
    }
}
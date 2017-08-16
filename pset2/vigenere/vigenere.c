#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Exit program with error if number of command line args is not within: 1 <= args < 3.
    if (argc <= 1)
    {
        printf("%s\n", "You've entered an invalid number of commands or an invalid key. Rerun with correct args");
        return 1;
    }
    
    else
    {
        int keyLen = strlen(argv[1]);

        // Validate key is only alphabetical.
        for (int i = 0; i < keyLen; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("%s\n", "Your key was not made up of all alpahetical letters, please rerun with a valid key");
                return 1;
            }
        }

        
        printf("%s", "plaintext: ");
        
        string txt = get_string();
        int txtLen = strlen(txt);
        
        int keyCounter = 0;
        int key = 0;
        char cipheredCh;
        

        printf("%s: ", "ciphertext");
            
        for (int i = 0; i < txtLen; ++i)
        {
            // Handle user provided key having both lowercase and/or uppercase letters.
            if (islower(argv[1][keyCounter % keyLen]))
            {
                key = argv[1][keyCounter % keyLen] - 97;   
            }
            else
            {
                key = argv[1][keyCounter % keyLen] - 65;
            }
            
            // Current char IS a alphabetical letter, encrypt it.
            if (isalpha(txt[i]))
            {
                // Handle cases where ith letter of txt string is an uppercase letter.
                if (isupper(txt[i]))
                {
                    // Cipher formula based on Vigenere.
                    cipheredCh = txt[i] - 65;
                    cipheredCh = (cipheredCh + key) % 26;
                    
                    printf("%c", cipheredCh + 65);
                    keyCounter += 1;

                }
                
                // Handle cases where ith letter of txt string is a lowercase letter.
                else
                {
                    // Cipher formula based on Vigenere.
                    cipheredCh = txt[i] - 97;
                    cipheredCh = (cipheredCh + key) % 26;

                    printf("%c", cipheredCh + 97);
                    keyCounter += 1;
        
                }
            }
            
            // Current char IS NOT an alphabetical letter, print it out with ciphering.
            else
            {
                printf("%c", txt[i]);
            }
        }
        
        printf("%c", '\n');
        
        return 0;
    }
}
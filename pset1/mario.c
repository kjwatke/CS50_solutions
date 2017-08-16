#include <stdio.h>
#include <cs50.h>

int main(void) {
    // Store the height of the pyramid from the user.
    int h;
    
    // While the height from user is not 0 <= h <= 23, reprompt for a correct value.
    do {
        printf("Enter the height of your desired pyramid: ");
        h = get_int();
    } while(h < 0 || h > 23);
    
    // If the user enters a height of 0, no #'s should be printed.
    if (h == 0) {
        return 0;
    }
    
    // The outer loop is responsible for the printing of each row.
    for (int i = 0; i < h; i += 1)
    {
        // This inner loop is responsible for printing the spaces for each row.
        for (int j = 0; j < h - i - 1; j += 1)
        {
            printf(" ");
        }
        
        // This inner loop is responsible for printing the '#' character for each row.
        for (int k = 0; k < i + 2; k += 1)
        {
            printf("%c", '#');
        }
        
        printf("\n");
    }
    
    return 0;
}
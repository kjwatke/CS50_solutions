#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change = 0;
    int coinCount = 0;

    // Keep prompting the user for the change to evaluate until a non-negative value is obtained.
    do
    {
        printf("%s", "Give me some change: ");
        change = get_float();
    } while (change < 0);
    
    // Convert the number to a whole integer so we can work with everything in cents context.
    int changeAsInt = (int) round(change * 100);
    
    // Keep looking at changeAsInt until it reaches 0, each time we will figure out the largest possible coin to take out
    // and subtract that from the balance. This loop will also keep track each time a coin is used.
    do
    {
        if (changeAsInt >= 25)
        {
            coinCount += 1;
            changeAsInt -= 25;
        }
        
        else if (changeAsInt >= 10 && changeAsInt < 25)
        {
            coinCount += 1;
            changeAsInt -= 10;
        }
        
        else if (changeAsInt >= 5 && changeAsInt < 10)
        {
            coinCount += 1;
            changeAsInt -= 5;
        }
        
        else if (changeAsInt >= 1 && changeAsInt < 5)
        {
            coinCount += 1;
            changeAsInt -= 1;
        }
    } while (changeAsInt > 0);
    
    // Print out how many coins it took to get from user change to zero.
    printf("%i\n", coinCount);
    
    return 0;    
}
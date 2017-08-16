#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string name = get_string();
    string initials = "";
    
    int len = strlen(name);
    
    for (int i = 0; i < len; i += 1)
    {
        if (i == 0)
        {
            if (name[i] < 65 || name[i] > 90)
            {
                printf("%c", name[i] - 32);
            }
            else
            {
                printf("%c", name[i]);
            }
        }
        
        if (i > 0 && name[i - 1] == 32)
        {
            if (name[i] < 65 || name[i] > 90)
            {
                printf("%c", name[i] - 32);
            }
            else
            {
                printf("%c", name[i]);
            }
        }
    }
    
    printf("%s\n", initials);
    
    return 0;
}
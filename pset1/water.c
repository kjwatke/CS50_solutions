#include <stdio.h>
#include <cs50.h>

int main(void) {
    int mins;
    do {
        printf("Minutes: ");
        mins = get_int();
    } while (mins <= 0);
    
    int bottles = mins * 12;
    printf("Bottles: %d\n", bottles);

    return 0;
}
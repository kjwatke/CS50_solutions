/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // Generate a tile.
    int n = d * d - 1;
    
    // Initialize game board. Iterate over multi_d array and set each tile based on n.
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = n--;
        }
    }
    
    // Check for d is even case, if it is even, we need to switch 2 and 1 tile.
    if (d % 2 == 0)
    {
        int tmp = board[d - 1][d - 3];
        board[d - 1][d - 3] = board[d - 1][d - 2];  // 1
        board[d - 1][d - 2] = tmp; // 2
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // If we found a zero integer, replace it with an '_'.
            if (board[i][j] == 0)
            {
                printf("%2c ", '_');
                continue;
            }
            printf("%2i ", board[i][j]);
        }
        
        printf("%c", '\n');
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int row = 0, col = 0, tmp = 0;
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // Current element in array matches user tile choice, store the row and column location.
            if (board[i][j] == tile)
            {
                row = i;
                col = j;
                break;
            }
        }
    }
    
    // Series of checks to see if tile borders an empty spot and can be moved.
    // Return true if it can be moved and swap it with the blank, else return
    // false.
    if (board[row + 1][col] == 0 && row < d - 1)
    {
        tmp = board[row][col];
        board[row][col] = board[row + 1][col];
        board[row + 1][col] = tmp;
        return true;
    }
    else if (board[row - 1][col] == 0 && row > 0)
    {
        tmp = board[row][col];
        board[row][col] = board[row - 1][col];
        board[row - 1][col] = tmp;
        return true;
    }
    else if (board[row][col + 1] == 0 && col < d - 1)
    {
        tmp = board[row][col];
        board[row][col] = board[row][col + 1];
        board[row][col + 1] = tmp;
        return true;
    }
    else if (board[row][col - 1] == 0 && col > 0)
    {
        tmp = board[row][col];
        board[row][col] = board[row][col - 1];
        board[row][col - 1] = tmp;
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int checker = 1;
    bool status = true;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // If we get to the last element in the multi_d array, we skip the comparison, since it's an empty spot.
            if (i == d - 1 && j == d - 1)
            {
                continue;
            }
            // A winning board is in incrementing order, starting with 1, regardless of dimensions.
            // If we ever encounter an integer not in line with checker, we know it can't be in order.
            else if (board[i][j] != checker)
            {
                status = false;
            }
            checker++;
        }
    }
    return status;
}

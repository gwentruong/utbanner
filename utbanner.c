#include <stdio.h>
#include <string.h>

#define ROWS 5
#define SIZE 16

char ascii_art[16][ROWS][SIZE];

void split_string(char array[ROWS][SIZE], char *s);
void a(char array[ROWS][SIZE]);
void h(char array[ROWS][SIZE]);
void e(char array[ROWS][SIZE]);
void l(char array[ROWS][SIZE]);
void o(char array[ROWS][SIZE]);
void ascii(char letter, char ascii_art[ROWS][SIZE]);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("Usage: utbanner WORD\n");
        return 1;
    }

    char *str = argv[1];
    int   len = strlen(str);
    int   i, j;

    for (i = 0; i < len; i++)
    {
        // Return array of substrings of current letter
        ascii(str[i], ascii_art[i]);
    }

    // Print out the whole line ascii_art[i][j] in 3D array
    for (j = 0; j < ROWS; j++)
    {
        for (i = 0; i < len; i++)
            printf("%s", ascii_art[i][j]);
        printf("\n");
    }

    return 0;
}

// Split string into substrings and fill into array
void split_string(char array[ROWS][SIZE], char *s)
{
    int  j = 0;
    int  index = 0;
    char buf[SIZE];
    int  len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (s[i] != '\n')
        {
            buf[j] = s[i];
            j++;
        }
        else
        {
            buf[j] = '\0'; // End the string
            strcpy(array[index], buf); // Copy the substring to array
            index++;
            j = 0;
        }
    }
    buf[j] = '\0';
    strcpy(array[index], buf); // Copy the last substring to the array
}

// Create array of each letter
void a(char array[ROWS][SIZE])
{
    char *a = "  AAA   \n AAAAA  \nAA   AA \nAAAAAAA \nAA   AA \n";
    split_string(array, a);
}

void h(char array[ROWS][SIZE])
{
    char *h = "HH   HH \nHH   HH \nHHHHHHH \nHH   HH \nHH   HH \n";
    split_string(array, h);
}

void e(char array[ROWS][SIZE])
{
    char *e = "EEEEEEE \nEE      \nEEEEE   \nEE      \nEEEEEEE \n";
    split_string(array, e);
}

void l(char array[ROWS][SIZE])
{
    char *l = "LL      \nLL      \nLL      \nLL      \nLLLLLLL \n";
    split_string(array, l);
}

void o(char array[ROWS][SIZE])
{
    char *o = " OOOOO  \nOO   OO \nOO   OO \nOO   OO \n OOOO0  \n";
    split_string(array, o);
}

// Create array ASCII base on the letter
void ascii(char letter, char letter_art[ROWS][SIZE])
{
    char buf[ROWS][SIZE];

    switch (letter)
    {
        case 'h':
        case 'H':
            h(buf);
            break;
        case 'e':
        case 'E':
            e(buf);
            break;
        case 'l':
        case 'L':
            l(buf);
            break;
        case 'o':
        case 'O':
            o(buf);
            break;
        case 'a':
        case 'A':
            a(buf);
            break;
        default:
            break;
    }

    // Copy each substrings to each rowumn/ element of struct array
    for (int i = 0; i < ROWS; i++)
        strcpy(letter_art[i], buf[i]);
}

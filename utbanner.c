#include <stdio.h>
#include <string.h>

#define ROWS 5
#define SIZE 16

char ascii_art[16][ROWS][SIZE];

void split_string(char array[ROWS][SIZE], char *s);
void read_font(char letter, char letter_art[ROWS][SIZE]);

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
        read_font(str[i], ascii_art[i]);
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

// Read each character from font files list
void read_font(char letter, char letter_art[ROWS][SIZE])
{
    FILE *fp;
    char  path[32];
    char  buf[128];
    int   size;

    sprintf(path, "./fonts/letters/%c", letter);

    fp = fopen(path, "r");

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    fread(buf, 1, size, fp);
    buf[size] = '\0';
    split_string(letter_art, buf);

    fclose(fp);
}

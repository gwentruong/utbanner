#include <stdio.h>
#include <string.h>

#define ROWS     22
#define SIZE     64
#define FONT_NUM 2

char ascii_art[16][ROWS][SIZE];
char font_list[FONT_NUM][16]    = {"letters", "alpha"};
int  font_row_length[FONT_NUM]  = {5, 22};

int  get_font_index(char *font_style);
int  alphabet(char c);
void split_string(char array[ROWS][SIZE], char *s);
void read_font(char letter, char *font_style, char letter_art[ROWS][SIZE]);


int main(int argc, char **argv)
{
    if (argc <= 2)
    {
        printf("Usage: utbanner <font_style> <WORD>\n"
                "Choost font_style:\n"
                "letters\nalpha\n");
        return 1;
    }

    char *style = argv[1]; // Take the 1st argument for font style
    int font_index = get_font_index(style);
    if (font_index == -1)
    {
        printf("Invalid font_style: choose 'letters' or 'alpha'\n");
        return 1;
    }

    int rows = font_row_length[font_index];

    for (int k = 2; k < argc; k++)
    {
        char *str = argv[k];
        int   len = strlen(str);

        for (int i = 0; i < len; i++)
        {
            if (alphabet(str[i]))
            {
                // Return array of substrings of current letter
                read_font(str[i], style, ascii_art[i]);
            }
        }
        // Print out the whole line ascii_art[i][j] in 3D array
        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < len; i++)
                printf("%s", ascii_art[i][j]);
            printf("\n");
        }
    }
    return 0;
}

// Checking for font style
int get_font_index(char *font_style)
{
    int invalid = 0;
    int font_index;
    for (int i = 0; i < FONT_NUM; i++)
    {
        int check = strcmp(font_style, font_list[i]);
        if (check) // Check != 0
            invalid++;
        else
            font_index = i;
    }

    if (invalid == FONT_NUM)
        return -1;
    else
        return font_index;
}

// Check if the letter is alphabetical
int alphabet(char c)
{
    if ((c > 64 && c < 91) || (c > 96 && c < 123))
        return 1;
    else
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
void read_font(char letter, char *font_style, char letter_art[ROWS][SIZE])
{
    FILE *fp;
    char  path[32];
    char  buf[1024];
    int   size;

    sprintf(path, "./fonts/%s/%c", font_style, letter);

    fp = fopen(path, "r");

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    fread(buf, 1, size, fp);
    buf[size] = '\0';
    split_string(letter_art, buf);

    fclose(fp);
}

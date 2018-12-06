#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS     22
#define SIZE     64
#define FONT_NUM 2

char ascii_art[16][ROWS][SIZE];
char font_list[FONT_NUM][16]    = {"letters", "alpha"};
int  font_row_length[FONT_NUM]  = {5, 22};

void menu(int n);
int  get_font_index(char *font_style);
int  alphabet(char c);
void split_string(char array[ROWS][SIZE], char *s);
void read_font(char letter, char *font_style, char letter_art[ROWS][SIZE]);

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        menu(0); // Return help menu
        return 1;
    }

    char *option = argv[1];
    char *font_style;
    int font_index;
    int rows;
    int index;

    if (strcmp(option, "--help") == 0)
    {
        menu(0);
        return 0;
    }
    else if (strcmp(option, "--version") == 0)
    {
        menu(1);
        return 0;
    }
    else if (strcmp(option, "-f") == 0 || strcmp(option, "-i") == 0)
    {
        if (argc < 4)
        {
            printf("Error, check utbanner --help for valid commands\n");
            return 1;
        }

        index = 3;
        if (strcmp(option, "-f") == 0)
        {
            char *font = argv[2];
            font_index = get_font_index(font);
            if (font_index == -1)
            {
                rows = font_row_length[0];
                font_style = font_list[0];
            }
            else
            {
                rows = font_row_length[font_index];
                font_style = font;
            }
        }
        else // option == "-i"
        {
            font_index = atoi(argv[2]); // If error, return index 0
            font_style = font_list[font_index];
            rows = font_row_length[font_index];
        }
    }
    else
    {
        rows = font_row_length[0];
        font_style = font_list[0];
        index = 1;
    }

    for (int k = index; k < argc; k++)
    {
        char *str = argv[k];
        int   len = strlen(str);

        for (int i = 0; i < len; i++)
        {
            if (alphabet(str[i]))
            {
                // Return array of substrings of current letter
                read_font(str[i], font_style, ascii_art[i]);
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

// Help menu
void menu(int n)
{
    if (n == 0) // Print help menu
    {
        printf("Usage: utbanner [options] [font] [word]\n"
               "Default font: 'letters'\n"
               "Fonts index:\n"
               "0\tletters\n"
               "1\talpha\n"
               "Options:\n"
               "-i\tChoose font by font index\n"
               "-f\tChoose font by font name\n"
               "--help\n\tPrint help menu\n"
               "--version\n\tPrint the lastest version\n");
    }
    else // Print latest version
    {
        printf("utbanner v0.1\n"
               "Copyright (C) 2018 Uyen Truong\n"
               "Contact me if found bugs via haiuyentruong(at)gmail(dot)com\n");
    }

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

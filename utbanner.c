#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS     22
#define SIZE     64
#define FONT_NUM 2

char ascii_art[16][ROWS][SIZE];
char font_list[FONT_NUM][16]    = {"letters", "alpha"};
int  font_row_length[FONT_NUM]  = {5, 22};

void help_menu(int n);
int  get_font_index(char *font_style);
int  is_alpha(char c);
void split_string(char array[ROWS][SIZE], char *s);
void read_font(char letter, char *font_style, char letter_art[ROWS][SIZE]);

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        help_menu(0); // Invalid command, return help menu
        return 1;
    }

    char *option = argv[1];
    char *font_style;
    int   font_index = 0;
    int   rows;
    int   word_index;

    if (strcmp(option, "--help") == 0)
    {
        help_menu(0); // Show help menu
        return 0;
    }
    else if (strcmp(option, "--version") == 0)
    {
        help_menu(1); // Show version
        return 0;
    }
    else if (strcmp(option, "-f") == 0 || strcmp(option, "-i") == 0)
    {
        if (argc < 4) // Invalid command, return help menu
        {
            help_menu(0);
            return 1;
        }

        if (strcmp(option, "-f") == 0)
        {
            char *font = argv[2];
            font_index = get_font_index(font);
        }
        else // option == "-i"
        {
            font_index = atoi(argv[2]); // If error, return index 0
            if (font_index < 0 || font_index >= FONT_NUM)
                font_index = 0;
        }

        word_index = 3;
    }
    else // Default style
        word_index = 1;

    rows       = font_row_length[font_index];
    font_style = font_list[font_index];

    for (int k = word_index; k < argc; k++)
    {
        char *str = argv[k];
        int   len = strlen(str);

        for (int i = 0; i < len; i++)
        {
            if (is_alpha(str[i]))
                read_font(str[i], font_style, ascii_art[i]);
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
void help_menu(int n)
{
    if (n == 0) // Print help menu
    {
        printf("Usage: utbanner [options] [font] [word]\n"
               "Options:\n"
               "-i\tChoose font by font index\n"
               "-f\tChoose font by font name\n"
               "--help\n\tPrint help menu\n"
               "--version\n\tPrint the lastest version\n"
               "\n"
               "  index\tfont\n"
               "* 0\tletters (Default)\n"
               "* 1\talpha\n");
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
    for (int i = 0; i < FONT_NUM; i++)
    {
        if (strcmp(font_style, font_list[i]) == 0)
            return i;
    }

    return 0;
}

// Check if the letter is is_alphaical
int is_alpha(char c)
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

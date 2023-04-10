/*
    Nuray Bayrakdar 190101054
    System Progromming Assignment 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void clear_input_buffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void clear_console()
{
    system("cls");
}
int main(int arg, char *argv[])
{

    char *filename = argv[1];
    int lineNum = atoi(argv[2]);

    if (lineNum <= 0)
    {
        printf("Usage : ./moreOrLess dosya_adi satir_sayisi\n");
        return 0;
    }

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf(" %s dosyasi bulunamadi.\n", filename);
        return 0;
    }

    char line[256];
    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL)
    {
        i++;
    }

    if (lineNum > i)
    {
        printf("satir_sayisi mevcut satir sayisindan buyuk.\n");
        return 0;
    }

    fseek(file, 0, SEEK_SET);
    char ch = ' ';
    int current_line = 0;
    int top_line = 0;
    int bottom_line = lineNum - 1;
    int arrow_up_pressed = 0;
    int arrow_down_pressed = 0;
    while (ch != 'q')
    {
        clear_console();
        printf("Press 'q' to quit.\n");
        printf("Press Enter to clear and show next line.\n");
        printf("Press ESC to clear console and show %d lines from file.\n", lineNum);
        printf("Press up arrow to show previous line.\n");
        printf("Press down arrow to show next line.\n");
        printf("---------------------------------------------\n");

        int line_count = 0;
        while (fgets(line, sizeof(line), file) != NULL && line_count < bottom_line + 1)
        {
            if (line_count >= top_line)
            {
                printf("%s", line);
            }
            line_count++;
        }

        if (current_line == 0)
        {
            printf(">");
        }
        else
        {
            printf(" ");
        }

        ch = getchar();

        switch (ch)
        {
        case '\r':
            clear_input_buffer();
            top_line++;
            bottom_line++;
            current_line++;
            break;
        
        default:
            arrow_up_pressed = 0;
            arrow_down_pressed = 0;
            break;
        }

        if (top_line < 0)
        {
            top_line = 0;
        }

        if (bottom_line >= i)
        {
            bottom_line = i - 1;
        }
    }
    fclose(file);
    return 0;
}
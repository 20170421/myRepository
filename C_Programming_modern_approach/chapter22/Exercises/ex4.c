#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;
    char arr[100] = { 0, };
    char *chs;
    int ch_cnt = 0, word_cnt = 0, line_cnt = 0;

    if (argc < 2)
    {
        fprintf(stderr, "usager: ex4.exe filename1\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "file open error: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        if (isprint(ch))
            ch_cnt++;
        if (ch == '\n')
            line_cnt++;
    }
    line_cnt++;
    rewind(fp);
    while (fscanf(fp, "%s", chs) == 1)
    {
        word_cnt++;
    }
    printf("The number of character is %d\n", ch_cnt);
    printf("The number of words is %d\n", word_cnt);
    printf("The number of lines is %d\n", line_cnt);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 
    $ compress_file filename1
*/

int main(int argc, char *argv[])
{
    const char *ext = ".rle";

    FILE *fp, *dest_fp;
    char pre_sym, sym;
    int word_cnt = 0;

    if (argc < 2)
    {
        fprintf(stderr, "usage: ex7_a filename\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "file open error\n");
        exit(EXIT_FAILURE);
    }
    char *dest_filename = strncat(argv[1], ext, sizeof(ext));
    if ((dest_fp = fopen(dest_filename, "wb")) == NULL)
    {
        fprintf(stderr, "dest_file open error\n");
        exit(EXIT_FAILURE);
    }

    pre_sym = 0;
    word_cnt = 0;
    while ((sym = fgetc(fp)) != EOF)
    {
        if (pre_sym == 0) // 맨 처음 시작시
        {
            pre_sym = sym;
            word_cnt++;
            continue;
        }
        if (sym == pre_sym)
            word_cnt++;
        else
        {
            if (word_cnt == 0)
                word_cnt++;
            fputc(word_cnt, dest_fp);
            fputc(pre_sym, dest_fp);
            pre_sym = sym;
            word_cnt = 1;
        }
    }
    fputc(word_cnt, dest_fp); // 마지막 케이스
    fputc(pre_sym, dest_fp);

    fclose(fp);
    fclose(dest_fp);
    return 0;
}
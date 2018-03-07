#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int is_fail = 0;

    if (argc < 2)
    {
        printf("usage: canopen filename1 filename2 ...\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            printf("%s can't be opened\n", argv[i]);
            is_fail = 1;
            continue;
        }
        printf("%s can be opened\n", argv[i]);
    }

    fclose(fp);
    if (is_fail)
        exit(EXIT_FAILURE);
    else
        return EXIT_SUCCESS;
}
#include <stdio.h>
#include <string.h>

char* my_fgets(char* restrict s, int n, FILE* restrict stream);
int my_fputs(char const* restrict s, FILE* restrict stream);

int main(void)
{
    FILE *fp, *dest;
    char arr[100] = { 0, };

    if ((fp = fopen("ab.dat", "r+")) == NULL)
    {
        fprintf(stderr, "==> Error occurred in fopen()\n");
    }
    if ((dest = fopen("ba.dat", "w+")) == NULL)
    {
        fprintf(stderr, "==> Error occurred in fopen()\n");
    }

    if (my_fgets(arr, sizeof(arr), fp) == NULL)
        fprintf(stderr, "==> Error occurred\n");
    
    printf("%s\n", arr);

    my_fputs(arr, dest);

    return 0;
}

// It is like fputs()
int my_fputs(char const* restrict s, FILE* restrict stream)
{
    FILE* fp = stream;
    char ch = 0;
    int word_cnt = 0;

    word_cnt = fprintf(fp, "%s", s);

    return word_cnt;
}

// It is like fgets()
char* my_fgets(char* restrict s, int n, FILE* restrict stream)
{
    FILE* fp = stream;
    char* arr = s;
    char ch;
    int i;

    for (i = 0; i < n; i++)
    {
        ch = getc(fp);
            
        if (feof(fp) || ch == '\n')
            break;
        arr = strncat(arr, &ch, 1);

        if (fp != NULL && ferror(fp))
            return NULL;

    }
    
    fclose(fp);
    return arr;
}
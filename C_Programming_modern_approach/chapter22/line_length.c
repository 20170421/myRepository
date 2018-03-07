#include <stdio.h>
#include <stdlib.h>

int line_lengths(const char *filename, int n);

int main(void)
{
  const char *filename = "ab.dat";
  int length_of_line = 0;

  length_of_line = line_lengths(filename, 1);
  printf("length of line 1 is %d\n", length_of_line);

  return 0;
}

int line_lengths(const char *filename, int n)
{
  FILE *fp;
  int ch;
  int i = 0;
  int word_count = 0;

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Error in fopen()\n");
    exit(EXIT_FAILURE);
  }

  for (i = 1; i < n; ) {
    if ((ch = fgetc(fp)) == EOF)
      return -1; // not enough line
    if (ch == '\n') {
      i++;
    }
  }
  
  while ((ch = fgetc(fp)) != '\n') {
    printf("%c", ch);
    word_count++;
  }
  printf("\n");

  fclose(fp);
  return word_count;
}

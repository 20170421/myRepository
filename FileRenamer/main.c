#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "files.h"

/*
    ���丮���� ����Ž�� �� �̸� �缳��
*/
int main(void)
{
    bool quit = false;
    char *current_path;
    int selected;

    while (!quit)
    {
        printf("[[ 0: exit 1: show files ]]\n> ");
        selected = getchar() - '0';
        switch (selected)
        {
            case 0:
                quit = true;
                break;
            case 1:
                printf("Enter the path: ");
                scanf("%s", current_path);
                print_files(current_path);
                break;
            default:
                printf("Invalid selection\n");
                break;
        }
    }

    return 0;
}

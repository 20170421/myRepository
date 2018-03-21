void print_files(char *file_path)
{
    HANDLE hFind;
    WIN32_FIND_DATA FindData;
    const char *ext = "\\*";

    hFind = FindFirstFile(strcat(file_path, ext), &FindData);
    while (FindNextFile(hFind, &FindData))
    {
        printf("%20.17s\t", FindData.cFileName);
        printf("%20d\n", FindData.nFileSizeLow);
    }
    FindClose(hFind);
}
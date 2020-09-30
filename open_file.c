#include "funciones.h"

FILE* OpenFile(const char *name_file, const char *open_mode)
{
    FILE *pFile=NULL;

    if((pFile = fopen(name_file , open_mode)) == NULL)
    {
        exit(EXIT_FAILURE);
    }

    return pFile;
}

int recor_quantity(FILE *pFile)
{
    fseek(pFile, 0, SEEK_END);
    long ult = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);
    long result = ult / sizeof(STR_USER);

    return result;
}

void file_remove(const char *name_file)
{
        remove(name_file);
}
void file_rename(const char *file_rename, const char *file_name)
{
    rename(file_rename, file_name);
}
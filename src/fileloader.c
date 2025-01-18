#include "fileloader.h"

struct FILE_CONTENT read_file(char *path)
{
    struct FILE_CONTENT fc;
    fc.return_code = NOT_ERRORS;
    FILE *fPtr = fopen(path, "rb");
    if (fPtr == NULL)
    {
        fc.return_code = FILE_NOT_OPEN;
        return fc;
    }
    if (fseek(fPtr, 0, SEEK_END) != 0)
    {
        fclose(fPtr);
        fc.return_code = FSEEK_ERROR;
        return fc;
    }
    fc.file_size = ftell(fPtr);
    rewind(fPtr);
    if (fc.file_size == 1L)
    {
        fclose(fPtr);
        fc.return_code = GET_FILE_SIZE_ERROR;
        return fc;
    }
    fc.contentPtr = malloc(fc.file_size);
    if (fc.contentPtr == NULL)
    {
        fclose(fPtr);
        fc.return_code = MEMORY_NOT_ALLOC;
        return fc;
    }
    int i;
    for (i = 0; i < fc.file_size; i++)
    {
        *(fc.contentPtr + i) = getc(fPtr);
    }
    *(fc.contentPtr + fc.file_size) = '\0';
    if (fclose(fPtr) != 0)
    {
        fc.return_code = FILE_NOT_CLOSED;
        return fc;
    }
    return fc;
}
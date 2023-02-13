/* File: File.c
**
** Description: File's methods definition
**
** 2023, February 13
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "File.h"

static char *File_readLine(FileClass *this)
{
    char *line = NULL;
    size_t size = 0;
    ssize_t len = 0;

    if ((len = getline(&line, &size, this->_fstream)) == -1)
        raise("Can't read line.");

    return (line);
}

static char *File_read(FileClass *this)
{
    char *content = malloc(sizeof(char) * (this->_size + 1));

    if (!content)
        raise("Can't malloc.");

    memset(content, 0, this->_size + 1);
    if (read(this->_fd, content, this->_size) == -1)
        raise("Can't read file.");

    return (content);
}

static void File_fopen(FileClass *this)
{
    this->_fstream = fopen(this->_path, "r");
    if (this->_fstream == NULL)
        raise("Can't open file.");
}

static void File_open(FileClass *this)
{
    this->_fd = open(this->_path, O_RDONLY);
    if (this->_fd == -1)
        raise("Can't open file.");

    // Get file size
    struct stat info;
    this->_size = info.st_size;
}

static void File_ctor(FileClass *this, va_list *args)
{
    // Initialize internal resources

    this->_path = va_arg(*args, char *);

    printf("File()\n");
}

static void File_dtor(FileClass *this)
{
    // Release internal resources
    if (this->_fstream != NULL)
        fclose(this->_fstream);
    if (this->_fd != -1)
        close(this->_fd);

    printf("~File()\n");
}

static const FileClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FileClass),
        .__name__ = "File",
        .__ctor__ = (ctor_t)&File_ctor,
        .__dtor__ = (dtor_t)&File_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._path = NULL,
    ._size = -1,
    ._fstream = NULL,
    ._fd = -1,
    /* Methods definitions */
    .__read__ = &File_read
};

const Class *File = (const Class *)&_description;
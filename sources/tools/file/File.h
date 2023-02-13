/* File: file.h
**
** Description: File's class definition
**
** 2023, February 13
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef FILE_H_
    #define FILE_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <fcntl.h>
    #include <unistd.h>

    #include "object.h"
    #include "raise.h"

    typedef struct s_FileClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        char*           _path;
        long            _size;

        int             _fd;
        FILE*           _fstream;

        /* Methods definitions*/
        void    (*__open__)(struct s_FileClass*);
        void    (*__fopen__)(struct s_FileClass*);
        char*   (*__read__)(struct s_FileClass*);
        char*   (*__readLine__)(struct s_FileClass*);
    } FileClass;

    extern const Class *File;

    #define readFile(f)     ((FileClass*)f)->__read__(f)
    #define readLine(f)     ((FileClass*)f)->__readLine__(f)

#endif /* !FILE_H_ */
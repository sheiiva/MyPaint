/*
** Description:
** Array Class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef ARRAY_H
    # define ARRAY_H

    #include "container.h"

    typedef struct
    {
        Container   base;
        Class       *_type;
        size_t      _size;
        Object      **_tab;
    } ArrayClass;

    typedef struct {
        Iterator    base;
        ArrayClass  *_array;
        size_t      _idx;
    } ArrayIteratorClass;

    extern const Class *Array;

#endif
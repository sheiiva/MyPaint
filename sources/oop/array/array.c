/*
** Description:
** Array Class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include <stdlib.h>
#include <stdarg.h>

#include "new.h"
#include "raise.h"

#include "array.h"

static void ArrayIterator_ctor(ArrayIteratorClass *this, va_list* args)
{
    this->_array = va_arg(*args, ArrayClass*);
    this->_idx = va_arg(*args, int);
}

static void ArrayIterator_dtor(__UNUSED__ ArrayIteratorClass *this)
{
}

static bool ArrayIterator_eq(ArrayIteratorClass *this, ArrayIteratorClass* other)
{
    return (this->_idx == other->_idx);
}

static bool ArrayIterator_gt(ArrayIteratorClass *this, ArrayIteratorClass* other)
{
    return (this->_idx > other->_idx);
}

static bool ArrayIterator_lt(ArrayIteratorClass *this, ArrayIteratorClass* other)
{
    return (this->_idx < other->_idx);
}

static void ArrayIterator_incr(ArrayIteratorClass *this)
{
    this->_idx += 1;
}

static Object *ArrayIterator_getval(ArrayIteratorClass *this)
{
    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    return (this->_array->_tab[this->_idx]);
}

static void ArrayIterator_setval(ArrayIteratorClass *this, ...)
{
    va_list ap;

    va_start(ap, this);
    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    delete(this->_array->_tab[this->_idx]);
    this->_array->_tab[this->_idx] = va_new(this->_array->_type, &ap);
    va_end(ap);
}

static const ArrayIteratorClass ArrayIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ArrayIteratorClass),
            .__name__ = "ArrayIterator",
            .__ctor__ = (ctor_t)&ArrayIterator_ctor,
            .__dtor__ = (dtor_t)&ArrayIterator_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ArrayIterator_eq,
            .__gt__ = (binary_comparator_t)&ArrayIterator_gt,
            .__lt__ = (binary_comparator_t)&ArrayIterator_lt,
        },
        .__incr__ = (incr_t)&ArrayIterator_incr,
        .__getval__ = (getval_t)&ArrayIterator_getval,
        .__setval__ = (setval_t)&ArrayIterator_setval,
    },
    ._array = NULL,
    ._idx = 0
};

static const Class  *ArrayIterator = (const Class *)&ArrayIteratorDescr;

static void Array_ctor(ArrayClass *this, va_list* args)
{
    unsigned int    i;

    this->_size = va_arg(*args, size_t);
    this->_type = va_arg(*args, Class*);
    this->_tab = calloc(this->_size, sizeof(Object*));
    if (this->_tab == NULL)
        raise("Out of memory");
    for (i = 0; i < this->_size; i++) {
        this->_tab[i] = va_new(this->_type, args);
    }
}

static void Array_dtor(ArrayClass *this)
{
    for (unsigned int i = 0; i < this->_size; i++)
        delete(this->_tab[i]);
    free(this->_tab);
}

static size_t Array_len(ArrayClass *this)
{
    return (this->_size);
}

static Iterator *Array_begin(ArrayClass *this)
{
    return (new(ArrayIterator, this, 0));
}

static Iterator *Array_end(ArrayClass *this)
{
    return (new(ArrayIterator, this, this->_size));
}

static Object *Array_getitem(ArrayClass *this, ...)
{
    va_list ap;
    size_t  idx = 0;

    va_start(ap, this);
    idx = va_arg(ap, size_t);
    if (idx >= this->_size)
        raise("Out of range");
    va_end(ap);
    return (this->_tab[idx]);
}

static void  Array_setitem(ArrayClass *this, ...)
{
    va_list ap;
    size_t  idx = 0;

    va_start(ap, this);
    idx = va_arg(ap, size_t);
    if (idx >= this->_size)
        raise("Out of range");
    delete(this->_tab[idx]);
    this->_tab[idx] = va_new(va_arg(ap, Class*), &ap);
    va_end(ap);
}

static const ArrayClass _description = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ArrayClass),
            .__name__ = "Array",
            .__ctor__ = (ctor_t)&Array_ctor,
            .__dtor__ = (dtor_t)&Array_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&Array_len,
        .__begin__ = (iter_t)&Array_begin,
        .__end__ = (iter_t)&Array_end,
        .__getitem__ = (getitem_t)&Array_getitem,
        .__setitem__ = (setitem_t)&Array_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

const Class* Array = (const Class *) &_description;

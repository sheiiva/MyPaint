/*
** Description:
** Main Function
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "raise.h"
#include "new.h"
#include "object.h"

Object *new(const Class *class, ...)
{
    va_list ap;
    Object  *object;

    va_start(ap, class);
    object = va_new(class, &ap);
    va_end(ap);
    return (object);
}

Object *va_new(const Class *class, va_list *ap)
{
    Class *object;

    if (class == NULL || class->__size__ < sizeof(*class))
        raise("invalid class");
    object = malloc(class->__size__);
    if (object == NULL)
        raise("malloc failed");
    memcpy(object, class, class->__size__);
    if (object->__ctor__ != NULL)
        object->__ctor__(object, ap);
    return (object);
}

void delete(Object *ptr)
{
    Class *object = (Class *)ptr;

    if (object != NULL && object->__dtor__ != NULL)
        object->__dtor__(object);
    free(object);
}

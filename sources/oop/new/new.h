/*
** Description:
** Object Class NEW and DELETE Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef NEW_H_
    # define NEW_H_

    # include <stdarg.h>
    # include "object.h"

    Object* new(const Class *class, ...);
    Object* va_new(const Class *class, va_list* ap);
    void    delete(Object *ptr);

#endif /* !NEW_H_ */
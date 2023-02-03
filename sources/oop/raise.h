/*
** Description:
** Raise function definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef RAISE_H_
    # define RAISE_H_

    # include <stdio.h>
    # include <stdlib.h>

    # define raise(msg)                                             \
    do {                                                            \
        fprintf(stderr, "%s: %u: %s\n", __FILE__, __LINE__, msg);   \
        abort();                                                    \
    } while (0)

#endif /* !RAISE_H_ */
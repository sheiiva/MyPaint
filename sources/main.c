/* File: main.c
**
** Entry point of the program
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "new.h"
#include "System.h"

void prout(__UNUSED__ SystemClass *system)
{
    printf("prout\n");
}

int main(void)
{
    Object *system = new(System, &prout);

    run(system);
    delete(system);
    return (0);
}
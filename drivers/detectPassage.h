#ifndef DETECTPASSAGE_H
#define DETECTPASSAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>


extern int pinUltrason;

//detecte le passage d'une personne
int detectPassage(void);

#endif /*DETECTPASSAGE_H */

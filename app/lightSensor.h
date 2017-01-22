#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "grovepi.h"

extern int pinLight;

// Fonction qui détermine si il faut allumer la lumière ou pas
int isLight(void);


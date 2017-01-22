//Fichier pour détecter le passage d'une personne au niveau de l'ultrason

#include "detectPassage.h"

//Compilation : gcc grovepi_ultrasonic.c grovepi.c -Wall -o grovepi_ultrasonic
//Execution : sudo ./grovepi_ultrasonic

#define us_cmd 7

int pinUltrason = 4; // Capteur branché sur le port D4 (digital 4)

int detectPassage(){
	int data;
	write_block(us_cmd, pinUltrason, 0, 0);
	read_byte();
	read_block();
	data=r_buff[1]* + r_buff[2];
	if (data <= 100) // distance à mettre en fonction de la pièce dans laquelle se trouve la raspberry
	  return 1;

	else
	  return 0;
	
}

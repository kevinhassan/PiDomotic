// main.c

#include "grovepi.h"
#include "lightSensor.h"
#include "detectObstacle.h"
#include "detectPresence.py"

//Compilation : gcc grovepi_ultrasonic.c grovepi.c -Wall -o grovepi_ultrasonic
//Execution : sudo ./grovepi_ultrasonic

#define us_cmd 7

int main(void)
{
	//Exit on failure to start communications with the GrovePi
	if (init()==-1)
		exit(1);

	//TODO: faire la prise de la background
	while (1){ // On fait tourner le programme en continue
	  	if (detectPassage()){
			if (lumiereEteinte())
			  allumerLumiere();
			
			else{
			  if (detectPersonne(background)){
			    eteindreLumiere();
			  }
		pi_sleep(100); // attend 1 seconde
		}
	}
   	return 1;
}

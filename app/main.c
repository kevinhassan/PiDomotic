// main.c

#include "grovepi.h"
#include "lightSensor.h"
#include "detectObstacle.h"

//Compilation : gcc grovepi_ultrasonic.c grovepi.c -Wall -o grovepi_ultrasonic
//Execution : sudo ./grovepi_ultrasonic

#define us_cmd 7

int main(void)
{
	//Exit on failure to start communications with the GrovePi
	if (init()==-1)
		exit(1);

	system("raspistill -w 1024 -h 768 -o background.jpg");
	while (1){ // On fait tourner le programme en continue
	  	if (detectPassage()){
			if (lumiereEteinte())
				system("yee --ip=192.168.43.236 toggle");  
			
			else{
			  if (detectPersonne(background)){
			  	system("yee --ip=192.168.43.236 toggle");
			  }
		pi_sleep(100); // attend 1 seconde
		}
	}
   	return 1;
}

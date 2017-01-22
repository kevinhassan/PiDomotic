//Fichier pour utiliser la sensibilisation de la lumière

#include "lightSensor.h"

//Compilation : gcc grovepi_ultrasonic.c grovepi.c -Wall -o grovepi_ultrasonic
//Execution : sudo ./grovepi_ultrasonic

#define us_cmd 7

	const int pinLight= A0; // détecteur de lumière en A0

	int isLight(){
	  return (analogRead(pinLight)>50); // quand le capteur a une valeur de 51 ou plus on considère que la pièce est allumée ou n'a pas besoin d'être allumé
	}

/*
C'est pour faire les tests après 
 int main(){
	while(true){
	  if((isLight()){
	    printf("%d",analogRead(pinLight));
	  }
	pi_sleep(500); // attend 500 ms
	}

	return 1;
}
*/		

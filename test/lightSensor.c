//GrovePi Example for using the digital write command

#include "grovepi.h"

//Compilation : gcc grovepi_ultrasonic.c grovepi.c -Wall -o grovepi_ultrasonic
//Execution : sudo ./grovepi_ultrasonic

#define us_cmd 7

	const int pinLight= A0; // détecteur de lumière en A0

	bool isLight(){
	  return (analogRead(pinLight)>50); // quand la lumière est inférieure ou égale 50 ça veut dire que la lumière est éteint
	}

int main(){
	while(true){
	  if((isLight()){
	    printf("%d",analogRead(pinLight));
	  }
	pi_sleep(500); // attend 500 ms
	}

	return 1;
}		

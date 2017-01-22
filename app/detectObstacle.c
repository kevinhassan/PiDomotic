//GrovePi Example for using the digital write command

#include "grovepi.h"

//Compilation : gcc grovepi_ultrasonic.c grovepi.c -Wall -o grovepi_ultrasonic
//Execution : sudo ./grovepi_ultrasonic

#define us_cmd 7

int main(void)
{
	//Exit on failure to start communications with the GrovePi
	if(init()==-1)
		exit(1);

	int pinUltrason = 4; // Capteur branché sur le port D4 (digital 4)
	int data;
	while(1) // boucle infinie
	{
	  write_block(us_cmd, pinUltrason, 0, 0);
	  pi_sleep(200);
	  read_byte();
	  read_block();
	  data=r_buf[1]* 256 + r_buf[2];
		if(data <= 100) //distance à mettre en fonction de la pièce dans laquelle se trouve la raspberry
		{
			printf("Une personne vient de passer l'ultrason");
			// digitalWrite(pinBuzzer,1); envoie "HIGH" sur le port pinBuzzer (allume le buzzer)
			// pi_sleep(500); attend 500ms
			// digitalWrite(pinBuzzer,0); envoie "LOW" : éteind le buzzer
			// pi_sleep(500); attend 500ms
		}
	  printf("%d %d\n", r_buf[1], r_buf[2]);
	  printf("Distance : %d cm\n", data);
	  pi_sleep(500); // attend 500ms
	}
   	return 1;
}

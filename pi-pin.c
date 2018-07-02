#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wiringPi.h>

#define MIN_PIN 1
#define MAX_PIN 26

void showHelp(unsigned char);

/* Is a P1 connector pin usable for GPIO? */
const int isGpio[] = {0,0,0,1,0,1,0,1,1,0,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,0,1};

int main(int argc, char **argv) {
	if(argc < 3) showHelp(1);

	unsigned char pin = (unsigned char)atoi(argv[1]);
	if(pin < MIN_PIN || pin > MAX_PIN || !isGpio[pin]) showHelp(1);

	unsigned char level;
	if(strncmp(argv[2], "HIGH", 4) == 0 || strncmp(argv[2], "ON", 4) == 0) level = HIGH;
	else if(strncmp(argv[2], "LOW", 3) == 0 || strncmp(argv[2], "OFF", 3) == 0) level = LOW;
	else showHelp(1);

	printf("Setting pin %d to %d\n", pin, level);
	wiringPiSetupPhys();
	pinMode(pin, OUTPUT);
	digitalWrite(pin, level);

	return 0;
}

void showHelp(unsigned char error) {
	fputs("Usage: pi-pin PIN_NUM LEVEL\n", stdout);
	fputs("  PIN_NUM - P1 pin number, one of: ", stdout);
	for(int i = 0; i<=MAX_PIN; i++) {
		if(isGpio[i]) printf("%d ", i);
	}
	fputs("\n", stdout);
	fputs("  LEVEL - HIGH | LOW\n", stdout);
	exit(error);
}

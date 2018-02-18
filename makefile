CC=gcc
LIBS=-lwiringPi

OBJECTS=pi-pin.o

pi-pin : $(OBJECTS)
	$(CC) -o pi-pin $(OBJECTS) $(LIBS)

clean :
	rm pi-pin $(OBJECTS)

back: main.o backg.o
	gcc  main.o backg.o -o back -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c 
	gcc -c main.c 
backg.o:backg.c 
	gcc -c backg.c


PATH := $(DEVKITARM)/bin:$(PATH)
INCLUDE  := -I$(LIBTONC)/include
LIBPATHS := -L$(LIBTONC)/lib

all: juego.gba

background.gfx.c background.gfx.h : background.gfx.png
	grit background.gfx.png -gu16 -gB4 -mLs -ftc
background.gfx.h : background.gfx.c

background.gfx.o : background.gfx.c background.gfx.h
	arm-none-eabi-gcc -I${INCLUDE} -O2 -Wall -fno-strict-aliasing -mthumb-interwork -mthumb -c background.gfx.c -o background.gfx.o

main.o : main.c background.gfx.h
	arm-none-eabi-gcc ${INCLUDE} -O2 -Wall -fno-strict-aliasing -mthumb-interwork -mthumb -c main.c -o main.o

juego.elf : main.o background.gfx.o
	arm-none-eabi-gcc main.o background.gfx.o -mthumb-interwork -mthumb -specs=gba.specs ${LIBPATHS} -ltonc -o juego.elf

juego.gba : juego.elf
	arm-none-eabi-objcopy -v -O binary juego.elf juego.gba
	gbafix juego.gba -tjuego

clean :
	rm -f *.elf
	rm -f *.gba
	rm -f *.o
	rm -f *.gfx.c
	rm -f *.gfx.h

CC=arm-none-linux-gnueabi-gcc
#INC=/opt/arm-2011.09/include/
C_FLAGS= -static -l:libncurses.a

rtps: rtps.o
	$(CC) rtps.c -o rtps $(C_FLAGS)

clean: 
	rm -rf *.o rtps

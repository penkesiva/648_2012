CC=arm-none-linux-gnueabi-gcc
C_FLAGS= -static
rtps: rtps.o
	$(CC) $(C_FLAGS) rtps.c -o rtps

clean: 
	rm -rf *.o rtps

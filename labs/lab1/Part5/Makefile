CC=arm-none-linux-gnueabi-gcc
C_FLAGS= -static
tst_process_info: tst_process_info.o 
	$(CC) $(C_FLAGS) tst_process_info.c -o tst_process_info

clean:
	rm -rf *.o tst_process_info

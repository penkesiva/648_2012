CC=arm-none-linux-gnueabi-gcc
C_FLAGS= -static
test_my_syscall: test_my_syscall.o
	$(CC) $(C_FLAGS) test_my_syscall.c -o test_my_syscall

clean:
	rm -rf *.o test_my_syscall

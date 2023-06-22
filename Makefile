Emulator: 8080emulator.o opcodeHandling.o
	gcc -o Emulator 8080emulator.o opcodeHandling.o

8080emulator.o: 8080emulator.c
	gcc -c 8080emulator.c

opcodeHandling.o: opcodeHandling.c
	gcc -c opcodeHandling.c

clean:
		rm -f *.o
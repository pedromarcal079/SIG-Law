make:
	gcc -c -Wall *.h
	gcc -c -Wall *.c
	gcc -o siglaw *.o
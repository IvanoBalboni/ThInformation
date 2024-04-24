
test: TP1.exe
	./TP1.exe
TP1.exe: TP1.c TP1.h
	gcc -Wall -g -o TP1.exe TP1.c

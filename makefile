compilerParams=-Wall -Wshadow
programName=hashtable

all: $(programName)

$(programName): main.o hashTable.o
	gcc -o $(programName) main.o hashTable.o $(compilerParams)

main.o: main.c
	gcc -c main.c $(compilerParams)

hashTable.o: hashTable.h hashTable.c
	gcc -c hashTable.c $(compilerParams)

clean:
	rm -f *.o *.gch $(programName)
holand: main.o holand.o
	gcc $^  -o $@ 

holand.o: holand.h
main.o:holand.h

src.tar:holand.h holand.c main.c Makefile
	tar -cvf $^ > src.tar

.PHONY: clean
clean:
	rm *.o
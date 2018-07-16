forcabruta: forcabruta.o leituradados.o main.o
		gcc -O3 forcabruta.o main.o leituradados.o -o tp -lpthread
leituradados: leituradados.o main.o forcabruta.o
		gcc -O3 leituradados.o forcabruta.o main.o -o tp -lpthread
main.o: main.c leituradados.h forcabruta.h
		gcc -O3 -g -c main.c -lpthread
forcabruta.o: forcabruta.h forcabruta.c leituradados.h leituradados.c
		gcc -O3 -g -c forcabruta.c 
leituradados.o: leituradados.h leituradados.c forcabruta.c forcabruta.h
		gcc -O3 -g -c leituradados.c 
clean:
		rm *.o *.gch
			rm forcabruta
				rm leituradados

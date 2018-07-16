#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "forcabruta.h"
#include "leituradados.h"

int main(int argc, char *argv[])
{
	if((argv[1][0] == '-') && (argv[1][1] == 't'))
	{	
		
		quant = atoi(&argv[2][0]);	
		//printf("%d\n", quant);
		paral = (pthread_t*)malloc(sizeof(pthread_t)*quant);
		data_read();
		
	} // fim casos do arg
	free(paral);
    return 0;
}

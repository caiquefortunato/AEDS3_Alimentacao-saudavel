#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "leituradados.h"
#include "forcabruta.h"

// Função para paralelizar o problema
void Parallel() 
{
	int i, j;
	int tid, limit;
	int aux;
	stru tmp[quant];
	aux = vector_len + quant;
	
	for(j = 0; j < aux; j = j + quant) 
	{
		if(flag == 1)
			break;
	
		limit = (j > vector_len) ? (j % quant) : quant;
	
		for (i = 0; i < limit; i++)
		{
			tmp[tid].index = i + j;
			tmp[tid].sum = 0;
			pthread_create(&paral[i], NULL, enumeration_algorithm, (void*) &tmp);
		}
	
		for (i = 0; i < limit; i++)
			pthread_join(paral[i], NULL);
	}
} // end of funcion

void* enumeration_algorithm(void* value)
{
	stru* ST;
	ST = (stru*) value;
	if ((ST->sum + vector[ST->index]) == sum)
		flag = 1;
	
	enumeration_algorithm2((ST->index - 1), ST->sum + vector[ST->index]);
}

// Funcao recursiva de força bruta para resolver o problema
void enumeration_algorithm2(int index, int partial_sum)
{
    if(index == 0 || flag == 1)
		return;
		
    if(partial_sum == sum)
        flag = 1;

    // Caso ele va somar
    if ((partial_sum + vector[index]) <= sum)
    	enumeration_algorithm2(index - 1, partial_sum + vector[index]);
   	// Caso ele nao va somar
        enumeration_algorithm2(index - 1, partial_sum);
} // end of function

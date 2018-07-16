#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "forcabruta.h"
#include "leituradados.h"

void sort() 
{
	int i,j, x;
	
	for (i = 0; i < vector_len; i++)
  		for (j = i+1; j < vector_len; j++)
  			if (vector[i] < vector[j])
  			{
				x = vector[i];
  				vector[i] = vector[j];
  				vector[j] = x;
  			}
}

// Funcao de leitura
int data_read()
{
    int input;
    int i, j;
    char space, caractere[5]; // max 4 + 1
    
    vector = (int*)calloc(301, sizeof(int));
    scanf("%d", &input);

    for(i = 0; i < input; i++)
    {
        vector_len = 0, sum = 0, space = '\0';
        scanf("%d", &sum);
    
        for(j = 0; j < 301; j++)
        	vector[j] = 0;

        // Leitura das entradas
        while(1)
        {
            scanf("%s", caractere);
            vector[vector_len] = (int)atoi(caractere);
            scanf("%c", &space);
            if(space == '\n')
            {
                break;
            }
            vector_len++;
        } // fim das leituras dos vetor
  
  		// Ordeno os índices para otimizar o algoritmo
  		sort();
  		// Zerar as variaveis antes de enviar para a funcao
  		vector_len += 1;
  		partial_sum = 0;
  		flag = 0;
        stru val;
        val.index = 0; val.sum = 0;
        
        // Chamo a função para realizar a paralelização
        Parallel();

        if(flag == 1)
            printf("sim\n");
        else
            printf("nao\n");

    	
    } // fim dos casos de teste
        free(vector);
}


#include "TAD Cadena.h"

void leecad(TCadena cad, int tam){
	fflush(stdin);
	
	int i = 0, c = getchar();
	
	while(i < tam - 1 && c != EOF && c != '\n'){
		cad[i] = c;
		i++;
		c = getchar();
	}
	
	cad[i] = '\0';
	
	while(c != EOF && c != '\n')
		c = getchar();
}

#include "TAD Cadena.h"

typedef struct{
	long Codigo;
	TCadena Nombre, Proveedor;
	float Precio;
	int Disponibles;
}TR_Repuesto;

TR_Repuesto Cargar_Repuesto(void);
	
void Mostrar_Repuesto(TR_Repuesto rep);

int Disponibles_getter(TR_Repuesto rep);

long Codigo_getter(TR_Repuesto rep);

int Compara_proveedor(TR_Repuesto rep, TCadena proveedor);

void Modificar_Precio(TR_Repuesto *rep);

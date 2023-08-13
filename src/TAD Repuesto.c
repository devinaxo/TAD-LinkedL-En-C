#include "TAD Repuesto.h"

TR_Repuesto Cargar_Repuesto(void){
	TR_Repuesto rep;
	printf("\nIngrese los datos del repuesto a cargar:\n");
	
	printf("\n  .Codigo: ");
	scanf("%ld", &rep.Codigo);
	
	printf("\n  .Nombre: ");
	leecad(rep.Nombre, 50);
	
	printf("\n  .Proveedor: ");
	leecad(rep.Proveedor, 50);
	
	printf("\n  .Precio unitario: $");
	scanf("%f", &rep.Precio);
	
	printf("\n  .Unidades disponibles: ");
	scanf("%d", &rep.Disponibles);
	
	return rep;
}
	
void Mostrar_Repuesto(TR_Repuesto rep){
	printf("\n  .Codigo: %ld", rep.Codigo);
	printf("\n  .Nombre: %s", rep.Nombre);
	printf("\n  .Proveedor: %s", rep.Proveedor);
	printf("\n  .Precio unitario: $%.2f", rep.Precio);
	printf("\n  .Unidades disponibles: %d\n", rep.Disponibles);
}

int Disponibles_getter(TR_Repuesto rep){return rep.Disponibles;}

long Codigo_getter(TR_Repuesto rep){return rep.Codigo;}

int Compara_proveedor(TR_Repuesto rep, TCadena proveedor){return stricmp(rep.Proveedor, proveedor);}

void Modificar_Precio(TR_Repuesto *rep){
	Mostrar_Repuesto(*rep);
	printf("\nPrecio nuevo: $");
	scanf("%f", &rep->Precio);
	printf("\nPrecio actualizado con exito!\n");
}
	

#include <stdio.h>
#include <stdlib.h>
#include "TAD Repuesto.h"

typedef struct Nodo{
	TR_Repuesto Repuesto;
	struct Nodo *Sig;
}TR_Nodo;

typedef TR_Nodo *Tptr_Nodo;

Tptr_Nodo Crear_Repuesto(void);

void Agrega_al_principio(Tptr_Nodo *lista, Tptr_Nodo nodo);

void Agrega_al_final(Tptr_Nodo *lista, Tptr_Nodo nodo);

void Agrega_ordenado(Tptr_Nodo *lista, Tptr_Nodo nodo);

Tptr_Nodo Cargar_Lista(void);

void Elimina_uno(Tptr_Nodo *lista);

void Mostrar_Lista(Tptr_Nodo lista);

void Mostrar_uno(Tptr_Nodo lista);

void Modifica_uno(Tptr_Nodo *lista);

void Mostrar_por_proveedor(Tptr_Nodo lista);

void system_cmd(void);	

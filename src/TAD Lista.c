#include "TAD Lista.h"


void system_cmd(void){
	printf("\n");
	system("pause");
	system("cls");
}


Tptr_Nodo Crear_Nodo(void){
	Tptr_Nodo nodo = NULL;
	
	nodo = (Tptr_Nodo) malloc(sizeof(TR_Nodo));
	nodo->Sig = NULL;
	
	return nodo;
}
	
Tptr_Nodo Crear_Repuesto(void){
	Tptr_Nodo nodo = NULL;
	
	nodo = Crear_Nodo();
	nodo->Repuesto = Cargar_Repuesto();
	
	return nodo;
}



void Agrega_al_principio(Tptr_Nodo *lista, Tptr_Nodo nodo){
	nodo->Sig = *lista;
	*lista = nodo;
}

void Agrega_al_final(Tptr_Nodo *lista, Tptr_Nodo nodo){
	Tptr_Nodo aux = NULL;
	if(*lista != NULL){
		aux = *lista;
		while(aux->Sig != NULL)
			aux = aux->Sig;
		aux->Sig = nodo;
	}
	else *lista = nodo;
}

void Agrega_ordenado(Tptr_Nodo *lista, Tptr_Nodo nodo){
	Tptr_Nodo ant = NULL, sig = NULL;
	
	if(*lista != NULL && Codigo_getter(nodo->Repuesto) > Codigo_getter((*lista)->Repuesto)){
		sig = *lista;
		
		while(sig != NULL && Codigo_getter(nodo->Repuesto) > Codigo_getter(sig->Repuesto)){
			ant = sig;
			sig = sig->Sig;
		}
		ant->Sig = nodo;
		nodo->Sig = sig;
	}
	else Agrega_al_principio(lista, nodo);
}

Tptr_Nodo Cargar_Lista(void){
	Tptr_Nodo lista = NULL, nuevo = NULL;
	
	int rta = 1;
	
	while(rta == 1){
		nuevo = Crear_Repuesto();
		Agrega_al_principio(&lista, nuevo);
		
		system_cmd();
		
		printf("\nDesea agregar otro repuesto? (1. SI // 2. NO): ");
		scanf("%d", &rta);
	}
	return lista;
}



void Borrar_Nodo(Tptr_Nodo *lista, Tptr_Nodo *ant, Tptr_Nodo *ult){
	if(*ant != NULL) (*ant)->Sig = (*ult)->Sig;
	else *lista = (*ult)->Sig;
	free(*ult);
	*ult = NULL;
}

void Borrar_Repuesto(Tptr_Nodo *lista, long codigo_busc){
	Tptr_Nodo ant = NULL, ult = *lista;
	int rta;
	
	while(ult != NULL && Codigo_getter(ult->Repuesto) != codigo_busc){
		ant = ult;
		ult = ult->Sig;
	}
	if(ult != NULL) {
		Mostrar_Repuesto(ult->Repuesto);
		printf("\nEsta seguro que desea eliminarlo? (1. SI // 2. NO): ");
		scanf("%d", &rta);
		if(rta == 1){
			Borrar_Nodo(lista, &ant, &ult);
			printf("\nRepuesto eliminado correctamente!\n");
		}
	}
	else printf("\nRepuesto no encontrado!\n");
}

void Elimina_uno(Tptr_Nodo *lista){
	long codigo_busc;
	
	if(*lista != NULL){
		printf("\nIngrese el codigo del repuesto a eliminar: ");
		scanf("%ld", &codigo_busc);
		Borrar_Repuesto(lista, codigo_busc);
	}
	else printf("\nLista vacia!\n");	
}

	

void Mostrar_Lista(Tptr_Nodo lista){
	if(lista != NULL){
		printf("\nRepuestos cargados:\n");
		while(lista != NULL){
			Mostrar_Repuesto(lista->Repuesto);
			lista = lista->Sig;
		}
	}
	else printf("\nLista vacia!\n");
}

Tptr_Nodo Busca_uno(Tptr_Nodo lista, long codigo_busc){
	while(lista != NULL){
		if(Codigo_getter(lista->Repuesto) == codigo_busc) return lista;
		lista = lista->Sig;
	}
	return NULL;
}

void Mostrar_uno(Tptr_Nodo lista){
	long codigo_busc;
	
	if(lista != NULL){
		printf("\nIngrese el codigo del respuesto a buscar: ");
		scanf("%ld", &codigo_busc);
		
		lista = Busca_uno(lista, codigo_busc);
		if(lista != NULL){
			printf("\nRepuesto encontrado:\n");
			Mostrar_Repuesto(lista->Repuesto);
		}
		else printf("\nRepuesto no encontrado!\n");
	}
	else printf("\nLista vacia!\n");
}

void Modifica_uno(Tptr_Nodo *lista){
	long codigo_busc;
	Tptr_Nodo aux = NULL;
	
	if(*lista != NULL){
		printf("\nIngrese el codigo del respuesto a modificar: ");
		scanf("%ld", &codigo_busc);
		
		aux = Busca_uno(*lista, codigo_busc);
		if(aux != NULL){
			printf("\nRepuesto encontrado:\n");
			Modificar_Precio(&(aux->Repuesto));
		}
		else printf("\nRepuesto no encontrado!\n");
	}
	else printf("\nLista vacia!\n");
}

void Mostrar_por_proveedor(Tptr_Nodo lista){
	TCadena proveedor;
	Tptr_Nodo lista_aux = NULL, nodo_aux = NULL;
	
	if(lista != NULL){
		printf("\nIngrese el proveedor: ");
		leecad(proveedor, 50);
		
		while(lista != NULL){
			if(Compara_proveedor(lista->Repuesto, proveedor) == 0){
				nodo_aux = Crear_Nodo();
				nodo_aux->Repuesto = lista->Repuesto;
				Agrega_ordenado(&lista_aux, nodo_aux);
			}
			lista = lista->Sig;
		}
		if(lista_aux != NULL){
			Mostrar_Lista(lista_aux);
			nodo_aux = NULL;
			while(lista_aux != NULL)
				Borrar_Nodo(&lista_aux, &nodo_aux, &lista_aux);
		}
		else printf("\nProveedor no encontrado!\n");
	}
	else printf("\nLista vacia!\n");
}

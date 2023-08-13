#include "TAD Lista.h"
#include <Windows.h>

void opciones();
void menu_r(Tptr_Nodo *);

int main(){
	Tptr_Nodo repuestos = NULL;
	
	menu_r(&repuestos);
	
	return 0;
}

void opciones(){
	printf("\n----------------------------------------------");
	printf("\n               Menu de Opciones               ");
	printf("\n----------------------------------------------\n");
	printf("\n0. Cerrar programa");
	printf("\n1. Cargar varios repuestos (por cabecera)");
	printf("\n2. Agregar un repuesto al principio");
	printf("\n3. Agregar un repuesto ordenado");
	printf("\n4. Agregar un repuesto al final");
	printf("\n5. Eliminar un repuesto por codigo");
	printf("\n6. Modificar un repuesto por codigo");
	printf("\n7. Mostrar un repuesto por codigo");
	printf("\n8. Mostrar todos los repuestos");
	printf("\n9. Mostrar los repuestos por proveedor\n");
}
	
void menu_r(Tptr_Nodo *Repuestos){
	int rta;
	Tptr_Nodo nuevo;
	
	opciones();
	printf("\nSeleccione una opcion: ");
	scanf("%d", &rta);
	printf("\n----------------------------------------------\n");
	
	switch(rta){
		case 0: 
			printf("\nSaliendo del programa...");
			Sleep(3000);
			break;
		case 1:
			*Repuestos = Cargar_Lista();
			system_cmd();
			menu_r(Repuestos);
			break;
		case 2:
			nuevo = Crear_Repuesto();
			Agrega_al_principio(Repuestos, nuevo);
			system_cmd();
			menu_r(Repuestos);
			break;
		case 3:
			nuevo = Crear_Repuesto();
			Agrega_ordenado(Repuestos, nuevo);
			system_cmd();
			menu_r(Repuestos);
			break;
		case 4:
			nuevo = Crear_Repuesto();
			Agrega_al_final(Repuestos, nuevo);
			system_cmd();
			menu_r(Repuestos);
			break;
		case 5:
			Elimina_uno(Repuestos);
			system_cmd();
			menu_r(Repuestos);
			break;
		case 6:
			Modifica_uno(Repuestos);
			system_cmd();
			menu_r(Repuestos);
			break;
		case 7:
			Mostrar_uno(*Repuestos);
			system_cmd();
			menu_r(Repuestos);
			break;
		case 8:
			Mostrar_Lista(*Repuestos);
			system_cmd();
			menu_r(Repuestos);
			break;
		case 9:
			Mostrar_por_proveedor(*Repuestos);
			system_cmd();
			menu_r(Repuestos);
			break;
		default:
			printf("\nOpcion no valida!\n");
			system_cmd();
			menu_r(Repuestos);
			break;
	}
}

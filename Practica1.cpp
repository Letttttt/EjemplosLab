#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstring>

using namespace::std;

struct nodo{
	int dato;
	nodo* next;
    nodo* prev;
} *inicial, *final;

void NodoInsertar();
void ListaMostrar();
void ordenando(nodo* Entrada);
void NodoBuscar();

int main(){
	
	int opcion = 0;
	
	do
	{
		cout << "\n|*************************************|";
		cout << "\n|                MENÚ                 |";
		cout << "\n|*************************************|";
		cout << "\n| 1. Inserte                          |";
		cout << "\n| 2. Buscar                           |";
		cout << "\n| 3. Visualizar Lista                 |";
		cout << "\n| 4. Salir                            |";
		cout << "\n|*************************************|";
		cout << "\n\n Seleccione alguna opción: ";
		cin >> opcion;
		switch(opcion){
		case 1:
			cout << "\n\n Se inserta el nodo en la lista... \n\n";
			NodoInsertar();
			break;
		case 2:
			cout << "\n\n Buscando... \n\n";
			NodoBuscar();
			break;
		case 3:
			cout << "\n\n Se muestra lista... \n\n";
			ListaMostrar();
			break;
		case 4:
			cout << "\n\n Fin del programa. \n\n";
			break;
		default:
			cout << "\n\n Por favor ingrese una opcion correcta: \n\n";
		}
	} while (opcion != 4);
	
	
	return 0;
}
void NodoInsertar(){
	nodo* nuevo = new nodo();
	cout << " Ingrese el Dato: ";
	cin >> nuevo->dato;

	if(inicial == NULL){
		inicial = nuevo;
		inicial->next = NULL;
		final = nuevo;
	}else{
		ordenando(nuevo);
	}
	cout << "\n Se inserta nodo...\n\n";
}
void ordenando(nodo* Entrada){
    nodo* aux = inicial;
    while(aux != NULL){
        if(aux->dato < Entrada -> dato){
            aux = aux -> next;
            
        }else{

            if(aux == inicial){
                Entrada -> next = aux;
                aux -> prev = Entrada;
                inicial = Entrada;

            }else{
                Entrada -> prev = aux -> prev;
                aux -> prev -> next = Entrada;
                Entrada -> next = aux;
                aux -> prev = Entrada;
                return;
            }
        }
    }

    final -> next = Entrada;
    Entrada -> prev = final;
    final = Entrada;
}

void NodoBuscar(){
    nodo* temporal = inicial;
    int posicion = 0;
    int datoB;
    bool encontro = false;

    cout << " Ingrese el Dato: ";
    cin >> datoB;
    while(temporal != NULL){
        if(temporal->dato == datoB){
            cout << " No encontrado  " << posicion << endl;
            encontro = true;
            break;
        }else{
            posicion += 1;
        }
        temporal = temporal -> next;
    }
    if(encontro == false){
        cout  << "\n No encontrado \n\n";
    }
}

void ListaMostrar(){
	nodo* primario = new nodo();
	primario = inicial;
	if(inicial != NULL){
		
		while(primario != NULL){
			cout << "------------------------------------------- " << endl;
			cout << " Información: " << primario-> dato << endl;
           
			cout << "------------------------------------------- " << endl;
			primario = primario->next;
		}
		
	}else{
		cout  << "\n La Lista esta vacia. \n\n";
        
	}
}
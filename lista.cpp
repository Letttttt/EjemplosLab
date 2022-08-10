#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstring>

using namespace::std;

struct nodo{
	string nombre;
    string apellido;
    string edad;
    char direccion[150];
    char carrera[50];
    char curso[100];
    string estado;
	nodo* sig;
} *inicial1, *final;

void InsertarNodo();
void MostrarLista();
void Modificar();


int main(){
	int opcion = 0;
	
	do
	{
		cout << "\n|*************************************|";
		cout << "\n|             * LISTA *               |";
		cout << "\n|*************************************|";
		cout << "\n| 1) Opcion insertar                  |";
		cout << "\n| 2) Opción modificar                 |";
		cout << "\n| 3) Opción mostrar                   |";
		cout << "\n| 4) Salir                            |";
		cout << "\n|*************************************|";
		cout << "\n\n Seleccione una opción: ";
		cin >> opcion;
		switch(opcion){
		case 1:
			cout << "\n\n INSERTAR NODO \n\n";
			InsertarNodo();
			break;
		case 2:
			cout << "\n\n MODIFICAR \n\n";
			Modificar();
			break;
		case 3:
			cout << "\n\n MOSTRAR \n\n";
			MostrarLista();
			break;
		case 4:
			cout << "\n\n FINALIZACIÓN CORRECTA \n\n";
			break;
		default:
			cout << "\n\n Por favor ingrese una opción válida: \n\n";
		}
	} while (opcion != 4);
	
	
	return 0;
}

      

void InsertarNodo(){
	nodo* inicial = new nodo();
	cout << " Ingrese el Nombre: ";
	cin >> inicial->nombre;

    cout<<" Ingrese el Apellido: ";
    cin >> inicial -> apellido;

    cout<<" Ingrese la edad: ";
    cin >> inicial -> edad;

    cout <<" Ingrese la direccion: ";
	cin.ignore();
	gets(inicial->direccion);

    cout <<" Ingrese la carrera: ";
    gets(inicial->carrera);

    cout <<" Ingrese el curso: ";
    gets(inicial -> curso);

    cout <<" Ingrese el estado: ";
    cin >> inicial -> estado;

	if(inicial1 == NULL){
		inicial1 = inicial;
		inicial1->sig = NULL;
		final = inicial;
	}else{
		final->sig = inicial;
		inicial->sig = NULL;
		final = inicial;
	}
	cout << "\n Se agregó el nodo a la lista\n\n";
}


void MostrarLista(){
	nodo* actual = new nodo();
	actual = inicial1;
	if(inicial1 != NULL){
		
		while(actual != NULL){
			cout << "******************************************* " << endl;
			cout << " Nombre: " << actual-> nombre << endl;
            cout << " Apellido: " << actual-> apellido << endl;
            cout << " Edad: " << actual-> edad << endl;
            cout << " Direccion: " << actual-> direccion << endl;
            cout << " Carrera: " << actual-> carrera << endl;
            cout << " Curso: " << actual-> curso << endl;
            cout << " Estado: " << actual-> estado << endl;
			cout << "******************************************* " << endl;
			actual = actual->sig;
		}
		
	}else{
		cout  << "\n La Lista esta vacia \n\n";
	}
}

void Modificar(){
	nodo* actual = new nodo();
	actual = inicial1;
	bool encontrado = false;
	string nodoBuscado = "";
	cout << " Ingrese el Nombre a Buscar para Modificar: ";
	cin >> nodoBuscado;
	if(inicial1 != NULL){
		
		while(actual != NULL && encontrado != true){
			
			if(actual->nombre == nodoBuscado ){
				cout << "\n Nodo con el dato " << nodoBuscado << " Encontrado";
				cout << "\n Ingrese el inicial Estado: ";
				cin >> actual -> estado;

				cout <<" Ingrese la Nueva Edad: ";
				cin >> actual -> edad;

				cout <<" Ingrese la Nueva Direccion: ";
				cin.ignore();
				gets(actual->direccion);

				encontrado = true;
			}
			
			actual = actual->sig;
		}
		if(!encontrado){
			cout << "\n Nombre no encontrado\n\n";
		}
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}
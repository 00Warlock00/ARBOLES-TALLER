#include<iostream>
#include<malloc.h>
#include<cstring>
using namespace std;

struct rtn{
char nombre[40];
int codigo;
int anio,mes,dia;
rtn *izq;
rtn *der;
};
rtn *raizCodigo,*raizFecha,*aux;

int posicionararbolCodigo(rtn* aux, rtn* aux2) {
    if (aux->codigo < aux2->codigo) {
        if (aux2->izq != NULL) {
            aux2 = aux2->izq;
            posicionararbolCodigo(aux, aux2);
        }
        else
            aux2->izq = aux;
    }
    else if (aux->codigo > aux2->codigo) {
        if (aux2->der != NULL) {
            aux2 = aux2->der;
            posicionararbolCodigo(aux, aux2);
        }
        else
            aux2->der = aux;
    }

    return 0;
}

// Función para posicionar un nodo en el árbol2 según su fecha
int posicionararbolFecha(rtn* aux, rtn* aux2){
    // Comparamos primero el año
    if(aux->anio < aux2->anio){
        if(aux2->izq!=NULL){
            aux2=aux2->izq;
            posicionararbolFecha(aux,aux2);
        }
        else
            aux2->izq=aux;
    }
    else if(aux->anio > aux2->anio){
        if(aux2->der!=NULL){
            aux2=aux2->der;
            posicionararbolFecha(aux, aux2);
        }
        else{
            aux2->der=aux;
     }
    }

    else { // Si los años son iguales, comparamos el mes
        if(aux->mes < aux2->mes){
            if(aux2->izq!=NULL){
                aux2=aux2->izq;
                posicionararbolFecha(aux,aux2);
            }
            else
                aux2->izq=aux;
        }
        else if(aux->mes > aux2->mes){
            if(aux2->der!=NULL){
                aux2=aux2->der;
                posicionararbolFecha(aux, aux2);
            }
            else{
                aux2->der=aux;
         }
        }
        else { // Si los meses son iguales, comparamos el día
            if(aux->dia < aux2->dia){
                if(aux2->izq!=NULL){
                    aux2=aux2->izq;
                    posicionararbolFecha(aux,aux2);
                }
                else
                    aux2->izq=aux;
            }
            else if(aux->dia > aux2->dia){
                if(aux2->der!=NULL){
                    aux2=aux2->der;
                    posicionararbolFecha(aux, aux2);
                }
                else
                    aux2->der=aux;
            }
        }
    }
    return 0;
}


int registrar(){
aux= ((struct rtn*)malloc(sizeof(struct rtn)));

cout<<"codigo de la entidad RNT: "<<endl;
cin>>aux->codigo;
cout<<"Año de la fecha de la entidad RNT: "<<endl;
cin>>aux->anio;
cout<<"Mes de la fecha de la entidad RNT: "<<endl;
cin>>aux->mes;
cout<<"Dia de la fecha de la entidad RNT: "<<endl;
cin>>aux->dia;

aux->izq=aux->der=NULL;
if(raizCodigo==NULL){
raizCodigo= aux;
aux=NULL;
}
else{

posicionararbolCodigo(aux, raizCodigo);

}

// Si la raíz2 está vacía, el nuevo nodo será la raíz2
    if(raizFecha == NULL){
        raizFecha = aux;
        
    }
    else{
        posicionararbolFecha(aux, raizFecha);
    }

return 0;
};

//ordenamientos por codigo.

// Función para recorrer el árbol en preorden
void recorridoPreordenCodigo(rtn* nodo) {
    if (nodo != NULL) {
        // Mostramos los datos del nodo
        cout << "Codigo: " << nodo->codigo << ", Fecha: " << nodo->anio << "/" << nodo->mes << "/" << nodo->dia << endl;
        // Recorremos el subárbol izquierdo
        recorridoPreordenCodigo(nodo->izq);
        // Recorremos el subárbol derecho
        recorridoPreordenCodigo(nodo->der);
    }
}
void recorridoInordenCodigo(rtn* orden){

if(orden!=NULL){
     if(orden->izq!=NULL){
 recorridoInordenCodigo(orden->izq);
  cout<<"Codigo: " << orden->codigo << ", Fecha: " << orden->anio << "/" << orden->mes << "/" << orden->dia << endl;
}else{
    if(orden->der!=NULL){
        recorridoInordenCodigo(orden->der);
      cout<<"Codigo: " << orden->codigo << ", Fecha: " << orden->anio << "/" << orden->mes << "/" << orden->dia << endl;
    }
  }
 }
}//fin metodo.

void recorridoPostordenCodigo(rtn* sett){
if(sett!=NULL){
     if(sett->izq!=NULL){
 recorridoInordenCodigo(sett->izq);
}else{
    if(sett->der!=NULL){
        recorridoInordenCodigo(sett->der);
    }
  }
 }
  cout<<"Codigo: " << sett->codigo << ", Fecha: " << sett->anio << "/" << sett->mes << "/" << sett->dia << endl;
return;
}//fin metodo.

//fin recorridos por codigo.

void recorridoPreordenFecha(rtn* add){
    if(add!=NULL){
    cout<<"FECHA: "<<add->anio<<"/"<<add->mes<<"/"<<add->dia<<"/"<<" "<< "CON CODIGO: "<<add->codigo;
    recorridoPreordenFecha(add->izq);
    recorridoPreordenFecha(add->der);
    }

}//fin metodo.

void recorridoInordenFecha(rtn* add2){
if(add2->izq!=NULL){
    recorridoInordenFecha(add2->izq);
    cout<<"FECHA: "<<add2->anio<<"/"<<add2->mes<<"/"<<add2->dia<<"/"<<" "<< "CON CODIGO: "<<add2->codigo;
}else{
    if(add2->der!=NULL){
    recorridoInordenFecha(add2->der);
    cout<<"FECHA: "<<add2->anio<<"/"<<add2->mes<<"/"<<add2->dia<<"/"<<" "<< "CON CODIGO: "<<add2->codigo;
  }
 }
}//fin metodo.

void recorridoPostordenFecha(rtn* add3){
if(add3->izq!=NULL){
    recorridoPostordenFecha(add3->izq);
}else{
    if(add3->der!=NULL){
recorridoPostordenFecha(add3->der);
    }
    cout<<"FECHA: "<<add3->anio<<"/"<<add3->mes<<"/"<<add3->dia<<"/"<<" "<<" CON CODIGO: "<<add3->codigo;
}
}//fin metodo.


int main(){
	int opc = 0, subOpc = 0;
    do {
        cout << "\nMenu:\n";
        cout << "1. Registrar \n";
        cout << "2. Mostrar recorridos\n";
        cout << "3. salir\n";

        cin >> opc;
        cout << endl;

        switch (opc) {
        case 1:
            registrar();
            break;

        case 2:
            cout << "1. Recorridos por codigo\n";
            cout << "2. Recorridos por fecha\n";
            cin >> subOpc;
            switch (subOpc) {
            case 1:
                cout << "Recorrido preorden por codigo: " << endl;
                recorridoPreordenCodigo(raizCodigo);
                cout << "Recorrido inorden por codigo: " << endl;
                recorridoInordenCodigo(raizCodigo);
                cout << "Recorrido postorden por codigo:\n " << endl;
                recorridoPostordenCodigo(raizCodigo);
                break;
            case 2:
                cout << "Recorrido preorden por fecha:\n " << endl;
                recorridoPreordenFecha(raizFecha);
                cout << "Recorrido inorden por fecha:\n " << endl;
                recorridoInordenFecha(raizFecha);
                cout << "Recorrido postorden por fecha:\n " << endl;
                recorridoPostordenFecha(raizFecha);
                break;
            default:
                cout << "Opción inválida. Por favor, ingrese una opción válida.\n" << endl;
                break;
            }
            break;

        case 3:
            cout << "BYE BYE.\n" << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, ingrese una opción válida.\n" << endl;
            break;
        }
    } while (opc != 3);
    return 0;
}
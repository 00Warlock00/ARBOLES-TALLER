#include <iostream>
#include <malloc.h>
using namespace std;

struct rtn
{
    long codigo;
    int anio, mes, dia;
    rtn *izq;
    rtn *der;
};
rtn *raizCodigo, *raizFecha, *aux;

int posicionararbolCodigo(rtn *aux2)
{
    if (aux->codigo < aux2->codigo)
    {
        if (aux2->izq != NULL)
        {
            aux2 = aux2->izq;
            posicionararbolCodigo(aux2);
        }
        else
            aux2->izq = aux;
    }
    else if (aux->codigo > aux2->codigo)
    {
        if (aux2->der != NULL)
        {
            aux2 = aux2->der;
            posicionararbolCodigo(aux2);
        }
        else
            aux2->der = aux;
    }

    return 0;
}

// Función para posicionar un nodo en el árbol2 según su fecha
int posicionararbolFecha(rtn *aux2)
{
    // Comparamos primero el año
    if (aux->anio < aux2->anio)
    {
        if (aux2->izq != NULL)
        {
            aux2 = aux2->izq;
            posicionararbolFecha(aux2);
        }
        else
            aux2->izq = aux;
    }
    else if (aux->anio > aux2->anio)
    {
        if (aux2->der != NULL)
        {
            aux2 = aux2->der;
            posicionararbolFecha(aux2);
        }
        else
        {
            aux2->der = aux;
        }
    }

    else
    { // Si los años son iguales, comparamos el mes
        if (aux->mes < aux2->mes)
        {
            if (aux2->izq != NULL)
            {
                aux2 = aux2->izq;
                posicionararbolFecha(aux2);
            }
            else
                aux2->izq = aux;
        }
        else if (aux->mes > aux2->mes)
        {
            if (aux2->der != NULL)
            {
                aux2 = aux2->der;
                posicionararbolFecha(aux2);
            }
            else
            {
                aux2->der = aux;
            }
        }
        else
        { // Si los meses son iguales, comparamos el día
            if (aux->dia < aux2->dia)
            {
                if (aux2->izq != NULL)
                {
                    aux2 = aux2->izq;
                    posicionararbolFecha(aux2);
                }
                else
                    aux2->izq = aux;
            }
            else if (aux->dia > aux2->dia)
            {
                if (aux2->der != NULL)
                {
                    aux2 = aux2->der;
                    posicionararbolFecha(aux2);
                }
                else
                    aux2->der = aux;
            }
        }
    }
    return 0;
}

int registrar()
{

    aux = ((struct rtn *)malloc(sizeof(struct rtn)));

    cout << " codigo de la entidad RNT: " << endl;
    cin >> aux->codigo;
    cout << " Año de la fecha de la entidad RNT: " << endl;
    cin >> aux->anio;
    cout << " Mes de la fecha de la entidad RNT: " << endl;
    cin >> aux->mes;
    cout << " Dia de la fecha de la entidad RNT: " << endl;
    cin >> aux->dia;

    aux->izq = aux->der = NULL;
    if (raizCodigo == NULL)
    {
        raizCodigo = aux;
        aux = NULL;
    }
    else
    {

        posicionararbolCodigo(raizCodigo);
    }

    // Si la raíz2 está vacía, el nuevo nodo será la raíz2
    if (raizFecha == NULL)
    {
        raizFecha = aux;
    }
    else
    {
        posicionararbolFecha(raizFecha);
    }

    return 0;
}

// ordenamientos por codigo.

// Función para recorrer el árbol en preorden
void recorridoPreordenCodigo(rtn *nodo)
{
    if (nodo != NULL)
    {
        cout << "Codigo: " << nodo->codigo << "\n ";
        recorridoPreordenCodigo(nodo->izq);
        recorridoPreordenCodigo(nodo->der);
    }
}
void recorridoInordenCodigo(rtn *orden)
{
    if (orden != NULL)
    {
        recorridoInordenCodigo(orden->izq);
        cout << "Codigo: " << orden->codigo << "\n ";
        recorridoInordenCodigo(orden->der);
    }
} // fin metodo.


void recorridoPostordenCodigo(rtn *sett)
{
    if (sett != NULL)
    {
        recorridoPostordenCodigo(sett->izq);
        recorridoPostordenCodigo(sett->der);
        cout << "Codigo: " << sett->codigo << "\n ";
    }
}// fin metodo.

// fin recorridos por Codigo.

void recorridoPreordenFecha(rtn *nodo)
{
    if (nodo != NULL)
    {
        cout << "FECHA: " << nodo->anio << "/" << nodo->mes << "/" << nodo->dia << "/"
             << "\n ";
        recorridoPreordenFecha(nodo->izq);
        recorridoPreordenFecha(nodo->der);
    }
} // fin metodo.

void recorridoInordenFecha(rtn *nodo)
{
    if (nodo != NULL)
    {
        recorridoInordenFecha(nodo->izq);
        cout << "FECHA: " << nodo->anio << "/" << nodo->mes << "/" << nodo->dia << "/"
             << "\n ";
        recorridoInordenFecha(nodo->der);
    }
}// fin metodo.

void recorridoPostordenFecha(rtn *nodo)
{
    if (nodo != NULL)
    {
        recorridoPostordenFecha(nodo->izq);
        recorridoPostordenFecha(nodo->der);
        cout << "FECHA: " << nodo->anio << "/" << nodo->mes << "/" << nodo->dia << "/"
             << "\n ";
    }
} // fin metodo.
// fin metodos por Fecha.

void EliminarArbolCodigo(rtn *co, int eliminar)
{

    if (co == NULL)
    {
        return;
    }
    else
    {

        if (co->codigo < eliminar)
        {
            EliminarArbolCodigo(co->izq, eliminar);
        }
        else if (co->codigo > eliminar)
        {
            EliminarArbolCodigo(co->der, eliminar);
        }
        else
        {
            if (co->der == NULL)
            {
                rtn *temp = co->izq;
                delete co;
                co = temp;
            }
            else if (co->izq == NULL)
            {
                rtn *temp = co->der;
                delete co;
                co = temp;
            }
            else
            {
                rtn *temp = co->der;
                while (temp->izq != NULL)
                {
                    temp = temp->izq;
                }

                co->codigo = temp->codigo;
                co->anio = temp->anio;
                co->mes = temp->mes;
                co->dia = temp->dia;
                EliminarArbolCodigo(raizCodigo, eliminar);
            }
        }
    }
    return;
}

void EliminarArbolFecha(rtn *nodo, int anio, int mes, int dia)
{
    if (nodo == NULL)
    {
        return;
    }

    if (anio < nodo->anio)
    {
        EliminarArbolFecha(nodo->izq, anio, mes, dia);
    }
    else if (anio > nodo->anio)
    {
        EliminarArbolFecha(nodo->der, anio, mes, dia);
    }
    else if (mes < nodo->mes)
    {
        EliminarArbolFecha(nodo->der, anio, mes, dia);
    }
    else if (mes > nodo->mes)
    {
        EliminarArbolFecha(nodo->der, anio, mes, dia);
    }
    else if (dia < nodo->dia)
    {
        EliminarArbolFecha(nodo->izq, anio, mes, dia);
    }
    else if (dia > nodo->dia)
    {
        EliminarArbolFecha(nodo->der, anio, mes, dia);
    }
    else
    {
        if (nodo->izq == NULL)
        {
            rtn *temp = nodo->der;
            delete nodo;
            nodo = temp;
        }
        else if (nodo->der == NULL)
        {
            rtn *temp = nodo->izq;
            delete nodo;
            nodo = temp;
        }
        else
        {
            rtn *temp = nodo->der;
            while (temp->izq != NULL)
            {
                temp = temp->izq;
            }

            nodo->codigo = temp->codigo;
            nodo->anio = temp->anio;
            nodo->mes = temp->mes;
            nodo->dia = temp->dia;
            EliminarArbolFecha(raizFecha, anio, mes, dia);
        }
    }
    return;
}

int main()
{
    int anio = 0, mes = 0, dia = 0,codigo=0;
    int opc = 0, subOpc = 0, subOpc2 = 0;
    do
    {
        cout << "\tMENU:\n";
        cout << "1. REGISTRAR \n";
        cout << "2. MOSTRAR RECORRIDOS\n";
        cout << "3. ELIMINAR NODO\n";
        cout << "4. SALIR\n";

        cin >> opc;
        cout << endl;

        switch (opc)
        {
        case 1:
            registrar();
            break;

        case 2:
            cout << "1. Recorridos por codigo\n";
            cout << "2. Recorridos por fecha\n";
            cin >> subOpc;
            switch (subOpc)
            {
            case 1:
                cout << "Recorrido preorden por codigo:\n " << endl;
                cout << " \n";
                recorridoPreordenCodigo(raizCodigo);
                cout << " \n";
                cout << "Recorrido inorden por codigo:\n " << endl;
                recorridoInordenCodigo(raizCodigo);
                cout << " \n";
                cout << "Recorrido postorden por codigo:\n " << endl;
                recorridoPostordenCodigo(raizCodigo);
                cout << " \n";
                break;
            case 2:
                cout << "Recorrido preorden por fecha:\n " << endl;
                recorridoPreordenFecha(raizFecha);
                cout << " \n";
                cout << "Recorrido inorden por fecha:\n " << endl;
                recorridoInordenFecha(raizFecha);
                cout << " \n";
                cout << "Recorrido postorden por fecha:\n " << endl;
                recorridoPostordenFecha(raizFecha);
                cout << " \n";
                break;
            default:
                cout << "Opción inválida. Por favor, ingrese una opción válida.\n"
                     << endl;
                break;
            }
            break;

        case 3:

            cout << "1.\tELIMINAR NODO CODIGO\n";
            cout << "2.\tELIMINAR NODO FECHA\n";
            cin >> subOpc2;
            switch (subOpc2)
            {
            case 1:
            cout<<"DIGITE EL CODIGO A ELIMINAR\n";
            cin>>codigo;
                EliminarArbolCodigo(raizCodigo, codigo);
                cout << "NODO ELIMINADO SATISFACTORIAMENTE" << endl;
                break;
            case 2:
                cout << "\tDIGITE LA FECHA A ELIMINAR(SE BORRA TODO CON LA FECHA)\n";
                cout << "AÑO\n";
                cin >> anio;
                cout << "MES\n";
                cin >> mes;
                cout << "DIA\n";
                cin >> dia;
                EliminarArbolFecha(raizFecha, anio, mes, dia);
                cout << "NODO ELIMINADO SATISFACTORIAMENTE" << endl;
                break;
            }
        case 4:
            cout << "BYE BYE.\n"
                 << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, ingrese una opción válida.\n"
                 << endl;
            break;
        }
    } while (opc != 4);
    return 0;
}

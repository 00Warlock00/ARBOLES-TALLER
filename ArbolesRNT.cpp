#include <iostream>
#include <malloc.h>
using namespace std;

struct rtn
{
    long codigo;
    int anio, mes, dia;
    int categoria;
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
void NodosCategoria(rtn *aux3, int categoria)
{
    if (aux3 != NULL)
    {
        if (aux3->categoria == categoria)
        {
            cout << " CODIGO: " << aux3->codigo << "  " << " FECHA: " << "" << aux3->anio << "/" << aux3->mes << "/" << aux3->dia << "\n";
        }
        NodosCategoria(aux3->izq, categoria);
        NodosCategoria(aux3->der, categoria);
    }
}
void MostrarCategoria()
{

    int mostrar = 0;
    do
    {
        cout << "\tSE MOSTRARAN LAS EMPRESAS DE ACUERDO A LA OPCION DIGITADA\n";
        cout << "\nCATEGORIAS:\n";
        cout << "1.HOSPEDAJE\n";
        cout << "2.TRANSPORTE\n";
        cout << "3.GASTRONOMIA\n";
        cout << "4.SALIR\n";
        cout << "OPCION:\n";
        cin >> mostrar;

        switch (mostrar)
        {
        case 1:
            cout << "HOSPEDAJE\n";
            NodosCategoria(raizCodigo, 1);
            break;
        case 2:
            cout << "TRANSPORTE\n";
            NodosCategoria(raizCodigo, 2);
            break;
        case 3:
            cout << "GASTRONOMIA\n";
            NodosCategoria(raizCodigo, 3);
            break;
        case 4:
            cout << "BYE BYE\n";
            break;
        default:
            cout << "OPCION INVALIDA\n";
            break;
        }
    } while (mostrar != 4);
}

int registrar()
{
    int categoria = 0;
    aux = ((struct rtn *)malloc(sizeof(struct rtn)));

    do
    {

        cout << " \tIngrese categoria a la que pertenece\n";
        cout << "1. HOSPEDAJE\n";
        cout << "2. TRANSPORTE\n";
        cout << "3. GASTRONOMIA\n";
        cout << "OPCION: ";
        cin >> categoria;

        switch (categoria)
        {
        case 1:
            aux->categoria = 1;
            break;
        case 2:
            aux->categoria = 2;
            break;
        case 3:
            aux->categoria = 3;
            break;
        default:
            cout << "Opción inválida. Por favor, ingrese una opción válida.\n";
            return 0;
        }

        cout << " codigo de la entidad RNT: " << endl;
        cin >> aux->codigo;
        cout << " Año de la fecha de la entidad RNT: " << endl;
        do
        {
            cin >> aux->anio;
            if (aux->anio < 1900 || aux->anio > 2024)
            {
                cout << "Año inválido. Ingrese un año entre 1900 y 2024: ";
            }
        } while (aux->anio < 1900 || aux->anio > 2024);
        cout << " Mes de la fecha de la entidad RNT: " << endl;
        do
        {
            cin >> aux->mes;
            if (aux->mes < 1 || aux->mes > 12)
            {
                cout << "Mes inválido. Ingrese un mes entre 1 y 12: ";
            }
        } while (aux->mes < 1 || aux->mes > 12);
        cout << " Dia de la fecha de la entidad RNT: " << endl;
        do
        {
            cin >> aux->dia;
            if (aux->dia < 1 || aux->dia > 31)
            {
                cout << "Día inválido. Ingrese un día entre 1 y 31: ";
            }
        } while (aux->dia < 1 || aux->dia > 31);

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
    } while (categoria != 4);
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
} // fin metodo.

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
} // fin metodo.

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

bool buscarNodoPorCodigo(rtn *nodo, int codigo)
{
    if (nodo == NULL)
    {
        return false;
    }
    if (nodo->codigo == codigo)
    {
        return true;
    }
    return buscarNodoPorCodigo(nodo->izq, codigo) || buscarNodoPorCodigo(nodo->der, codigo);
}

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

bool buscarNodoPorFecha(rtn *nodo, int anio, int mes, int dia)
{
    if (nodo == NULL)
    {
        return false;
    }
    if (nodo->anio == anio && nodo->mes == mes && nodo->dia == dia)
    {
        return true;
    }
    return buscarNodoPorFecha(nodo->izq, anio, mes, dia) || buscarNodoPorFecha(nodo->der, anio, mes, dia);
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
    int anio = 0, mes = 0, dia = 0, codigo = 0;
    int opc = 0, subOpc = 0, subOpc2 = 0, categoria = 0;
    do
    {
        cout << "\tMENU:\n";
        cout << "1. REGISTRAR \n";
        cout << "2. MOSTRAR RECORRIDOS\n";
        cout << "3. MOSTRAR CATEGORIAS\n";
        cout << "4. ELIMINAR NODO\n";
        cout << "5. SALIR\n";

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
            MostrarCategoria();
            break;

        case 4:
            cout << "1.\tELIMINAR NODO CODIGO\n";
            cout << "2.\tELIMINAR NODO FECHA\n";
            cin >> subOpc2;

            if (subOpc2 == 1 || subOpc2 == 2)
            {
                switch (subOpc2)
                {
                case 1:
                    cout << "DIGITE EL CODIGO A ELIMINAR\n";
                    cin >> codigo;
                    if (buscarNodoPorCodigo(raizCodigo, codigo))
                    {
                        EliminarArbolCodigo(raizCodigo, codigo);
                        cout << "NODO ELIMINADO SATISFACTORIAMENTE" << endl;
                    }
                    else
                    {
                        cout << "EL CODIGO INGRESADO NO EXISTE" << endl;
                    }
                    break;
                case 2:
                    cout << "\tDIGITE LA FECHA A ELIMINAR(SE BORRA TODO CON LA FECHA)\n";
                    cout << "AÑO\n";
                    cin >> anio;
                    cout << "MES\n";
                    cin >> mes;
                    cout << "DIA\n";
                    cin >> dia;
                    if (buscarNodoPorFecha(raizFecha, anio, mes, dia))
                    {
                        EliminarArbolFecha(raizFecha, anio, mes, dia);
                        cout << "NODO ELIMINADO SATISFACTORIAMENTE" << endl;
                    }
                    else
                    {
                        cout << "LA FECHA INGRESADA NO EXISTE" << endl;
                    }
                    break;
                }
            }
            else
            {
                cout << "Opción inválida. Por favor, ingrese una opción válida.\n";
            }
            break;
        case 5:
            cout << "BYE BYE.\n"
                 << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, ingrese una opción válida.\n"
                 << endl;
            break;
        }
    } while (opc != 5);
    return 0;
}

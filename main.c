

#include "helper.h"

int main()
{
    Pila *pila=newPila();
    Lista *lista=newLista();
    ColaCircular *cola=newColaCircular();

    enlistar(lista, newTarea("limpiar oficina"));
    enlistar(lista, newTarea("Buscar café"));
    enlistar(lista, newTarea("practicar Matematica"));
    enlistar(lista, newTarea("Dormir"));


    precesandorDeTareas(lista, newTarea("limpiar oficina"),cola);
    precesandorDeTareas(lista, newTarea("Buscar café"),cola);
    precesandorDeTareas(lista, newTarea("practicar Matematica"),cola);
    almacenDeTareasCompletas(cola,pila);
    mostrarPila(pila);

    return 0;
}
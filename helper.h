//
// Created by Fran on 03/09/2024.
//

#ifndef UNTITLED34_HELPER_H
#define UNTITLED34_HELPER_H
#define TAM 10
typedef struct tarea
{
    struct tarea *sig;
    char actividad[32];
}Tarea;
typedef struct lista
{
    Tarea *cab;
}Lista;
typedef struct colaCircular
{
    Tarea *pos[TAM];
}ColaCircular;
typedef struct pila
{
    Tarea *tope;
}Pila;
Tarea *newTarea(char *actividad);
Lista *newLista();
ColaCircular *newColaCircular();
Pila *newPila();
void enlistar(Lista*lista,Tarea *tareaAI);
void precesandorDeTareas(Lista*lista,Tarea *tareaAE,ColaCircular*cola);
void almacenDeTareasCompletas(ColaCircular*cola,Pila*pila);
void mostrarPila(Pila *pila);

#endif //UNTITLED34_HELPER_H

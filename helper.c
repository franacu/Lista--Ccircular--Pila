//
// Created by Fran on 03/09/2024.
//

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "helper.h"

Tarea *newTarea(char *actividad)
{
    Tarea *aux= malloc(sizeof(Tarea));
    if(aux==NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    strcpy(aux->actividad,actividad);
    return aux;
}
Lista *newLista()
{
    Lista *aux= malloc(sizeof(Lista));
    if(aux==NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    aux->cab=NULL;
    return aux;
}
ColaCircular *newColaCircular()
{
    ColaCircular *aux= malloc(sizeof(ColaCircular));
    if(aux==NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    for(int i=0;i<TAM;i++)
    {
        aux->pos[i]=NULL;
    }
    return aux;
}
Pila *newPila()
{
    Pila *aux= malloc(sizeof(Pila));
    if(aux==NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    aux->tope=NULL;
    return aux;
}
void enlistar(Lista*lista,Tarea *tareaAI)
{
    if(lista->cab==NULL)
    {
        lista->cab=tareaAI;
    }else
        {
            Tarea *aux=lista->cab;
            while (aux->sig!=NULL)
            {
                aux=aux->sig;
            }
            aux->sig=tareaAI;
        }
}
void precesandorDeTareas(Lista*lista,Tarea *tareaAE,ColaCircular*cola)
{
    Tarea *act=lista->cab;
    Tarea *ant=NULL;
    while (act!=NULL)
    {
        if(strcmp(act->actividad,tareaAE->actividad) == 0)
        {
            if(ant==NULL)
            {
                lista->cab=act->sig;
            }else
                {
                    ant->sig=act->sig;
                }

            int posAct=-1;
            for(int i=0;i<TAM;i++)
            {
                if(cola->pos[i]==NULL)
                {
                    posAct=i;
                }
            }
            if(posAct==-1)
            {
                for(int i=0;i<TAM-1;i++)
                {
                    cola->pos[i]=cola->pos[i+1];
                }
                posAct=TAM-1;
            }
            cola->pos[posAct]=act;
        }
        ant=act;
        act=act->sig;
    }
}
void almacenDeTareasCompletas(ColaCircular*cola,Pila*pila)
{
    for(int i=0;i<TAM;i++)
    {
        if(cola->pos[i]!=NULL)
        {
            Tarea *eliminar=cola->pos[i];
            cola->pos[i]=eliminar->sig;

            eliminar->sig=pila->tope;
            pila->tope=eliminar;
        }
    }
}
void mostrarPila(Pila *pila)
{
    Tarea *act=pila->tope;
    while (act!=NULL)
    {
        printf("Actividad Realizada:%s \n",act->actividad);
        act=act->sig;
    }
}



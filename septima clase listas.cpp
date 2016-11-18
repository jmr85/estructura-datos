
#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" //Libreria propia de lectura

struct lista{
    int num;
    struct lista *sig;
};

void crear_lista(struct lista *&com);
void mostrar_lista_rec(struct lista *com);
void cargar_adelante(struct lista *&com, int n);
void sacar_ultimo(struct lista *&com);

int main (void){
   //int n;
     		
   struct lista *com;
   
   crear_lista(com);
   mostrar_lista_rec(com);
   //pedir_nro(n);
   //cargar_adelante(com, n);
   sacar_ultimo(com);
   mostrar_lista_rec(com);
   
   system("pause");
   return(0);
}

void crear_lista(struct lista *&com){
    struct lista *p;
    struct lista *ant;
    int n;
    pedir_nro(n);
    if(n == 0){//lista vacia
        com = NULL;
    }else{
        com = new struct lista;
        com->num = n;
        com->sig = NULL;
        pedir_nro(n);
        ant = com; //apuntan al mismo
        while(n != 0){
            p = new struct lista;
            p->num = n;
            ant->sig = p; 
            p->sig = NULL;
            ant = p;
            pedir_nro(n);
        }
        
	}
}
void mostrar_lista_rec(struct lista *com){
    
    if(com != NULL){
        printf("\n Nodo->num: %d\n", com->num);
        mostrar_lista_rec(com->sig);
    }
}
void cargar_adelante(struct lista *&com, int n){
	
    if(n == 0){//lista vacia
        com = NULL;
    }else if(com->sig == NULL){
        com = new struct lista;
        com->num = n;
        com->sig = NULL;
    } 
}
void sacar_ultimo(struct lista *&com){
    struct lista *aux;
    aux = com;

    if(com->sig == NULL){
        delete(com);  
    }
}

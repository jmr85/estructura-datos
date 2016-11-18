#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" //Libreria propia de lectura

struct lista{
    int num;
    struct lista *sig;
};


void crear_lista(struct lista *&com);
void mostrar_lista_rec(struct lista *&com);
void mostrar_lista_pares_rec(struct lista *&com)
int contar_pares(struct lista *&com);
int contar_pares_rec(struct lista *&com);
int contar_pares_posicion(struct lista *&com);
int contar_pares_posicion_rec(struct lista *&com);

int main (void){
   struct lista *com;
   
   crear_lista(com);
   printf("\n***** Todos los nodos ******\n");
   mostrar_lista_rec(com);
   printf("\n***** Nodos con nros pares ******\n");
   mostrar_lista_pares_rec(com);
   
   printf("\n***** cuenta VALORES pares ******\n");
   
   printf("Cantidad de valores pares: %d\n", contar_pares(com));
   printf("(recursivo) Cantidad de valores pares: %d\n\n", contar_pares_rec(com));
   

   printf("\n***** cuenta POSICIONES pares ******\n");
   
   printf("Cantidad de posiciones pares: %d\n", contar_pares_posicion(com));
   printf("(recursivo) Cantidad de posiciones pares: %d\n\n", contar_pares_posicion_rec(com));
    
   
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


void mostrar_lista_rec(struct lista *&com){
    if(com != NULL){
        printf("\n Nodo->num: %d\n", com->num);
        mostrar_lista_rec(com->sig);
    }
}
void mostrar_lista_pares_rec(struct lista *&com){
    struct lista *p;
    p = com;
    if(p != NULL){
        if(p->num % 2 == 0){
            printf("%d", p->num);
        }
        mostrar_lista_pares_rec(p->sig);
    }
}

int contar_pares(struct lista *&com){
        int res;
        struct lista *p = com;
        res = 0;
        while(p != NULL){
            if(p->num % 2 == 0){
                res++;
            }
            p = p->sig;
        }
        return(res);
}
int contar_pares_rec(struct lista *&com){
        int res;
        if(com != NULL){
            if(com->num % 2 == 0){
                res = 1 + contar_pares(com->sig);
            }else{
                res = contar_pares(com->sig);
            } 
        }else{
            res = 0;
        }
        return(res);
}
int contar_pares_posicion(struct lista *&com){	
	int res;
    int i=1;
    struct lista *p = com;
    res = 0;
    while(p != NULL){
    	p = p->sig;
        if(p != NULL){
            p = p->sig;
            res++;
        }
    }
    return(res);        
}
    
int contar_pares_posicion_rec(struct lista *&com){
        int res;
        if(com != NULL){
            com = com->sig;
            if(com != NULL){
              res = 1 + contar_pares_posicion_rec(com->sig);
            }else{
              res = 0;
            }   
        }else{
            res = 0;
        }
        return(res);
}

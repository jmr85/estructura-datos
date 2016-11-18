/*
1. Cargar una lista simplemente enlazada con nros que se lean. La carga se detiene con el primer par que aparezca.
2. Mostrar recursivamente una  LSE, en forma recursiva, solo los contenidos pares.
3. Dada una LSE eliminar el 1er y el ultimo nodo.
4. Dada una LSE, se pide agregar un nro en el 1er y en el ultimo lugar.
*/

#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" //Libreria propia de lectura

struct lista{
    int num;
    struct lista *sig;
};

void crear_lista(struct lista *&com);//OK
void crear_lista_val_par(struct lista *&com);
void mostrar_lista(struct lista *&com);//OK
void cargar_lista_par(struct lista *&com);//1 OK
void mostrar_lista_pares_rec(struct lista *&com);//2 OK
void eliminar_primer_y_ultimo(struct lista *&com);//3
void agregar_primer_y_ultimo(struct lista *&com);//4
int cuenta_pares(struct lista *com);//OK - (ejer 16 del TP 3)


int main (void){
   struct lista *com;
   //struct lista *com2;
   
   crear_lista_val_par(com);
   
   printf("\n***** todos los nodos ******\n");//OK
   mostrar_lista(com);
  
   /*printf("\n***** muestra contenidos pares ******\n");//OK
   mostrar_lista_pares_rec(com);
   
   /*printf("\n***** cargar nodo, se detiene con el primer par que aparezca ******\n");//OK
   cargar_lista_par(com2);
   
   printf("\n***** todos los nodos ******\n");
   mostrar_lista(com2);*/
   
    printf("\nCantidad de pares: -- %d --\n", cuenta_pares(com));
   printf("\n***** elimina primero y ultimo ******\n");
   eliminar_primer_y_ultimo(com);
   
   mostrar_lista(com);
   
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
void crear_lista_val_par(struct lista *&com){
    struct lista *p;
    struct lista *ant;
    int n;	
    printf("Ingrese numero al Nodo: ");
    scanf("%d", &n);
    if(n == 0){//lista vacia
        com = NULL;
    }else{
        com = new struct lista;
        if(n % 2 == 0){
        	com->num = n;
		}
        com->sig = NULL;
        ant = com; //apuntan al mismo
        while(n != 0){
            p = new struct lista;
            if(n % 2 == 0){
        	    com->num = n;
		    }
            ant->sig = p; 
            p->sig = NULL;
            ant = p;
            printf("Ingrese otro numero al Nodo: ");
            scanf("%d", &n);
        }
        
    } 
}
void mostrar_lista(struct lista *&com){
    struct lista *p;
    p = com;
    while(p != NULL){
        printf("\n Nodo->num: %d\n\n", p->num);
        p = p->sig;
    }
}
//1 OK
void cargar_lista_par(struct lista *&com){
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
        while(n % 2 != 0){
            p = new struct lista;
            p->num = n;
            ant->sig = p; 
            p->sig = NULL;
            ant = p;
            pedir_nro(n);
        }
        
    } 
    
}
//2 OK
void mostrar_lista_pares_rec(struct lista *&com){
    struct lista *p;
    p = com;
    if(p != NULL){
        if(p->num % 2 == 0){
            printf("%d\n\n", p->num);
        }
        mostrar_lista_pares_rec(p->sig);
    }
}
//3)
void eliminar_primer_y_ultimo(struct lista *&com){
    struct lista *p, *ant, *aux;
    int i=1;
    p = com;
    ant = new struct lista;
    aux = new struct lista;
    while(p != NULL){
    	
        if(i==1){
            ant->sig = com->sig;
            delete(com);
        }
        
        if(p->sig == NULL){
        	ant = p;
            delete(p);
            ant->sig = NULL;
        }
    	if(p != NULL){
    		p = p->sig;
		}
    
    }
    
   /* struct lista *p, *ant, *aux;
    int i=1;	
    p = com;
    ant = p;
    aux = new struct lista;
    while( p != NULL){
        if(i == 1){
             delete(p);
             ant = com;
        }
        if(ant->sig == NULL){
            ant = p;
            aux->sig = ant->sig;
	    delete(ant);	
        }
	p = p->sig;
	*/
}
//4)
void agregar_primer_y_ultimo(struct lista *&com){
    struct lista *p;
    int i=1, n;
    p = com;
    while(p != NULL){

        if(i==1){
            pedir_nro(n);
            p->num=n;
        }
        if(p->sig == NULL){
             pedir_nro(n);
             p->num=n;
        }
        p = p->sig;
    }
}
int cuenta_pares(struct lista *com){
        int res = 0;
        struct lista *p;
        p = com;
        while(p != NULL){
                if(p->num % 2 == 0){
                     res++;
                }
            p = p->sig;
        }
        return(res);
}  


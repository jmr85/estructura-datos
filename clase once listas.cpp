
#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" //Libreria propia de lectura

struct lista{
    int num;
    struct lista *sig;
};

void crear_lista(struct lista *&com);//OK
void cargar_recursivo(struct lista *&com);//OK - (ejer 19 del TP 3)
void mostrar_lista(struct lista *&com);//OK
void mostrar_lista_impares(struct lista *&com);//OK - muestra valores impares
void mostrar_lista_impares_rec(struct lista *&com);//OK - muestra valores impares
int suma_pos_impar(struct lista *com);//OK - suma de los valores de las posiciones impares (ejer 22 del TP 3)
int suma_valor_impar(struct lista *com);//OK - suma de los valores impares (ejer 21 del TP 3)
void mostrar_pos_impar(struct lista *&com);//OK - muestra valores de las posiciones impares
void eliminar(struct lista *&com, int n);//OK - elimina NODO segun el valor de dicho nodo (ejer 14 del TP 3)
//20) Codificar  un procedimiento que reciba una  lista simplemente encadenada  y si se puede intercambiar el primero con el último elemento.
void inter_primer_ultimo(struct lista *&com);//OK - intercambio de valores entre nodos(ejer 20 del TP 3)

int main (void){
   struct lista *com;
   int n;
   
   cargar_recursivo(com);//OK
   printf("\n***** todos los nodos ******\n");
   mostrar_lista(com);
   /*printf("\n***** valores impares  ******\n");
   mostrar_lista_impares(com);
   printf("\n***** (recursivo) valores impares  ******\n");
   mostrar_lista_impares_rec(com);
	   
   printf("\n** suma de los valores de las posiciones impares **\n");
   printf("\n -- %d -- \n", suma_pos_impar(com));
   
   printf("\n** suma de los valores impares **\n");
   printf("\n -- %d -- \n", suma_valor_impar(com));
   
   printf("\n** muestra valores de las posiciones impares **\n");
   mostrar_pos_impar(com);
   
   
   mostrar_lista(com);
   */
   printf("\n** eliminar un valor **\n");
   pedir_nro(n);
   eliminar(com, n);//OK
   mostrar_lista(com);
   
   
   printf("\n** intercambio valor primero con el ultimo **\n");
   inter_primer_ultimo(com);//OK
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
void cargar_recursivo(struct lista *&com){
    int n;
    printf("Ingrese valor al nodo: ");
    scanf("%d", &n);
    if(n == 0){
        com = NULL;
    }else{
        com = new struct lista;
        com->num = n;
        com->sig = NULL;
        if(n != 0){
            cargar_recursivo(com->sig);
        }
        
    } 
}
void mostrar_lista(struct lista *&com){
    struct lista *p;
    p = com;
    while(p != NULL){
        printf("\n Nodo->num: %d\n", p->num);
        p = p->sig;
    }
}
void mostrar_lista_impares(struct lista *&com){
    struct lista *p;
    p = com;
    while(p != NULL){
        if(p->num % 2 != 0){
            printf("%d\n\n", p->num);
        }
        p = p->sig;
    }
}
void mostrar_lista_impares_rec(struct lista *&com){
    struct lista *p;
    p = com;
    if(p != NULL){
        if(p->num % 2 != 0){
            printf("%d\n\n", p->num);
        }
        mostrar_lista_impares_rec(p->sig);
    }
}
// suma de los valores que se encuentren en las posiciones impares
int suma_pos_impar(struct lista *com){
        int res = 0;
        struct lista *p;
        p = com;
        while(p != NULL){
            res += p->num;
            p = p->sig;
            if(p != NULL){
                p = p->sig;    
            }
        }
        return(res);
}
// suma de los valores impares (ejer 21 del TP 3)
int suma_valor_impar(struct lista *com){
	    int res = 0;
        struct lista *p;
        p = com;
        while(p != NULL){
        	if(p->num % 2 != 0){
        		res += p->num;
			}
            p = p->sig;
        }
        return(res);
}    
    // muestra valores de las posiciones impares
void mostrar_pos_impar(struct lista *&com){
        struct lista *p;
        p = com;
        while(p != NULL){
            printf("\n %d\n\n", p->num);
            p = p->sig;
            if(p != NULL){
                p = p->sig;
            }
  }
}
void eliminar(struct lista *&com, int n){
    struct lista *p, *ant;
    p = com;
    ant = p;
    while( p != NULL){
        if(p->num == n){// es el primero hay 1 o muchos
            if(com == p){
                com = com->sig;
                delete(p);
                p = com;
                ant = p;
            }else{// medio o ultimo
                ant->sig = p->sig;
                delete(p);
                p = ant->sig;
            }
        }else{
            ant = p;
            p = p->sig; // si p->num != n viene aca para p->sig
        }
    }
}
void inter_primer_ultimo(struct lista *&com){
	struct lista *p;
	int aux;
    p = com;
    while(p != NULL){
		if(p->sig == NULL){
			aux = com->num;
			com->num = p->num;
        	p->num = aux;	
		}
        p = p->sig;
    }
}

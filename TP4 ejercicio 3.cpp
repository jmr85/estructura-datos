#include<stdio.h>
#include<stdlib.h>

/*3) Un procedimiento para insertar en un árbol un nro entero que no debe existir en el mismo. 
    void insertar _arbol (struct árbol *&raíz, int n).*/

struct arbol{
    int num;
    struct arbol *izq;
    struct arbol *der;
};

void pedir_nro(int &a);
void crear_arbol(struct arbol *&r);
int esta_en_arbol(struct arbol *r, int n); 
void insertar_en_arbol(struct arbol *&r, int n);

int main(void){
   int n, i;
   struct arbol *raiz;
   crear_arbol(raiz);
   printf("\nIngresar elementos\n");
	
    for(i=1;i<=4;i++){
       pedir_nro(n);                 
       if(esta_en_arbol(raiz, n)==0){
           insertar_en_arbol(raiz, n);
       }else{
            printf("\nEsta repetido\n");
       }
    }		

   system("pause");
   return(0);
}
void pedir_nro(int &a){
  printf("\n Ingrese numero: ");
  scanf("%d", &a);
}
void crear_arbol(struct arbol *&r){
    r = NULL;
}
int esta_en_arbol(struct arbol *r, int n){
    int res = 0;
    struct arbol *p = r;
    while(p != NULL && res == 0){
        if(p->num == n){
            res = 1;
        }else{
            if(n > p->num){
                p = p->der;
            }else{
                p = p->izq;
            }
        }
    }
    return(res);
}
void insertar_en_arbol(struct arbol *&r, int n){
    struct arbol *p, *ant, *nuevo;
    p = r;
    ant = r;
    nuevo = new struct arbol;
    nuevo->num = n;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    while(p != NULL){
        ant = p;
        if(p->num < n){
            p = p->der;
        }else{
            p = p->izq;
        }
    }
    if(r != NULL){
        if(ant->num < n){
            ant->der = nuevo;
        }else{
            ant->izq = nuevo;
        }
    }else{
        r = nuevo;
    }
}

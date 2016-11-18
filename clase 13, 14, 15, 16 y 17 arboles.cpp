#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" //Libreria propia de lectura

/*Un ARBOL guarda una estructura de datos ordenada, descartando izq o der, 
en cambio una LISTA es secuencial. Se usa de fondo 
para guardar el id (o PK) de las bases de datos.*/

struct arbol{
    int num;
    struct arbol *izq;//menor
    struct arbol *der;//mayor
};

//& lo devuelve, sin eso (solo *) es porque retorna un int o no hace falta return como en eliminar o no muestra valor actual Nodo
void crear_arbol(struct arbol *&r);//ejer hecho en clase
int esta_en_arbol(struct arbol *r, int n);//ejer hecho en clase 
void insertar_en_arbol(struct arbol *&r, int n);
void recorrer(struct arbol *r);//tendria que ser como RID
void recorrer_2(struct arbol *r);//igual que DRI, mayor a menor
void recorrer_arbol_dri(struct arbol *r);//ordenado mayor a menor
void recorrer_arbol_ird(struct arbol *r);//ordenado menor a mayor
void recorrer_arbol_rdi(struct arbol *r);//raiz, der, izq
void recorrer_arbol_rid(struct arbol *r);//raiz, izq, der
void recorrer_arbol_idr(struct arbol *r);//izq, der, raiz
void recorrer_arbol_dir(struct arbol *r);//der, izq, raiz
void eliminar_arbol(struct arbol *&r, int n);//primero buscar y luego eliminar, depende de la funcion borrar_delarbol() de abajo
void borrar_delarbol(struct arbol *&r, struct arbol *p, struct arbol *ant, int n);//depende de las funciones borrar_nodo_hoja(),borrar_nodo_un_hijo(),borrar_nodo_dos_hijos()
void borrar_nodo_hoja(struct arbol *&r, struct arbol *p, struct arbol *ant, int n);//solo r lleva &, siempre devuelve nodo raiz
void borrar_nodo_un_hijo(struct arbol *&r, struct arbol *p, struct arbol *ant, int n);
void borrar_nodo_dos_hijos(struct arbol *&r, struct arbol *p, struct arbol *ant, int n);
int nivel_arbol(struct arbol *r, int n);//OK
int nivel_arbol_rec(struct arbol *r, int n);//OK

int main(void){
   struct arbol *raiz;
   int n, i;
   crear_arbol(raiz);//OK
   for(i=1;i<=14;i++){
       pedir_nro(n);                 
       if(esta_en_arbol(raiz, n)==0){//Si no esta, no puede estar repetido
           insertar_en_arbol(raiz, n);//OK
       }else{
            printf("\nEsta repetido\n");
       }
    }
   
   printf("\n\nIRD (Menor a Mayor): ");
   recorrer_arbol_ird(raiz);
   printf("\n\nDRI (Mayor a Menor): ");
   recorrer_arbol_dri(raiz);
   printf("\n\nRDI (Raiz, Der, Izq): ");
   recorrer_arbol_rdi(raiz);
   printf("\n\nRID (Raiz, Izq, Der): ");
   recorrer_arbol_rid(raiz);
   printf("\n\nIDR (Izq, Der, Raiz): ");
   recorrer_arbol_idr(raiz);
   printf("\n\nDIR (Der, Izq, Raiz): ");
   recorrer_arbol_dir(raiz);
   
   printf("\n\nNivel elemento\n"); 
   pedir_nro(n);
   if (esta_en_arbol(raiz,n)==1)
   {
     printf("\nNIVEL DEL ARBOL EN QUE SE ENCUENTRA EL NUMERO BUSCADO: %d\n", nivel_arbol_rec(raiz, n));//OK
     printf("\nNIVEL DEL ARBOL EN QUE SE ENCUENTRA EL NUMERO BUSCADO: %d\n", nivel_arbol(raiz, n));//OK
   }
   else
     printf("\nNo se pude calculaR NIVEL DE UN NODO QUE NO EXXISTE\n");
     
   printf("\nEliminar elemento\n");
   pedir_nro(n);
   if(esta_en_arbol(raiz, n)==1){//esta
        eliminar_arbol(raiz, n);//OK
   }else{
         printf("NO existe");
   }
   printf("\n\nIRD (Menor a Mayor): ");
   recorrer_arbol_ird(raiz);
   printf("\n\nDRI (Mayor a Menor): ");
   recorrer_arbol_dri(raiz);
   
   system("pause");
   return(0);
}
void crear_arbol(struct arbol *&r){
    r = NULL;
}
int esta_en_arbol(struct arbol *r, int n){
    int res = 0;
    struct arbol *p = r;
    while(p != NULL && res == 0){// 0 si lo encontro
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
void recorrer(struct arbol *r){//tendria que ser como RID
   	if(r != NULL){
        printf("%d ", r->num);
        recorrer_arbol_ird(r->izq);
		recorrer_arbol_ird(r->der);
    }
}
void recorrer_2(struct arbol *r){//lo mismo que DRI
    if(r != NULL){
        recorrer(r->der);//3
        printf("%d ", r->num);//1
        recorrer(r->izq);//2
    }
}
void recorrer_arbol_dri(struct arbol *r){//Ordenado mayor a menor
    if(r != NULL){
        recorrer_arbol_dri(r->der);
        printf("%d ", r->num);
        recorrer_arbol_dri(r->izq);
    }                    
}
void recorrer_arbol_ird(struct arbol *r){//Ordenado menor a mayor
    if(r != NULL){
        recorrer_arbol_ird(r->izq);
        printf("%d ", r->num);
        recorrer_arbol_ird(r->der);
    }
}
void recorrer_arbol_rdi(struct arbol *r){//recorre raiz, der, izq
	if(r != NULL){
        printf("%d ", r->num);
        recorrer_arbol_ird(r->der);
		recorrer_arbol_ird(r->izq);
    }
}
void recorrer_arbol_rid(struct arbol *r){//recorre raiz, izq, der
	if(r != NULL){
        printf("%d ", r->num);
        recorrer_arbol_ird(r->izq);
		recorrer_arbol_ird(r->der);
    }
}
void recorrer_arbol_idr(struct arbol *r){//recorre izq, der, raiz
	if(r != NULL){
        recorrer_arbol_ird(r->izq);
		recorrer_arbol_ird(r->der);
		printf("%d ", r->num);
    }
}
void recorrer_arbol_dir(struct arbol *r){//der, izq, raiz
	if(r != NULL){
        recorrer_arbol_ird(r->der);
		recorrer_arbol_ird(r->izq);
		printf("%d ", r->num);
    }
}
//llenar hasta q encuentre nulo y enlazar
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
        r = nuevo;//enlaza si el nodo de entrada es vacio o nulo o NULL
    }
}

void eliminar_arbol(struct arbol *&r, int n){
    struct arbol *p, *ant;
    p = r;
    ant = p;
    while(p->num != n){
        if(n > p->num){
            p = p->der;
        }else{
            p = p->izq;
        }
    }
    borrar_delarbol(r, p, ant, n);
}
void borrar_delarbol(struct arbol *&r, struct arbol *p, struct arbol *ant, int n){
    if(p->izq == NULL && p->der == NULL){
       borrar_nodo_hoja(r, p, ant, n);    
    }else{
       if(p->der !=NULL & p->izq != NULL){
           borrar_nodo_dos_hijos(r, p, ant, n);
       }else{
           borrar_nodo_un_hijo(r, p, ant, n);
       }
    }
}
void borrar_nodo_hoja(struct arbol *&r, struct arbol *p, struct arbol *ant, int n){//r es raiz, ant es padre de p
         if(p != r){   
               if(ant->num > p->num ){
                           ant->izq = NULL;
               }else{
                           ant->der = NULL;
               }        
               delete(p);
         }else{
               r = NULL;
               delete(p);
         }      
}
void borrar_nodo_un_hijo(struct arbol *&r, struct arbol *p, struct arbol *ant, int n){
  if(p != NULL){ 
     if(ant->izq == p){//padre lo apunta al hijo p por la izquierda
                 if(p->der != NULL){//1)hijo esta a la derecha
                         ant->izq = p->der;               
                 }else{
                         ant->izq = p->der;//2)hijo esta a la izq
                 }
     }else{//padre lo apunta por la derecha
           if(p->izq != NULL){
                ant->der = p->izq; //3)hijo por izquierda
           }else{
                 ant->der = p->der;//4)hijo por derecha      
           }
     }
      //delete(p);se deja para el final, es lo mismo
  }else{//p es raiz
        if(p->izq != NULL){
             r = p->izq;
        }else{
             r = p->der;
        }
        //delete(p); se deja para el final, es lo mismo
  }
  delete(p);   
}
void  borrar_nodo_dos_hijos(struct arbol *&r, struct arbol *p, struct arbol *ant, int n){
      struct arbol *i, *d, *anterior;//punt izq
      i = p->izq;//me movi un lugar a la izq
      d = i;
      anterior = d;
      while(d->der != NULL){
         anterior = d;
         d = d->der;
      }
      if(i->der != NULL){//sirve para cuando D no tiene hijo o tiene un solo izq
                p->num = d->num;//reemplazo
                anterior->der = d->izq;//enlace
      }else{
                p->num = i->num;//solo me puede correr un hijo a la izq
                p->izq = i->izq;
                delete(i);
      }
}
int nivel_arbol(struct arbol *r, int n){
	int res=0;
	while(r->num != n){
		if(n > r->num){
			r = r->der;
		}else{
			r = r->izq;
		}
		res++;
	}
	return(res);		      
}
int nivel_arbol_rec(struct arbol *r, int n){
	int res;
	if(r==NULL)
      res=0;
    else
       if(r->num != n)
	  	if(n > r->num)
		    res = 1 + nivel_arbol_rec(r->der, n);//siempre contar en el recursivo
		else
            res = 1 + nivel_arbol_rec(r->izq, n);
    else	
		res = 0;
	
	return(res);		      
}

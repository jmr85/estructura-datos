#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" //Libreria propia de lectura

struct lista{
    int num;
    struct lista *sig;
};

void leer_nro_nodo(int cant);
void otro_cargar_lista(struct lista *&com);
void crear_lista(struct lista *&com);
void mostrar_lista(struct lista *com);
void mostrar_lista_rec(struct lista *&com);
void insertar_atras(struct lista *&com, int n);//OK
void insertar_adelante(struct lista *&com, int n);//OK
void cargar_adelante_atras(struct lista *&com, int n);//OK (ejer 17 del TP 3)
void sacar_adelante_atras(struct lista *&com);//OK (ejer 18 del TP 3)
void eliminar_primero(struct lista *&com);//OK
void eliminar_ultimo(struct lista *&com);//OK
int cuantos_hay(struct lista *&com, int n);
int esta(struct lista *&com, int n);
int ordenado(struct lista *&com);
void ordenar(struct lista *&com);
void agregar_num_lista(struct lista *&com, int n);//OK - agrega valor ordenado (ejer 11 del TP 3)

int main (void){
   struct lista *com;
   crear_lista(com);
   /*agregar_num_lista(com, 5);//OK
   ordenar(com);//OK
   */
   //mostrar_lista_rec(com);
   //insertar_atras(com, 10);//OK
   //insertar_adelante(com, 10);//OK
   cargar_adelante_atras(com, 10);//OK
   mostrar_lista_rec(com);
   sacar_adelante_atras(com);
   mostrar_lista_rec(com);
   
   /*struct lista *com2;
   int n;
   
   /*crear_lista(com);
   printf("\n***** todos los nodos ******\n");
   mostrar_lista_rec(com);
  /* 
   printf("\n***** Si se encuentra el valor en la lista ******\n");
   pedir_nro(n);
   esta(com, n) ? printf("\n SI esta el valor \n") : printf("\n NO esta el valor \n");
   printf("\n***** CUANTOS hay del valor ingresado ******\n");
   printf("\n %d\n", cuantos_hay(com, n));
  
   printf("\n***** elimina el ultimo nodo ******\n");
   eliminar_ultimo(com);//OK
   mostrar_lista_rec(com);
   printf("\n***** elimina el primer nodo ******\n\n");
   eliminar_primero(com);//OK
   mostrar_lista_rec(com);
   /*                       
   printf("\n***** insertar atras ******\n");
   pedir_nro(n);
   insertar_atras(com, n);
   mostrar_lista_rec(com);
   printf("\n***** insertar adelante ******\n");
   pedir_nro(n);
   insertar_adelante(com, n);
   mostrar_lista_rec(com);
  */
   
  /* printf("\n***** Lista ordenada? ******\n");
   ordenado(com) ? printf("\n SI esta ordenada \n\n") : printf("\n NO esta ordenada \n\n");
   
   printf("\n***** Lista ordenada ******\n");
   ordenar(com);
   mostrar_lista_rec(com);
   
   /*printf("\n***** Lista ordenada? ******\n");
   ordenado(com) ? printf("\n SI esta ordenada \n\n") : printf("\n NO esta ordenada \n\n");
   */
   
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
void mostrar_lista(struct lista *com){
    struct lista *p;
    p = com;
    while(p != NULL){
        printf("\n Nodo->num: %d\n", com->num);
        p = p->sig;
    }
}
void mostrar_lista_rec(struct lista *&com){
    if(com != NULL){
        printf("\n Nodo->num: %d\n", com->num);
        mostrar_lista_rec(com->sig);
    }
}

void insertar_adelante(struct lista *&com, int n){
    struct lista *nuevo, *aux; 
    
	nuevo = new struct lista;
    nuevo->num = n;
    nuevo->sig = NULL;
    
    if(com == NULL){
        com = nuevo;
    }else{
    	aux = com;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}
void leer_nro_nodo(int cant){
    printf("\n Ingrese cantidad de nodos: ");
    scanf("%d", &cant);
}
void otro_cargar_lista(struct lista *&com){
    int a, cant, i;
    struct lista *p;
    struct lista *ant;
    leer_nro_nodo(cant);
    if(cant == 0){
        com = NULL;
    }else{
        com = new struct lista;
        pedir_nro(a);
        com->num = a;
        com->sig = NULL;
        ant = com;
        for(i=2; i<=cant;i++){
            p = new struct lista;
            pedir_nro(a);
            p->num = a;
            p->sig = NULL;
            ant->sig = p;
            ant = p;    
        }    
    }
}
void insertar_atras(struct lista *&com, int n){
    struct lista *nuevo, *p;
    p = com;
    
    nuevo = new struct lista;
    nuevo->num = n;
    nuevo->sig= p;
    p = nuevo;
    com = p;
}
/*17) Codificar  un procedimiento cargar_adelante_atras que reciba una
 lista simplemente encadenada (cargada o nula) y 
un nro entero y devuelva la lista con dicho nro insertado adelante y atrás de la lista.*/
void cargar_adelante_atras(struct lista *&com, int n){
	insertar_atras(com, n);
	insertar_adelante(com, n);
}
/*18) Codificar  un procedimiento sacar_adelante_atras que reciba una lista
 simplemente encadenada (cargada o nula) y devuelva la lista sin el primer y ultimo nro.*/
void sacar_adelante_atras(struct lista *&com){
	eliminar_primero(com);
	eliminar_ultimo(com);
} 
void eliminar_primero(struct lista *&com){
    struct lista *aux;
    if(com != NULL){
        aux = com;
        com = com->sig;
        delete(aux);
    }    
}
//Hacer void sacar ultimo
void eliminar_ultimo(struct lista *&com){
    struct lista *ant, *ult;
    if(com != NULL){
        ult = com;
        ant = ult;
        while(ult->sig != NULL){
            ant = ult;
            ult = ult->sig;
        }
    }
    if(com != ult){
        delete(ult);
        ant->sig = NULL;
    }else{
        delete(com);
        com = NULL;
    }
}
//cuenta la cantidad del valor ingresado
int cuantos_hay(struct lista *&com, int n){
    int res=0;
    struct lista *p;
    p = com;
    while(p != NULL){
        if(p->num == n){
            res++;
        }
        p = p->sig;
    }
    return(res);
}

/**** Se fija solo si el valor esta ****/
/*
  condicion de corte
  (p->num==n || p== NULL)
  (p->num != n && p != NULL)
  (p != NULL && res == 0)
*/
int esta(struct lista *&com, int n){
    int res=0;
    struct lista *p;
    p = com;
    while(p != NULL && res == 0){
        if(p->num == n){
            res = 1;
        }
        p = p->sig;
    }
    return(res);
}

/**** 1 si esta ordenado, si no retorna 0 ****/
int ordenado(struct lista *&com){
    int res=1;
    struct lista *p;
    struct lista *q;
    p = com;
    
    while(p != NULL && res == 1){
        q = p->sig;
        if(q != NULL){
            if(q->num < p->num){
                res = 0;
            }
         }   
        p = p->sig;
    }
    return(res);
}

/**** ordena la lista ****/
void ordenar(struct lista *&com){
    int aux;
	struct lista *f, *m;
    f = com;
    m = f;
    // intercambio entre dos variables va con auxiliar
    while(f != NULL){
        m = f->sig;//movil quedaria adelante de fijo
        while(m != NULL){
            if(m->num < f->num){
                aux = f->num;
                f->num = m->num;
                m->num = aux;
            }
            m = m->sig;
        } 
        f = f->sig;  
    }
}
/* 11) Dada una lista simplemente encadenada con valor ordenados de menor a mayor y un valor entero insertarlo en el lugar 
que le corresponda para que la lista continúe ordenada . Usar un procedimiento. */
void agregar_num_lista(struct lista *&com, int n){//OK
    struct lista *nuevo, *p, *ant;
    
    nuevo = new struct lista;
    nuevo->num = n;
    nuevo->sig = NULL;
    
	p=com;
	
	while((p != NULL) && (p->num <= n)){
		ant = p;
		p = p->sig;
	}
	if(ant == NULL){
		com = nuevo;
	}else{
		ant->sig = nuevo;
	}
	nuevo->sig = p;
	/*if(com->sig == NULL){
        com->sig = nuevo;
    }else{
        while(com != NULL){
            com = com->sig;
            if(com->sig == NULL){
                com->sig = nuevo;
            }
        }
        com->sig = nuevo;
    }
    
	/*while(p != NULL){
        if(nuevo->num  == com->num){
            com->sig = nuevo;
        }
		if(nuevo->num  > p->num){
            nuevo->sig = p->sig;
        }else{
        	p->sig = nuevo->sig;
		} 		
        p = p->sig;  
    }*/
}

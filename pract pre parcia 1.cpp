#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "lect_lib.h"

int producto(int a, int b);//OK
void suma(int a, int b, int &sum);//OK
void sumar(int a, int  &b);//OK
void product(int a, int b);//OK
int div_suces(int a, int b);//OK
void div_suces_proce(int coc, int div, int &res);//OK
int pot(int a, int b);
int mayor(int a, int b);//OK
void menor(int a, int b);//OK
int ordenado(int a, int b);
int siguiente(int a);//OK
int anterior(int a);//OK
void ant_sig(int a);
void ant_sig2(int a, int &ant, int &sig);
int par(int n);
void pares(int n);

int main (void){
    //int a,b,sum;
    //int a, ant, sig;
    
    /*
	pedir_nros(a,b);
    printf("El producto a es: %d\n", producto(a,b));//funcion OK
    product(a,b);//procedimiento OK
    
    
    pedir_nros(a,b);
    printf("El mayor es: %d\n", mayor(a,b));//OK
    menor(a,b);//OK
    printf("-> \n %d\n", ordenado(a,b));//OK
    
    pedir_nro(a);
    printf("El siguiente de %d es: %d\n", a, siguiente(a));//OK
    printf("El anterior de %d es: %d\n", a, anterior(a));//OK
    ant_sig(a);
    
    pedir_nros(a,b);
    suma(a,b,sum);//OK
    printf("La suma es: %d", sum);//OK
    
    pedir_nro(a);
    ant_sig2(a, ant, sig);
    printf("\n El anterior es %d", ant);//OK
    printf("\n El siguiente es %d \n", sig);//OK
    
    
    int a,b, res;
    pedir_nros(a,b);
    printf("La division por resta sucesivas es: %d\n", div_suces(a,b));//funcion OK
    div_suces_proce(a,b,res);//procedimiento OK
    printf("\n (Proc)La division por resta sucesivas es: %d\n", res);// OK
    
    int a,b;
    pedir_nros(a,b);
    printf("La potencia de %d es: %d\n",a, pot(a,b));//funcion OK
    sumar(a,b);//procedimiento OK
    printf("La suma es: %d\n", b);//OK
    */
    int n;
    pares(n);
    
    system("pause");
    return(0);
}

int producto(int a, int b){
     int pro=0;
     int i;
     for(i=1; i<=b;i++){
         pro += a;
     }
     if(b<0){
        pro *= -1; 
     }
     return(pro);
}
void product(int a, int b){
     int pro=0;
     int i;
     for(i=1; i<=b;i++){
         pro += a;
     }
     if(b<0){
        pro *= -1; 
     }
     printf("\n El producto es: %d\n", pro);
}
//14) Una función que reciba dos enteros y devuelva la división  de ambos por restas sucesivas. 
int div_suces(int coc, int div){
     int res=0;
     int aux = abs(coc);
     int i;
     while(aux >= abs(div)){
	 		aux -= abs(div);
	 		res++;
	 }
	 
     return(res);
}
//idem anterior pero con procedimiento
void div_suces_proce(int coc, int div, int &res){
     res=0;
     int aux = abs(coc);
     int i;
     while(aux >= abs(div)){
	 		aux -= abs(div);
	 		res++;
	 }
}
int pot(int base, int exp){
	int resul=base;
	int i;
	for(i=1;i<exp;i++){
			 resul *= base;
	}
	return(resul);
}
int mayor(int a, int b){
    return(a > b ? a: b);
}
void suma(int a, int b, int &sum){
	sum = a+b;
}
void sumar(int a, int  &b){
    b=a+b;
}
void menor(int a, int b){
    a < b ? printf("\n El menor es: %d \n", a): printf("\n El menor es: %d \n", b);
}
int ordenado(int a, int b){
    return(a < b || a == b ? 1: 0);
}
int siguiente(int a){
	return(a+1);
}
int anterior(int a){
	return(a-1);
}
void ant_sig(int a){
    printf("El anterior es: %d \n", anterior(a));
    printf("El siguiente es: %d", siguiente(a));		
}
void ant_sig2(int a, int &ant, int &sig){
    ant = anterior(a);
    sig = siguiente(a);		
}
int par(int n){
	return(n % 2 == 0 ? 1 : 0);
}
void pares(int n){
	abs(n);
	int sumPar=0;
	printf("Ingrese numero par: ");
	scanf("%d", &n);
	
	while(n != 0){
		if(par(n)){
			sumPar++;
		}
		printf("Ingrese numero par: ");
	    scanf("%d", &n);
	}
	printf("Cantidad de nros pares leidos: %d \n", sumPar);
}
void mayor_impares(int n){
	abs(n);
	int sumPar=0;
	printf("Ingrese numero impar: ");
	scanf("%d", &n);
	
	while(n != 0){
		if(!par(n)){
			sumPar++;
			
		}
		printf("Ingrese numero par: ");
	    scanf("%d", &n);
	}
	printf("Cantidad de nros pares leidos: %d \n", sumPar);
}





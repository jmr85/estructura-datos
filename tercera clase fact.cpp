#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h"

int factorial(int n);
int fact_rec(int n);
void mostrar_fact(int n);

int main (void){
    int a;
    
    pedir_nro(a);
    
    mostrar_fact(a);
    /*int j;
    int i;
    
    for(i=1;i<=5;i++){
    	pedir_nro(j);
    	printf("\n Factorial de %d es %d\n", j, fact_rec(j));	
	}*/
	
    
    system("pause");
    
    return(0);
}
int factorial(int n){
    int res = 1;
    int i;
    
    for(i=1; i<=n; i++){
        res = res * 1;        
    }
    return(res);                
}
int fact_rec(int n){
    int res;
    if(n==0){
             res=1;         
    }else{
          res = n * fact_rec(n-1);
    }
    return(res);      
}

/*******************************************/
void mostrar_fact(int n){
    if(n > 0){
        printf("\n Factorial %d = %d \n", n, fact_rec(n));
        mostrar_fact(n-1);
    }
}



    #include<stdio.h>
    #include<stdlib.h>
    #include "lect_lib.h" //Libreria propia de lectura
    
    int fibo(int subind);
    void mostrar_fibo(int n);
    int divi(int a, int b);
    
    int main (void){
       int x, y;
       
       pedir_nros(x, y);
       printf("El divi de %d y %d es: %d \n", x, y, divi(x,y));
       //mostrar_fibo(x); 
       
       system("pause");
       return(0);
    }
    int fibo(int subind){
        int i;
        int res;
        if(subind == 0){
            res = 1;
        }else{
             if(subind == 1){
                 res = 1;
             }else{
                 res = fibo(subind - 1) + fibo(subind - 2);
             } 
        }
        
        return(res);
    }
    /*
    5 -> 5 f5 8
         4 f4 5
         3 f3 3
         2 f2 2
         1 f1 1
         0 f0 1
    */
    void mostrar_fibo(int n){
        if(n >= 0){
            printf("\n Fibo %d = %d \n", n, fibo(n));
            mostrar_fibo(n-1);
        }
    }
    
    int divi(int a, int b){
        int res, auxa = abs(a);
        /********* parte mas importante *********/
        if(auxa >= abs(b)){
            res = 1 + divi(auxa - abs(b), b);
        }else{
            res = 0;
        }
        /*****************************************/
        if((a>0 && b<0) || (a<0 && b>0)){
            res= -res;
        }
        return(res);
    }


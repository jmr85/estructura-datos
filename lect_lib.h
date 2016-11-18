
/**
Libreria para ingresar datos por teclado
**/

void pedir_nro(int &a);
void pedir_nros(int &a, int &b);
void pedir_nro_float(float &a);
void pedir_nros_float(float &a, float &b);
void leer_no_negativo(int &a);

void pedir_nro(int &a)
{
  printf("\n Ingrese un numero: ");
  scanf("%d", &a);
}
void pedir_nros(int &a, int &b)
{
  printf("\n Ingrese un numero: ");
  scanf("%d", &a);
  printf("\n Ingrese segundo numero: ");
  scanf("%d", &b);
}
void pedir_nro_float(float &a)
{
  printf("\n Ingrese un numero: ");
  scanf("%f", &a);
}
void pedir_nros_float(float &a, float &b)
{
  printf("\n Ingrese un numero: ");
  scanf("%f", &a);
  printf("\n Ingrese segundo numero: ");
  scanf("%f", &b);
}
void leer_no_negativo(int &a){
     
     printf("\n Ingrese numero: ");
     scanf("%d", &a);

     while(a < 0){
              printf("\n es negativo, volver a ingresar: ");
              scanf("%d", &a);
     }
          
}

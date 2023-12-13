#include <assert.h>
#include <ctype.h>  // toupper
#include <math.h>   // sqrt
#include <stdio.h>  // scanf, printf
#include <string.h> // strcmp

#define MAX_PALABRA 32
#define MAX_LINEA 100

#define N 10000 // para la función primos

// Declaraciones de las funciones

/*
 precondición: 0 <= calN <= 10 para N en 1..N
*/
float promClase(int cal1, int cal2, int cal3, int cal4, int cal5);
void primos(int A, int B);
int ocurrencias(char frase[100], int largo, char letra);
bool esPalindrome(char *frase);
int * ordenar(int * A, int n);

int main() {
  char resto_linea[MAX_LINEA+1];

  int cont_comandos = 0;
  bool salir = false;
  while (!salir) {
    // mostrar el prompt
    cont_comandos++;
    printf("%u>", cont_comandos);

    // leer el comando
    char nom_comando[MAX_PALABRA];
    scanf("%s", nom_comando);

    // procesar el comando
    if (0 == strcmp(nom_comando, "Fin")) {
      salir = true;
      printf("Fin.\n");
      // comentario
    } else if (0 == strcmp(nom_comando, "#")) {
      scanf("%[^\n]", resto_linea);
      printf("# %s.\n", resto_linea);

      //------------- Inicio comandos

    } else if (0 == strcmp(nom_comando, "promClase")) {

      float prom;
      int cal1, cal2, cal3, cal4, cal5;
      printf("Ingrese las calificaciones: ");
      scanf("%d %d %d %d %d", &cal1, &cal2, &cal3, &cal4, &cal5);
      assert((0 <= cal1) && (cal1 <= 10) && (0 <= cal2) && (cal2 <= 10) &&
             (0 <= cal3) && (cal3 <= 10) && (0 <= cal4) && (cal4 <= 10) &&
             (0 <= cal5) && (cal5 <= 10));
      prom = promClase(cal1, cal2, cal3, cal4, cal5);
      printf("El promedio es %.2f \n", prom);

    } else if (0 == strcmp(nom_comando, "primos")) {

      printf("Ingrese dos enteros positivos, el segundo mayor o igual que el "
             "primero: \n");
      int A, B;
      scanf("%d %d", &A, &B);
      assert(A <= B);
      primos(A, B);

    } else if (0 == strcmp(nom_comando, "ocurrencias")) {

      char frase[100] = "Hoy es el día más hermoso de nuestra vida, querido "
                        "Sancho; los obstáculos más grandes ...";
      char letra = 'h';

      printf("La letra %c ocurre %d\n", letra,
             ocurrencias(frase, strlen(frase), letra));

    } else if (0 == strcmp(nom_comando, "esPalindrome")) {

      char *frase = new char[100];

      printf("Ingrese frase: ");
      scanf("%*c");
      scanf("%[^\n]s", frase);
      
      if (esPalindrome(frase))
        printf("La frase es Palindrome\n");
      else
        printf("La frase NO es Palindrome\n");

      delete[] frase;

    } else if (0 == strcmp(nom_comando, "ordenar")) {
      int A[10];
      printf("Ingrese 10 enteros: ");
      for (int i = 0; i < 10; i++)
	scanf("%d",&A[i]);
      int * B = ordenar(A,10);
      for (int i = 0; i < 10; i++)
	printf("%d ", B[i]);
      printf("\n");

      //------------- Fin comandos

    } else {
      printf("Comando no reconocido.\n");
    } // if
    fgets(resto_linea, MAX_LINEA + 1, stdin);
  } // while

  return 0;
}

// Implementación de las funciones

float promClase(int cal1, int cal2, int cal3, int cal4, int cal5) {
    int notas[5] = {cal1, cal2, cal3, cal4, cal5};
    int a_sumar[5];
    for (int i = 0; i == 3; i++) {
        if (notas[i] >= notas[i+1]) {
            a_sumar[i] = notas[i];
        } else {
            a_sumar[i] = notas[i+1];
        }
    }
    float suma = a_sumar[0] + a_sumar[1] + a_sumar[2] + a_sumar[3];
    return (suma/4);
};

void primos(int A, int B) {}

int ocurrencias(char frase[100], int largo, char letra) { return 0; }

bool esPalindrome(char *frase) { return false; }

int * ordenar(int * A, int n) {return NULL;} // violación de segmento





#include <stdio.h>  // scanf, printf

float promClase(int cal1, int cal2, int cal3, int cal4, int cal5);

int main() {
    int cal1, cal2, cal3, cal4, cal5;
    printf("Ingrese las calificaciones: ");
    scanf("%d %d %d %d %d", &cal1, &cal2, &cal3, &cal4, &cal5);
    float prom = promClase(cal1, cal2, cal3, cal4, cal5);
    printf("El promedio es %.2f\n", prom);
	return 0;
}

int min(int cal1, int cal2, int cal3, int cal4, int cal5) {
	int min = cal1;
	if (min > cal2) min = cal2;
	if (min > cal3) min = cal3;
	if (min > cal4) min = cal4;
	if (min > cal5) min = cal5;
	return min;
}

float promClase(int cal1, int cal2, int cal3, int cal4, int cal5) {
    float suma = cal1 + cal2 + cal3 + cal4 + cal5;
    int minimo = min(cal1, cal2, cal3, cal4, cal5);
    return ((suma-minimo)/4.0);
};


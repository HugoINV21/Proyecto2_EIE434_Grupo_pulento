#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Estructura del eslabón
typedef struct {
    int id;
    float x;
    float y;
} Eslabon;

// Función para generar posición inicial aleatoria
void generarPosicion(float *x, float *y) {
    *x = rand() % 361;  // Rango 0-360
    *y = rand() % 361;  // Rango 0-360
}

// Función para simular el auto-home
bool autoHome(Eslabon *e) {

    printf("\nIniciando Auto-Home del Eslabon %d\n", e->id);
    printf("Posicion inicial: X = %.0f, Y = %.0f\n", e->x, e->y);

    while (e->x > 0 || e->y > 0) {

        if (e->x > 0) {
            e->x--;
        }

        if (e->y > 0) {
            e->y--;
        }

        printf("Eslabon %d -> X = %.0f, Y = %.0f\n",
               e->id, e->x, e->y);
    }

    return (e->x == 0 && e->y == 0);
}

int main() {

    srand(time(NULL));

    // Definición obligatoria de los 4 eslabones
    Eslabon id1 = {1, 0, 0};
    Eslabon id2 = {2, 0, 0};
    Eslabon id3 = {3, 0, 0};
    Eslabon id4 = {4, 0, 0};

    // Generar posiciones iniciales
    generarPosicion(&id1.x, &id1.y);
    generarPosicion(&id2.x, &id2.y);
    generarPosicion(&id3.x, &id3.y);
    generarPosicion(&id4.x, &id4.y);

    printf("=====================================\n");
    printf("POSICIONES INICIALES DE LOS ESLABONES\n");
    printf("=====================================\n");

    printf("Eslabon %d -> X = %.0f, Y = %.0f\n",
           id1.id, id1.x, id1.y);

    printf("Eslabon %d -> X = %.0f, Y = %.0f\n",
           id2.id, id2.x, id2.y);

    printf("Eslabon %d -> X = %.0f, Y = %.0f\n",
           id3.id, id3.x, id3.y);

    printf("Eslabon %d -> X = %.0f, Y = %.0f\n",
           id4.id, id4.x, id4.y);

    printf("\n=====================================\n");
    printf("INICIO DEL PROCESO AUTO-HOME\n");
    printf("=====================================\n");

    bool estado1 = autoHome(&id1);
    bool estado2 = autoHome(&id2);
    bool estado3 = autoHome(&id3);
    bool estado4 = autoHome(&id4);

    if (estado1) {
        printf("\nEslabon 1 terminado\n");
    }

    if (estado2) {
        printf("Eslabon 2 terminado\n");
    }

    if (estado3) {
        printf("Eslabon 3 terminado\n");
    }

    if (estado4) {
        printf("Eslabon 4 terminado\n");
    }

    if (estado1 && estado2 && estado3 && estado4) {
        printf("Todos los eslabones realizaron auto-home correctamente.\n");
    }

    return 0;
}
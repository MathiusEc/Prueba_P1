/*Prueba*/
/*Se desea desarrolar un programam que me permita conocer el ganador de un torneo de box con 6 participantes, la prijera etapa son llaves preestablecidas
1vs2, 3vs4, 5vs6.

La segunda etapa sera la final entre aquellos que alcanzen los 2 mejores puntajes

los púntos se asignan asi: ganador 1 punto, por KO por 3 puntos

Ingreasr nombres de competidores y validar entradas*/

#include <stdio.h>
#include <string.h>

#define MAX_COMPETIDORES 6
#define llaves 3

void ingresarNombres(char nombres[][30], int n);
void resultados(char nombres[MAX_COMPETIDORES][30], int ganador[llaves], int sigRonda[MAX_COMPETIDORES]);
void finalistas(char nombres[MAX_COMPETIDORES][30], int sigRonda[MAX_COMPETIDORES], int ganador[llaves]);
void granFinal(char nombres[MAX_COMPETIDORES][30], int ganador[llaves]);

int main(int argc, char *argv[])
{
    char nombres[MAX_COMPETIDORES][30];
    int ganador[llaves] = {1, 2, 3};
    int sigRonda[MAX_COMPETIDORES] = {0};

    ingresarNombres(nombres, MAX_COMPETIDORES);
    printf("\n");
    resultados(nombres, ganador, sigRonda);
    printf("\n");
    finalistas(nombres, sigRonda, ganador);
    printf("\n");
    granFinal(nombres, ganador);
    return 0;
}

void ingresarNombres(char nombres[][30], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el nombre del competidor %d: ", i);
        fflush(stdin);
        fgets(nombres[i], 30, stdin);
        int len = strlen(nombres[i]) - 1;
        nombres[i][len] = '\0'; // Eliminar el salto de línea

        if (strlen(nombres[i]) == 0)
        {
            printf("Error: Nombre de competidor no puede estar vacio. Intentelo de nuevo.\n");
            i--; // Decrementar i para repetir la entrada
        }
    }
}

void resultados(char nombres[MAX_COMPETIDORES][30], int ganador[llaves], int sigRonda[MAX_COMPETIDORES])
{
    int puntos, opc, val;
    int resu;
    int combates[3][2] = {{0, 1}, {2, 3}, {4, 5}};

    for (int i = 0; i < llaves; i++)
    {
        int a = combates[i][0];
        int b = combates[i][1];

        printf("Ingrese quien gano entre %s y %s\n", nombres[a], nombres[b]);
        printf("1. Para %s\n", nombres[a]);
        printf("2. Para %s\n", nombres[b]);
        printf(">> ");

        do
        {
            val = scanf("%d", &resu);
            if ((resu != 1 && resu != 2) || val != 1)
            {
                printf("Entrada no valida. Por favor ingrese 1 o 2.\n");
                fflush(stdin);
            }
        } while ((resu != 1 && resu != 2) || val != 1);

        printf("Cuntos puntos gano?\n>> ");
        do
        {
            val = scanf("%d", &opc);
            if (val != 1 || opc < 1)
            {
                printf("Error, ingrese un numero valido mayor que 0.\n");
                fflush(stdin);
            }
        } while (val != 1 || opc < 1);

        if (resu == 1)
        {
            sigRonda[a] += opc;
            ganador[i] = a;  // Guardar el índice del ganador
        }
        else
        {
            sigRonda[b] += opc;
            ganador[i] = b;  // Guardar el índice del ganador
        }
    }
}


void finalistas(char nombres[MAX_COMPETIDORES][30], int sigRonda[MAX_COMPETIDORES], int ganador[llaves])
{
    for (int i = 0; i < llaves - 1; i++)
    {
        for (int j = 0; j < llaves - i - 1; j++)
        {
            int p1 = ganador[j];
            int p2 = ganador[j + 1];

            if (sigRonda[p1] < sigRonda[p2] ||
               (sigRonda[p1] == sigRonda[p2] && p1 > p2))
            {
                int temp = ganador[j];
                ganador[j] = ganador[j + 1];
                ganador[j + 1] = temp;
            }
        }
    }

    printf("Los finalistas son:\n");
    printf("1. %s con %d puntos\n", nombres[ganador[0]], sigRonda[ganador[0]]);
    printf("2. %s con %d puntos\n", nombres[ganador[1]], sigRonda[ganador[1]]);
}

void granFinal(char nombres[MAX_COMPETIDORES][30], int ganador[llaves])
{
    int resu, val;
    int finalista1 = ganador[0];
    int finalista2 = ganador[1];

    do
    {
        printf("Ingrese quien gano entre %s y %s\n", nombres[finalista1], nombres[finalista2]);
        printf("1. Para %s\n", nombres[finalista1]);
        printf("2. Para %s\n", nombres[finalista2]);
        printf(">> ");

        fflush(stdin);
        val = scanf("%d", &resu);

        if ((resu != 1 && resu != 2) || val != 1)
        {
            printf("Entrada no valida. Intente de nuevo.\n");
        }
    } while (resu != 1 && resu != 2);

    if (resu == 1)
    {
        printf("Felicidades %s, ganaste el torneo!\n", nombres[finalista1]);
    }
    else
    {
        printf("Felicidades %s, ganaste el torneo!\n", nombres[finalista2]);
    }
}    


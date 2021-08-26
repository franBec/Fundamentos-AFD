//Materia: Fundamentos de la Computación
//Autor: Franco Becvort
//Año: 2021

#include<stdio.h>
#include<stdlib.h>

int afd[6][2] =
{
            /*a,b*/
    /*Q0*/  {1,4},
    /*Q1*/  {2,5},
    /*Q2*/  {0,3},
    /*Q3*/  {4,2},
    /*Q4*/  {5,0},
    /*Q5*/  {3,1},
};

int finales[1] = {0};
char cadena[1025];

void lectura(){
    printf("A continuacion se ingresa la cadena de 'a' y 'b' a analizar\nIngresando un caracter por vez y apretando enter\nCuando no desee ingresar mas caracteres, ingrese punto ('.')\n");

    char c;
    short i = 0;

    while(c!='.'){
        fflush(stdin);
        scanf("%c",&c);

        if(c == 'a'|| c == 'b'){
            cadena[i] = c;
            i++;
        }

        else if(c == '.')
            cadena[i] = '\0';

        else{
            printf("Se ha ingresado un caracter que no pertenece al alfabeto... Saliendo del programa\n");
            system("pause");
            exit(0);
        }
    }
}

int ejecucion(){
    short i = 0;
    short estadoActual = 0;

    while(cadena[i] != '\0'){
        if(cadena[i] == 'a')
            estadoActual = afd[estadoActual][0];
        else
            estadoActual = afd[estadoActual][1];

        i++;
    }

    return estadoActual == finales[0];
}

void main(){
    lectura();
    if(ejecucion())
        printf("La cadena %s pertenece al lenguaje\n", cadena);

    else
        printf("La cadena %s no pertenece al lenguaje\n", cadena);
}

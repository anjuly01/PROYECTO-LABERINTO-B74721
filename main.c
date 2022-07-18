///Universidad de Costa Rica
/// Programaciòn Bajo Plataformas Abiertas-IE0117
/// Proyecto: Programar un resolvedor de laberintos en un entorno individual.
/// Estudiante: Angie Julissa Mèndez Ramìrez - B74721
/// Profesor: Juan Carlos Coto

///// Muestra de soluciones y datos del laberinto ///////

//Inclusiòn de archivo de la lògica del juego

#include "laberintoproyecto.h"

//Funciòn principal de todo el juego
int main(){
    //Se crea una variable de nombre "doc" que nos traer al...
    //...archivo "laberinto.txt" que vamos a estudiar.
    char doc[]="laberinto.txt";
    //Primero, imprimimos el nùmero de filas y columnas...
    //... mediante las funciones “traerFilastxt” y “traerColumnastxt”...
    // del documento que estàn en “recorrermatriz.h”
    printf("Matriz esta hecha de %d filas\n", traerFilastxt(doc));
    printf("Matriz  esta hecha de %d columnas\n" , traerColumnastxt(doc));
    //Imprime el laberinto desde “recorrermatriz.h”
    printf("El laberinto es el siguiente: \n");
    matrizprint(doc);
    // la solucion del laberinto:
    // con “travel” la funciòn que estaba en “laberintoproyecto.h”
    printf("La solucion del laberinto es la siguiente: \n");
    //1) si es 1 : encuentra la soluciòn (con el booleano):
    if(travel(doc)==1 ){
    //Caso I: si el contador de dos es 1: hay una soluciòn 
    if (contDeDos(doc)==1) {
        printf("\n");
        printf("Hay una solucion \n");
        coordSol(doc);
    //Caso II: el contador de dos me retorne algo distinto a “1” :...
    //... hay màs de un camino de “unos”, pero solo hay una solucion “2”
    }else{
        printf("\n");
        printf("Hay \"mas de una salida\" pero solo una solucion correcta\n");
        coordSol(doc);
    }
    //2) si el booleano nunca se fue a 1  y termina siendo 0:
    //...Nunca hay soluciòn, no encontrò ningùn "2"
    }else {
        printf("\n");
        printf("No hay solucion");
    }
    return 0;
}
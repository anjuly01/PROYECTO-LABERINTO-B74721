///Universidad de Costa Rica
/// Programaciòn Bajo Plataformas Abiertas-IE0117
/// Proyecto: Programar un resolvedor de laberintos en un entorno individual.
/// Estudiante: Angie Julissa Mèndez Ramìrez - B74721
/// Profesor: Juan Carlos Coto

///// Lògica del Juego ///////

//Inclusiòn de archivo de reconocimiento del documento .txt

#include "recorrermatriz.h"

// se define una variable para almacenar la lògica del...
//..juego de acuerdo a lo traìdo en "recorrermatriz.h"
char cc;

// "travel" nos lleva a la solucion a travès de un booleano
int travel(char doc[]){
    // se inicia en False cuando aùn no hemos encontrado un 2
    int bool=0;
    FILE* f= abrirdoctxt(doc);
    for (cc = getc(f); cc != EOF; cc = getc(f)) {
        //si el carácter que estoy leyendo es distinto a un espacio...
        //... distinto a un salto de linea y tambien es distinto a un cero...
        //...pasa a la siguiente condicion: ser un 1 o un 2
        if (cc != ' ' && cc != '\n' && cc !='0') {
            //si es 1, imprìmame un 1, que enseña el camino
            if (cc == '1') {
                printf("%d",1);
            //si es 2, imprìmame un 2...
            //y transfòrmeme el booleano en True    
            }else if(cc=='2'){
                printf("%d", 2);
                bool=1;
            }
        // Visualizaciòn del laberinto:
        //si me encuentro un salto de lìnea...
        //... imprimo un salto de lìnea
        }else if(cc=='\n'){
            printf("\n");
        //si me encuentro un cero...
        //... imprimo un espacio
        }else if(cc=='0'){
            printf(" ");
        //si me encuentro un espacio...
        //...tambièn imprimo un espacio
        }else if(cc==' '){
            printf(" ");
        }
    }
    return bool; //este booleano dice si es True o False para toda esta lògica del travel
}

//Contador de Dos: verifica si hay o no hay...
//...màs de un 2 en el laberinto
int contDeDos(char doc[]){
    int contDos=0; //se inicia en cero ya que arrancamos...
    //...desde el primer elemento que sea un 2
    FILE* f= abrirdoctxt(doc);
    for (cc = getc(f); cc != EOF; cc = getc(f)) {
        //si el carácter que estoy leyendo es distinto a un espacio...
        //... distinto a un salto de linea y tambien es distinto a un cero...
        //...pasa a la siguiente condicion:
        if (cc != ' ' && cc != '\n' && cc != '0') {
            //si es un dos, se agrega al contador uno "2" màs
            // se busca que ese contador siempre de uno, pues...
            //... solo queremos tener un camino vàlido con una...
            //...ùnica soluciòn
            if (cc == '2') {
                contDos = contDos + 1;
            }
        }
    }
    return contDos; //me devuelve la cantidad de "2" en total
}

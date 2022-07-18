///Universidad de Costa Rica
/// Programaciòn Bajo Plataformas Abiertas-IE0117
/// Proyecto: Programar un resolvedor de laberintos en un entorno individual.
/// Estudiante: Angie Julissa Mèndez Ramìrez - B74721
/// Profesor: Juan Carlos Coto

///// Reconocimiento del documento .txt ///////

//Inclusiòn de Librerìas
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


// Declaraciòn de variable que guarda el recorrido caracter por caracter
char c;
//Lògica de la apertura del archivo
FILE * abrirdoctxt(char name[]){
    FILE* fp;
    // Se guarda en una variable la lectura del archivo a partir 
    //de una funciòn "fopen "
    fp = fopen(name, "r");
    // se define una condiciòn para cuando el archivo no tenga nada
    // o simplemente no exista
    if (fp == NULL) {
        printf("No se abrio el documento %s",
               name);
    }
}

//Lògica de extracciòn de filas de la matriz caracter por caracter
int traerFilastxt(char name[]){
    //inicio desde 1 para contar las filas
    int row = 1;
    //recorre la matriz para reconocer saltos de lìnea y definir el numero de filas
    FILE* f= abrirdoctxt(name);
    for (c = getc(f); c != EOF; c = getc(f)) {
        //si hay un salto de lìnea "\n" entonces al numero de filas actual, le sumo una màs
        if (c == '\n') {
            row = row + 1;
        }
    }
    return  row;//Me devuelve las filas en total

}
int traerColumnastxt(char name[]){
    // inicio desde 0 para contar las columnas
    int column = 0;
    //recorre la matriz para reconocer el numero de caracteres por fila y definir el nùmero de columnas
    FILE* f= abrirdoctxt(name);
    for (c = getc(f); c != EOF; c = getc(f)) {
        // si el caracter es diferente a un espacio y a un salto de lìnea entonces al nùmero...
        //... de columnas actual, le sumo una màs
        if (c != ' ' && c != '\n') {
            column = column + 1;
        //si hay un salto de lìnea entonces no se devuelve el contador a cero 
        // cuenta los elementos por fila para definir el numero de columnas
        }if(c == '\n'){
            column = 0;
        }
    }
    return column;//Me devuelve las columnas en total
}

//Se imprime la matriz extraida del laberinto
void matrizprint(char name[]){
    //la variable sb tiene estructura tipo "stat" que...
    //...recupera el tamaño del archivo
    struct stat sb;
    FILE* f= abrirdoctxt(name);
    //La función stat () obtendrá información sobre el archivo
    //... nombrado y la escribirá en el área señalada por el argumento buf
    // Los buffer circulares no son más que “arrays” a los cuales se añaden datos. 
    stat(name, &sb);
    //malloc	asigna el número especificado de bytes
    char *file_contents = malloc(sb.st_size);
    //"fscanf" se encarga de leer desde un archivo con base en una tira de caracteres de formato.
    //se usa while para cuando se termine de leer los caracteres y almacenar...
    //... en la memoria se comience de nuevo cuando se encuentre con final...
    //...de la matriz.
    while (fscanf(f, "%[^\n] ", file_contents) != EOF) {
        printf("%s\n", file_contents);
    }
}


//Creaciòn de coordenada: hace un  recorrido de toda la matriz para...
//...encontrar la ùnica solucion aunque hayan varias salidas o "caminos de unos"...
//... y me lea la coordenada exacta.
void coordSol(char name[]){
    // inicio desde 0 para contar las columnas
    int column = 0;
    //inicio desde 1 para contar las filas
    int fila = 1;
    FILE* f= abrirdoctxt(name);
    for (c = getc(f); c != EOF; c = getc(f)) {
        //si es diferente de espacio y diferente de un salto de linea...
        //...agregue al contador  de columnas, una columna màs
        if (c != ' ' && c != '\n') {
            column = column + 1;
        //si es igual a un salto de lìnea...
        //...agregue al contador de filas una columna de màs
        }if(c == '\n'){
            column = 0;
            fila = fila + 1;
        }
        //cuando encuentre el 2...
        //...imprimame donde està esa solucion como (fila, columna)
        if (c == '2'){
            printf("La coordenada de la solucion es %d, %d", fila, column);
        }
    }
}
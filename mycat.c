//OPEN
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//READ
#include <unistd.h>
//Basicas C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    //Comprobamos que el numero de argumentos sea valido
    if(argv[1] == NULL || argv[2]!=NULL){
        //Si no lo son imprimimos por pantalla un error y terminamos la ejecucion
        perror("Numero de argumentos invalido");
        exit(-1);
    }
    //Si son validos abrimos el fichero que ha sido indicado en el primer argumento como solo lectura
    int fr = open(argv[1],O_RDONLY);
    //Comprobamos que haya podido abrir el fichero
    if( fr== -1){
        //Si no ha podido imprimimos por pantalla el error y terminamos la ejecucion
        perror("No se ha podido abrir el fichero");
        exit(-1);
    }
    //Creamos un buffer del tamaño especificado y un entero que almacenara el numero de bytesleido
    char buffer [1024];
    int bytesleidos;
    //Leemos tantos bytes como el tamaño del buffer
    bytesleidos= read(fr, &buffer, sizeof(buffer));
    //Iteramos hasta que no leamos ningun byte en una iteracion
    while (bytesleidos){
        //Escribimos por pantalla los bytes leidos y volvemos a leer
        write(STDOUT_FILENO,&buffer, bytesleidos);
        bytesleidos= read(fr, &buffer, sizeof(buffer));
    }
    //Imprimimos un salto de linea para que quede bonito en la terminal
    write(STDOUT_FILENO, "\n",1);
    //Cerramos el fichero y finalizamos la ejeccución exitosamente
    close(fr);
    return 0;
}


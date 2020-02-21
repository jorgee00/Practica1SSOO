//OPEN
#include <fcntl.h>
//READ
#include <unistd.h>
//Basicas C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    //Comprobamos que el numero de argumentos sea valido
    if(argc != 2){
        //Si no lo son imprimimos por pantalla un error y terminamos la ejecucion
        write(STDERR_FILENO,"Numero de argumentos invalido\n",31);
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
    //Cerramos el fichero y finalizamos la ejeccución exitosamente
    close(fr);
    return 0;
}
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
    char buffer [1024];
    int bytesleidos;
    bytesleidos= read(fr, &buffer, sizeof(buffer));
    while (bytesleidos){
        //printf("%d" ,bytesleidos);
        write(STDOUT_FILENO,&buffer, bytesleidos);
        bytesleidos= read(fr, &buffer, sizeof(buffer));
    }
    write(STDOUT_FILENO, "\n",1);
    close(fr);
    return 0;
}


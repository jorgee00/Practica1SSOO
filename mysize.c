#include <fcntl.h>
//OPENDIR
#include <dirent.h>
//READ
#include <unistd.h>
//Basicas C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    //Comprueba que como máximo se pasa un único parámetro
    if(argc !=1 ){
        write(STDERR_FILENO,"Numero de argumentos invalido\n",29);
        exit(-1);
    }

    //Almacenamos en path la ruta del directorio en el que se ejecuta mysize.c
    //Abrimos el directorio en cuestión, almacenándolo en dir
    DIR* dir;
    char path[PATH_MAX];
    getcwd(path, PATH_MAX);
    dir = opendir(path);

    //Comprobamos si el directorio existe
    if(dir==NULL){
        write(STDERR_FILENO,"No se ha podido abrir el directorio\n",36);
        exit(-1);
    }

    //Leemos los ficheros del directorio
    struct dirent* rdir;
    rdir = readdir(dir);
    while(rdir!=NULL){
        if(rdir->d_type==DT_REG){
            int fr = open(rdir->d_name, O_RDONLY);
            int size;
            //Abrimos todos los ficheros y almacenamos su tamaño en size
            if(fr != -1){
                size =  lseek(fr,0,SEEK_END);
                close(fr);
                printf("%s\t%d\n",rdir->d_name,size);
            }
        }
        rdir = readdir(dir);
    }

    //Cerramos el directorio y retornamos 0
    closedir(dir);
    return 0;
}

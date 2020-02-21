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
    if(argc>2){
        perror("Numero de argumentos invalido");
        exit(-1);
    }

    DIR* dir;
    char path[PATH_MAX];

    //Si no se ha pasado ningún parámetro (argc==1), se muestran los contenidos del directorio desde el que se está ejecutando myls.c
    //En caso contrario se mostrará los contenidos de la ruta específicada, ya sea absoluta o relativa
    if(argc==1){
        getcwd(path,PATH_MAX);
    }else{
        //Comprobamos que la ruta pasada no excede el tamñano máximo especificado
        if(strlen(argv[1])>PATH_MAX){
            perror("Ruta demasiado grande");
            exit(-1);
        }
        //Copiamos en la variable path la ruta pasada como parámetro
        strcpy(path, argv[1]);
    }

    //Abrimos el directorio al que apunta path
    dir = opendir(path);
    //Comprobamos si se ha podido abrir el directorio
    if(dir==NULL){
        perror("No se ha podido abrir el directorio");
        exit(-1);
    }

    //Leemos los contenidos del directorio y mostramos su nombre por pantalla
    struct dirent* rdir;
    rdir = readdir(dir);
    while(rdir!=NULL){
        printf("%s\n",rdir->d_name);
        rdir = readdir(dir);
    }

    //Cerramos el directorio y retornamos 0
    closedir(dir);
    return 0;
}
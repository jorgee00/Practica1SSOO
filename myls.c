//OPENDIR
#include <sys/types.h>
#include <dirent.h>

#include <fcntl.h>
//READ
#include <unistd.h>
//Basicas C
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){

    if(argc>2){
        perror("Numero de argumentos invalido");
        exit(-1);
    }

    DIR* dir;
    char *path;
    if(argc==1){
        //RELATIVA


    }else{
        if(sizeof(argv[1])>PATH_MAX){
            perror("Ruta demasiado grande");
            exit(-1);
        }
        path = argv[1];
    }
    dir = opendir(path);
    if(dir==NULL){
        perror("No se ha podido abrir el directorio");
        exit(-1);
    }
    struct dirent* rdir;
    rdir = readdir(dir);
    while(rdir!=NULL){
        printf("%s\n",rdir->d_name);
        rdir = readdir(dir);
    }
    closedir(dir);

    return 0;

}
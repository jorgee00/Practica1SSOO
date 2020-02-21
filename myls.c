//OPENDIR
#include <dirent.h>
//READ
#include <unistd.h>
//Basicas C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

    if(argc>2){
        perror("Numero de argumentos invalido");
        exit(-1);
    }
    DIR* dir;
    char path[PATH_MAX];
    if(argc==1){
        //RELATIVA
        getcwd(path,PATH_MAX);
    }else{
        if(sizeof(argv[1])>PATH_MAX){
            perror("Ruta demasiado grande");
            exit(-1);
        }
        strcpy(path, argv[1]);
    }
    printf("%s",path);
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
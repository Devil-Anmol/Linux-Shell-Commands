//Author: AG
//Linux Terminal Commands

#include <stdio.h>
#include <string.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int args,char **argv){

    // if(strcmp(argv[1],"")==0){
        struct dirent *d;
        DIR *dir ;//= opendir(".");
        // if(dir==NULL){
        //     printf("error %s\n",strerror(errno));
        //     return 0;
        // }
        // int a; int l;
        if(args==1){
            dir = opendir(".");
            if(dir==NULL){
                printf("error %s\n",strerror(errno));
                return 0;
            }
        }
        else if(args==2){
            if((strcmp(argv[1],"-al")==0 || strcmp(argv[1],"-l")==0 || strcmp(argv[1],"-a")==0)){
                dir = opendir(".");
                
            }
            else{
                dir = opendir(argv[1]);
            }
            if(dir==NULL){
                    printf("error %s\n",strerror(errno));
                    return 0;
                }
        }
        else if(args==3 && (strcmp(argv[1],"-al")==0 || strcmp(argv[1],"-l")==0 || strcmp(argv[1],"-a")==0)){
            dir = opendir(argv[2]);
            if(dir==NULL){
                printf("error %s\n",strerror(errno));
                return 0;
            }

        }
        else{
            printf("invalid command\n");
            return 0;
        }
        while((d = readdir(dir))!=NULL){
            if(args>1){
            if(strcmp(argv[1],"-al")==0){
                // if(strcmp(d->d_name,".") || strcmp(d->d_name,"..")){
                    printf("\n");
                    struct stat s;
                    stat(d->d_name, &s);
                    if(s.st_size==0) printf("d ");
                    if(s.st_mode){
                        // if(S_IREAD) printf("r ");
                        // if(S_IWRITE) printf("w ");
                        // if(S_IEXEC) printf("x ");
                        printf( (s.st_mode & S_IRUSR) ? "r" : "-");
                        printf( (s.st_mode & S_IWUSR) ? "w" : "-");
                        printf( (s.st_mode & S_IXUSR) ? "x" : "-");
                        printf( (s.st_mode & S_IRGRP) ? "r" : "-");
                        printf( (s.st_mode & S_IWGRP) ? "w" : "-");
                        printf( (s.st_mode & S_IXGRP) ? "x" : "-");
                        printf( (s.st_mode & S_IROTH) ? "r" : "-");
                        printf( (s.st_mode & S_IWOTH) ? "w" : "-");
                        printf( (s.st_mode & S_IXOTH) ? "x" : "-");
                    }
                    printf("\t%d\t",s.st_size);
                    printf("%s",d->d_name);

                
            }
            else if(strcmp(argv[1],"-a")==0){
                printf("%s\t",d->d_name);
            }
            else if(!strcmp(argv[1],"-l")){
                if(strcmp(d->d_name,".") && strcmp(d->d_name,"..")){
                    printf("\n");
                    struct stat s;
                    stat(d->d_name, &s);
                    // if(s.st_size==0) printf("d ");
                    printf((!s.st_size) ? "d" : "-");
                    if(s.st_mode){
                        // if(S_IREAD) printf("r ");
                        // if(S_IWRITE) printf("w ");
                        // if(S_IEXEC) printf("x ");
                        printf( (s.st_mode & S_IRUSR) ? "r" : "-");
                        printf( (s.st_mode & S_IWUSR) ? "w" : "-");
                        printf( (s.st_mode & S_IXUSR) ? "x" : "-");
                        printf( (s.st_mode & S_IRGRP) ? "r" : "-");
                        printf( (s.st_mode & S_IWGRP) ? "w" : "-");
                        printf( (s.st_mode & S_IXGRP) ? "x" : "-");
                        printf( (s.st_mode & S_IROTH) ? "r" : "-");
                        printf( (s.st_mode & S_IWOTH) ? "w" : "-");
                        printf( (s.st_mode & S_IXOTH) ? "x" : "-");
                    }
                    printf("\t%d\t",s.st_size);
                    printf("%s",d->d_name);

                }
            }
            else{
                if(strcmp(d->d_name,".") && strcmp(d->d_name,"..")){
                    // printf("\n");
                    // struct stat s;
                    // stat(d->d_name, &s);
                    // if(s.st_size==0) printf("d ");
                    // if(s.st_mode){
                    //     if(S_IREAD) printf("r ");
                    //     if(S_IWRITE) printf("w ");
                    //     if(S_IEXEC) printf("x ");
                    // }
                    // printf("\t%d\t",s.st_size);
                    printf("%s\t",d->d_name);

                }
            }
            }
            else{
                if(strcmp(d->d_name,".") && strcmp(d->d_name,"..")){
                    
                    printf("%s\t",d->d_name);
            }
        
        }
        }
        printf("\n");
        

    return 0;
}

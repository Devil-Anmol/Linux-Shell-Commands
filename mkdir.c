//Author: AG
//Linux Terminal Commands

#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<errno.h>


int main(int args,char **argv){

    if(args==2){
        if(strcmp(argv[1],"-v") && strcmp(argv[1],"-m") ){
            int m = mkdir(argv[1],0777);
            if(m){
                printf("error: %s\n",strerror(errno));
            }
        }
    }

    else if(args>2){
        if(!strcmp(argv[1],"-v")){
            int i=2;
            while(argv[i]!=NULL){
                int m = mkdir(argv[i],0777);
                if(!m){
                    printf("mkdir: directory created \"%s\"\n",argv[i]);

                }
                else{
                    printf("error: %s\n",strerror(errno));
                }
            i++;
            }
        }
        else if(strchr(argv[1],*("m")) && strchr(argv[1],*("-"))){
            int u = 0;
            char p[10];
            // char a[5];
            int a;
            if(strchr(argv[1],*("r"))){
                u+=4;
            }
            if(strchr(argv[1],*("w"))){
                u+=2;
            }
            if(strchr(argv[1],*("x"))){
                u+=1;
            }

            a = u*(73);
            int i=2;
            while(argv[i]!=NULL){
                    int m = mkdir(argv[i],a);
                    if(m){
                        printf("error %s: %s\n",argv[i],strerror(errno));
                    }
                    i++;
                }
        }
        else{
            int i=1;
            while(argv[i]!=NULL){
                int m = mkdir(argv[i],0777);
                // if(!m){
                //     printf("mkdir: directory created \"%s\"",argv[i]);

                // }
                // else{
                //     printf("error: %s",strerror(errno));
                // }
            i++;
            }
        }
    }else printf("invalid command\n");

    return 0;
}

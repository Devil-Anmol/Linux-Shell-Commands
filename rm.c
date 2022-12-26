//Author: AG
//Linux Terminal Commands

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int main(int args , char**argv){

    int i =1;
    if(strcmp(argv[i],"-f")==0){
        i++;
        if (!strcmp(argv[i], "shell.c")
                || !strcmp(argv[i], "mkdir.c")
                || !strcmp(argv[i], "ls.c")
                || !strcmp(argv[i], "cat.c")
                || !strcmp(argv[i], "date.c")
                || !strcmp(argv[i], "rm.c")
                || !strcmp(argv[i], "rm")
                || !strcmp(argv[i], "mkdir")
                || !strcmp(argv[i], "ls")
                || !strcmp(argv[i], "date")
                || !strcmp(argv[i], "cat")
                || !strcmp(argv[i], "shell")){
            // printf("You are not permitted to delete the code files of the project!!!\n");
            return 0;
        }
        // i++;
        while(argv[i]!=NULL){
            int s = remove(argv[i]);
            if(!s){
                printf("%s file delected successfully\n",argv[i]);
            }
            // else{
            //     printf("error : %s",strerror(errno));
            // }
            // remove(argv[i]);
            i++;
        }
    }
    else if (!strcmp(argv[i],"-i")){
        i++;
        if (!strcmp(argv[i], "shell.c")
                || !strcmp(argv[i], "mkdir.c")
                || !strcmp(argv[i], "ls.c")
                || !strcmp(argv[i], "cat.c")
                || !strcmp(argv[i], "date.c")
                || !strcmp(argv[i], "rm.c")
                || !strcmp(argv[i], "rm")
                || !strcmp(argv[i], "mkdir")
                || !strcmp(argv[i], "ls")
                || !strcmp(argv[i], "date")
                || !strcmp(argv[i], "cat")
                || !strcmp(argv[i], "shell")){
            printf("You are not permitted to delete the code files of the project!!!\n");
            return 0;
        }
        // i++;
        while(argv[i]!=NULL){
            printf("do you want to remove %s file(y/n): ",argv[i]);
            char y[10];
            scanf("%s",y);
            if(!strcmp(y,"y")){
                // remove(argv[i]);
                // printf("1");
                int s = remove(argv[i]);
                if(!s){
                    printf("%s file delected successfully\n",argv[i]);
                }
                else{
                    printf("error : %s\n",strerror(errno));
                }
            }
            i++;
        }
    }
    else{
        if (!strcmp(argv[i], "shell.c")
                || !strcmp(argv[i], "mkdir.c")
                || !strcmp(argv[i], "ls.c")
                || !strcmp(argv[i], "cat.c")
                || !strcmp(argv[i], "date.c")
                || !strcmp(argv[i], "rm.c")
                || !strcmp(argv[i], "rm")
                || !strcmp(argv[i], "mkdir")
                || !strcmp(argv[i], "ls")
                || !strcmp(argv[i], "date")
                || !strcmp(argv[i], "cat")
                || !strcmp(argv[i], "shell")){
            printf("You are not permitted to delete the code files of the project!!!\n");
            return 0;
        }
        // i++;
        while(argv[i]!=NULL){
            // remove(argv[i]);
            int s = remove(argv[i]);
            if(!s){
                printf("%s file delected successfully\n",argv[i]);
            }
            else{
                printf("error : %s\n",strerror(errno));
            }
            i++;
        }
    }

    return 0;
}

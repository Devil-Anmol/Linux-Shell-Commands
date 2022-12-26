//Author: AG
//Linux Terminal Commands

#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
#include<pthread.h>
#include<stdlib.h>
 
long long i =0;
int k=0;

void stringsplit(char* str,char* c,char** lists){
    
    lists[0] = strtok(str,c);
    i=0;
    while(lists[i]!=NULL){
        i++;
        k=i;
        lists[i]=strtok(NULL,c);
    }
    
}

void stringslice(char *s,char **list){
    strcpy(s,"");
    for(int j=0;j<k-1;j++){
        strcat(s,list[j]);
        strcat(s," ");
    }
}

void *func(void *arg){
    system(arg);
}


int main()
{
    char str[100];
    char str2[100];
    char str3[100];
    char* list_com[100];
    int flag = 1;

    char path[10000];
    getcwd(path,sizeof(path));

    printf("\033[97m\033[1m\033[4mWELCOME TO AG's SHELL\n\033[0m\033[0m\033[0m");
    while(flag){
        char addressd[10000];
        char path1[10000];
            getcwd(addressd,sizeof(addressd));
            printf("\033[96m[%s]\033[0m",addressd);
        printf("$ ");

        fgets(str,100,stdin);

        strcpy(str2,str);

    
        
        stringsplit(str2," \n",list_com);

        if(!strcmp(list_com[k-1],"&t") && strcmp(list_com[0],"cd") && strcmp(list_com[0],"pwd") && strcmp(list_com[0],"echo") && strcmp(list_com[0],"exit")){
            // system(list_com[0]);
            // char path2[10000];
            // getcwd(path2,10000);
            // strcat(path2,"/");
            // printf("%s\n",str3);
            // char * token1 = strtok(str3,"&");
            // printf("%s\n",token1);
            char str4[10000];
            strcpy(str4,path);
            // printf("%s",str4);
            strcat(str4,"/");
            stringslice(str3,list_com);
            // strcat(str4,list_com[0]);
            // strcat(str4," ");

            strcat(str4,str3);
            // printf("%s\n",str3);
            // strcpy(path2,token1);
            pthread_t p;
            // pthread_join(p,NULL);
            pthread_create(&p , NULL , func , str4);
            pthread_join(p,NULL);
        }
        else{
            if(strcmp(list_com[0],"pwd")==0){
                if(k==1){
                    char address[10000];
                    getcwd(address,sizeof(address));
                    printf("%s\n",address);
                    // flag=1;
                    // free(address);
                    
                }else if(k==2){
                    if(strcmp(list_com[1],"-P") || strcmp(list_com[1],"-L")){
                        char address[10000];
                        getcwd(address,sizeof(address));
                        printf("%s\n",address);
                    }
                    else if(!strcmp(list_com[1],"--help")){
                        printf("this is the help function: \npwd -P or pwd -L (available) \nfunction used to get the present working directory\n");
                    }
                    else printf("invalid command\n");
                }
                else printf("invalid command\n");

            }
            else if(strcmp(list_com[0],"cd")==0){
                if(k<=2){
                    if(k==2 && !strcmp(list_com[1],"--help")){
                        
                        printf("this is the help function:\ncd dir or cd ~ or cd / (available)\nfunction used to get the present working directory\n");
                    }
                    else if(k==2){
                    int c = chdir(list_com[1]);
                    if(c){
                        if(!strcmp(list_com[1],"~")){
                            chdir("/home");
                        }
                        else printf("error: %s\n",strerror(errno));
                    }
                }}
                else if(k==3 && !strcmp(list_com[1],"-L")){}
                else{
                    printf("invalid command\n");
                }
            }

            else if(strcmp(list_com[0],"echo")==0){
                int j=1;
                // while(list_com[j]!=NULL){
                //     printf("%s ",list_com[j]);
                //     j++;
                // }
                // printf("\n");
                if(strcmp(list_com[1],"-n")==0){
                    j=2;
                    while(list_com[j]!=NULL){
                        printf("%s ",list_com[j]);
                        j++;
                    }
                }
                else if(strcmp(list_com[1],"-E")==0){
                    j=2;
                    while(list_com[j]!=NULL){
                        printf("%s ",list_com[j]);
                        j++;
                    }
                    printf("\n");
                }
                else{
                    while(list_com[j]!=NULL){
                        printf("%s ",list_com[j]);
                        j++;
                    }
                    printf("\n");
                }
            }
            else if(strcmp(list_com[0],"cat")==0 || !strcmp(list_com[0],"date") || !strcmp(list_com[0],"ls") || !strcmp(list_com[0],"rm")|| !strcmp(list_com[0],"mkdir")){
                strcpy(path1,path);
                strcat(path1,"/");
                strcat(path1,list_com[0]);
                // printf("%s\n",path);
                pid_t rc = fork();
                if(rc>0){
                    waitpid(0,NULL,0);
                }
                else if(rc==0){
                    if(execv(path1,list_com)==-1){
                        printf("error\n");
                    }
                }
            }

            else if(strcmp(list_com[0],"exit")==0){
                printf("shell terminated!!!\n");
                flag=0;
            }

            else{
                printf("command not found\n");
            }

            
        }

    }

    return 0;
}

//Author: AG
//Linux Terminal Commands

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

// char cwd[1000];

int main(int args, char **argv){
    // args = 1;
    // argv={"cat",">","hello.txt"};
    // cwd[0]="\0";
    int display;
    int i = 1;
    char* path = malloc(1000* sizeof(char));
    char* ini_dir = malloc(1000* sizeof(char));
    getcwd(ini_dir,1000);
    strcpy(path,ini_dir);
    strcat(path,"/");


    if(args<=3){
        if(strcmp(argv[1],"-n")==0){                        // flag prints line number along with new lines
            // getcwd(cwd,sizeof(cwd));
            // perror("error in file address");
            int i = 1;
            strcat(path,argv[2]);
            FILE* file;
            file = fopen(path,"r");
            if(file!=NULL){
                printf("%d) ",i);
                while(1){
                    display = fgetc(file);
                    if(feof(file)){
                        break;
                    }
                    char a = display;
                    if(a=='\n'){
                        i++;
                        printf("\n%d) ",i);
                        continue;
                    }
                    printf("%c",display);
                    
                }
                printf("\n");
                fclose(file);
                
            }
            else{
                printf("error in opening file: %s\n",strerror(errno));
            }

        }
        else if(strcmp(argv[1],">")==0){                    // operation used to create a new file
            FILE * file;
            strcat(path,argv[2]);
            char *array=realpath(path,NULL);        
            if(array!=NULL){
                printf("file already exists\n");
                // fclose(file);
            }
            else{
                // fclose(file);
                file = fopen(path,"w");
                fclose(file);
                printf("file created\n");
            }
            
        }
        else if(args == 2 ) {                                               // case when no option is given
            // FILE* file;
            // file = fopen(path,"r");
            strcat(path,argv[1]);
            FILE* file;
            file = fopen(path,"r");
            if(file!=NULL){
                // printf("%d) ",i);
                while(1){
                    display = fgetc(file);
                    if(feof(file)){
                        break;
                    }
                    // char a = display;
                    // if(a=='\n'){
                    //     i++;
                    //     printf("\n%d) ",i);
                    //     continue;
                    // }
                    printf("%c",display);
                    
                }
                printf("\n");
                fclose(file);
                
            }
            else{
                printf("error in opening file: %s\n",strerror(errno));
            }
        }
        else printf("invalid command\n");
    }else printf("invalid command\n");

    return 0;

}

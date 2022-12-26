//Author: AG
//Linux Terminal Commands

#include <stdio.h>
#include <time.h>
#include<string.h>
int main(int args, char**argv) {

	if(args==1){
		time_t t;
		time(&t);
		if(t==-1){
			printf("failed time\n");
		}
		printf("%s",ctime(&t));
	}
	else if(!strcmp(argv[1], "-u") && args == 2){
		time_t t = time(&t);
		struct tm *information = gmtime(&t);
		if(information == NULL){
			printf("gmtime failed\n");
		}
		printf("%s", asctime(information));
	}
	else if(!strcmp(argv[1], "-R") && args == 2){
		time_t t = time(&t);
		struct tm *information = localtime(&t);
		// printf("%s", asctime(information));
		char str[100];
		strftime(str,100,"%a, %d %b %EY %T %z\n",information);
		printf("%s",str);
	}
	else printf("invalid command\n");
	return 0;
}

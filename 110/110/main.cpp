#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ctype.h>
using namespace std;
int main(){
    char* temp=new char[105];
    char* input=new char[105];
    int max=-1;
    while(scanf("%s",input)){
        if(!strcmp(input,"E-N-D")){
            break;
        }
        int i=0;
        int len=0;
        while(input[i]!='\0'&&input[i]!='\n') {
            if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || input[i] == '-') {
                len+=1;
            }
            if(input[i] >= 'A' && input[i] <= 'Z'){
                input[i]=input[i]+32;
            }
            i++;
        }
        if(max<len){
            max=len;
            strcpy(temp,input);
        }
    }
    for(int i=0;i<strlen(temp);i++){
        if ((temp[i] >= 'a' && temp[i] <= 'z')  || temp[i] == '-') {
            printf("%c",temp[i]);
        }
    }
    printf("\n");
    return 0;
}


#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int people;
    scanf("%d",&people);
    char** name=new char*[people];
    int** birthday=new int*[people];
    for(int i=0;i<people;i++){
        birthday[i]=new int[3];
        name[i]=new char[15];
        int j=0;
        char c;
        scanf("%c",&c);
        scanf("%c",&c);
        while(c!=' '){
            name[i][j++]=c;
            scanf("%c",&c);
        }
        scanf("%d %d %d",&birthday[i][0],&birthday[i][1],&birthday[i][2]);
    }
    int youngDay=birthday[0][0];
    int youngMonth=birthday[0][1];
    int youngYear=birthday[0][2];
    int oldDay=birthday[0][0];
    int oldMonth=birthday[0][1];
    int oldYear=birthday[0][2];
    int young=0;
    int old=0;
    for(int i=0;i<people;i++){
        if(birthday[i][2]<oldYear||(birthday[i][2]==oldYear&&birthday[i][1]<oldMonth)||(birthday[i][2]==oldYear&&birthday[i][1]==oldMonth&&birthday[i][0]<oldDay)){
            old=i;
            oldYear=birthday[i][2];
            oldMonth=birthday[i][1];
            oldDay=birthday[i][0];
        }
        if(birthday[i][2]>youngYear||(birthday[i][2]==youngYear&&birthday[i][1]>youngMonth)||(birthday[i][2]==youngYear&&birthday[i][1]==youngMonth&&birthday[i][0]<youngDay)){
            young=i;
            youngYear=birthday[i][2];
            youngMonth=birthday[i][1];
            youngDay=birthday[i][0];
        }
    }
    cout<<name[young]<<endl;
    cout<<name[old]<<endl;
}

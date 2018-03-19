#include <iostream>
#include <stdio.h>
#include <set>
#include <string>
#include <cstring>
using namespace std;
bool isValid(char c){
    return (c>=65&&c<=90)||(c>=97&&c<=122);
}
int main(){
    string word;
    set<string> res;
    while(cin>>word){
        string temp="";
        for(int i=0;i<word.length();i++){
            if(isValid(word[i])){
                temp+=tolower(word[i]);
            }
            else if(temp!=""){
                res.insert(temp);
                temp="";
            }
        }
        if(temp!=""){
            res.insert(temp);
        }
    }
    for(set<string>::iterator it = res.begin();it!=res.end();it++){
        cout<<*it<<endl;
    }
}

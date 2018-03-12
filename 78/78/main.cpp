#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <stdio.h>
using namespace std;
string getSubsequence(string s){
    int flag=0;
    int previous=0;
    string res="";
    for (char ch='z';ch>='a';ch--) {
        int count = 0;
        for (int i =previous;i<s.length();i++) {
            if (s[i] == ch)
                count++;
        }
        if (count>=1) {
            for (int i=previous;i<s.length();i++) {
                if (s[i] == ch) {
                    res+=ch;
                    flag = i;
                }
            }
            previous = flag;
        }
    }
    return res;
}
int main(){
    int testCases;
    cin>>testCases;
    getchar();
    for(int i=0;i<testCases;i++){
        string input;
        getline(cin,input);
        cout<<getSubsequence(input)<<endl;
    }
}

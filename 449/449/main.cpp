#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <iterator>
#include <stdlib.h>
using namespace std;
int main(){
    string input;
    while(getline(cin,input)){
        vector<string> kingdom;
        do{
            kingdom.push_back(input);
            getline(cin,input);
        }while(input.compare("\0"));
        int beach=0;
        if(kingdom.size()==1){
            for(int j=0;j<kingdom[0].length()-1;j++){
                if(kingdom[0][j]!=kingdom[0][j+1]) beach+=1;
            }
        }
        else{
            for(int i=0;i<kingdom.size();i++){
                for(int j=0;j<kingdom[i].length()-1;j++){
                    if(kingdom[i][j]!=kingdom[i][j+1]) beach+=1;
                }
                if(i!=kingdom.size()-1){
                    if(i%2==0){
                        for(int j=0;j<kingdom[i].length();j++){
                            if(j==0){
                                if(kingdom[i][j]!=kingdom[i+1][j]) beach+=1;
                            }
                            else{
                                if(kingdom[i][j]!=kingdom[i+1][j-1]) beach+=1;
                                if(kingdom[i][j]!=kingdom[i+1][j]) beach+=1;
                            }
                        }
                    }
                    else{
                        for(int j=0;j<kingdom[i].length();j++){
                            if(j==(kingdom[i].length()-1)){
                                if(kingdom[i][j]!=kingdom[i+1][j]) beach+=1;
                            }
                            else{
                                if(kingdom[i][j]!=kingdom[i+1][j]) beach+=1;
                                if(kingdom[i][j]!=kingdom[i+1][j+1]) beach+=1;
                            }
                        }
                    }
                }
            }
        }
        cout<<beach<<endl;
    }
}

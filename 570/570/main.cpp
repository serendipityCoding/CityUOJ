#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string input;
int main() {
    int testCase;
    cin>>testCase;
    getchar();
    for (int i=0;i<testCase;i++) {
        getline(cin,input);
        int length = input.length();
        int total = 0;
        //minimum steps to get the target word without considering any restriction
        for (int j=0;j<length;j++) {
            total+=min(input[j]-'A','Z'-input[j]+1);
        }
        int minus = 0;
        //go from the left to the right
        for(int j=1;j<length;j++){
            int inital=-1;
            int last=-1;
            //if the origin input is A, check if there are other non-A char in the rest of the input
            if (input[j]=='A') {
                inital=j;
                for(int k=j+1;k<length; k++){
                    j++;
                    //if there is non-A char, get the position of the last char
                    if(input[k]!='A'){
                        last=k-1;
                        break;
                    }
                }
                //if the rest are all A, set the position to the last char of the input
                if (last==-1){
                    last=length-1;
                }
                //choose the mini one
                //whether go from the A to the last recorded position (left to right)
                //or go back (right to left)
                int temp =(last+1-inital)-min(inital-1,length-(last + 1));
                if(temp>minus){
                    minus=temp;
                }
            }
        }
        int res=total+length-1-minus;
        cout<<res<<endl;
    }
}

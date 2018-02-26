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
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    string input;
    int i=0;
    while(getline(cin,input)){
        if(!input.compare("\0")) continue;
        if(i!=0)printf("\n");
        istringstream buf(input);
        istream_iterator<string> beg(buf), end;
        vector<string> tokens(beg, end);
        double sum=0;
        for(auto& s: tokens){
            bool hasDecimal=false;
            for(int j=0;j<s.length();j++){
                if(s[j]=='.'){
                    hasDecimal=true;
                    break;
                }
            }
            if(hasDecimal) s+="00001";
            sum+=stod(s) * 10000000;
        }
        cout<<fixed<<setprecision(4)<<sum/10000000<<endl;
        i++;
        input="";
    }
}

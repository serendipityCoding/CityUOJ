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
#include <math.h>
using namespace std;
int getNutBox(int maxSection, int nuts, int divisors,  int sectionCap){
    nuts-=sectionCap;
    if(nuts<=0) return 1;
    int boxes=1;
    for(int i=0;i<divisors;i++){
        if(i>=(maxSection-1)&&i%(maxSection-1)==0) {
            boxes+=1;
            nuts-=sectionCap;
        }
        nuts-=sectionCap;
        if(nuts<=0) return boxes;
    }
    if(divisors>=(maxSection-1)&&divisors%(maxSection-1)!=0) return boxes+=ceil(double(nuts-sectionCap)/double(sectionCap));
    return boxes+=ceil(double(nuts)/double(sectionCap));
}
int main(){
    string input;
    int d;
    while(scanf("%d",&d)!=EOF){
//        istringstream buf(input);
//        istream_iterator<string> beg(buf), end;
//        vector<string> tokens(beg, end);
//        int box=getNutBox(stoi(tokens[0]),stoi(tokens[1]),stoi(tokens[2]),stoi(tokens[3]));
//        cout<<box<<endl;
    }
}

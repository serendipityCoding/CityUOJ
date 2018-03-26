#include <iostream>
#include <cstring>
#include <string>
using namespace std;
struct suffix{
    int index;
    char *suff;
};
int cmp(struct suffix a, struct suffix b){
    return strcmp(a.suff,b.suff)<0?1:0;
}
void *buildSuffixArray(char *txt, int n){
    struct suffix suffixes[n];
    for(int i=0;i<n;i++){
        suffixes[i].index=i;
        suffixes[i].suff=(txt+i);
    }
    sort(suffixes,suffixes+n,cmp);
    int max=0;
    int resIndex=0;
    if(suffixes[0]==NULL){
        cout<<"No repetitions found!"<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            if(max<suffixes[i].index){
                max=suffixes[i].index;
                resIndex=i;
            }
        }
        cout<<suffixes[resIndex].suff<<" "<<suffixes[resIndex].index<<endl;
    }
}

int main(){
    int testCase;
    cin>>testCase;
    getchar();
    for(int i=0;i<testCase;i++){
        char* s;
        cin>>s;
        buildSuffixArray(s,strlen(s));
    }
}

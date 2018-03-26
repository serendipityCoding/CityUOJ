#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int segNo;
struct Point{
    int x,y;
};
struct Line{
    Point s;
    Point e;
};
vector<Line> lines;
bool onSegment(Point p,Point q,Point r){
    if(q.x<=max(p.x,r.x)&&q.x>=min(p.x,r.x)&&q.y<=max(p.y,r.y)&&q.y>=min(p.y,r.y))
        return true;
    return false;
}

int orientation(Point p, Point q, Point r){
    int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool intersect(Line l1, Line l2){
    int o1=orientation(l1.s,l1.e,l2.s);
    int o2=orientation(l1.s,l1.e,l2.e);
    int o3=orientation(l2.s,l2.e,l1.s);
    int o4=orientation(l2.s,l2.e,l1.e);
    if(o1!=o2&&o3!=o4)
        return true;
    if(o1==0 &&onSegment(l1.s,l2.s,l1.e)) return true;
    if(o2==0 &&onSegment(l1.s,l2.e,l1.e)) return true;
    if(o3==0 &&onSegment(l2.s,l1.s,l2.e)) return true;
    if(o4==0 &&onSegment(l2.s,l1.e,l2.e)) return true;
    return false;
}
int solve(){
    int count=segNo;
    for(int i=0;i<segNo;i++){
        for(int j=0;j<segNo;j++){
            if(i!=j&&intersect(lines[i],lines[j])){
                count-=1;
                break;
            }
        }
    }
    return count;
}
int main(){
    int testCase;
    cin>>testCase;
    for(int t=0;t<testCase;t++){
        cin>>segNo;
        Point start;
        Point end;
        for(int i=0;i<segNo;i++){
            Line l;
            cin>>start.x>>start.y>>end.x>>end.y;
            l.s=start;
            l.e=end;
            lines.push_back(l);
        }
        cout<<solve()<<endl;
        lines.clear();
    }
}

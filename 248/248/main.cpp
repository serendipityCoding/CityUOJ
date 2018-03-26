#include <iostream>
#include <algorithm>
using namespace std;
struct Point{
    int x,y;
};
struct Line{
    Point s;
    Point e;
};
Line lines[5];
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
char solve(){
    for(int i=1;i<5;i++){
        if(intersect(lines[i],lines[0])){
            return 'T';
        }
    }
    return 'F';
}
int main(){
    int testCase;
    cin>>testCase;
    for(int i=0;i<testCase;i++){
        cin>>lines[0].s.x;
        cin>>lines[0].s.y;
        cin>>lines[0].e.x;
        cin>>lines[0].e.y;
        int left,top,right,bottom;
        cin>>left>>top>>right>>bottom;
        if(right<left){
            int c=right;
            right=left;
            left=c;
        }
        if(top<bottom){
            int c=top;
            top=bottom;
            bottom=c;
        }
        if(lines[0].s.x>left&&lines[0].s.x<right&&
           lines[0].e.x>left&&lines[0].e.x<right&&
           lines[0].s.y>bottom&&lines[0].s.y<top&&
           lines[0].e.y>bottom&&lines[0].e.y<top
           ){
            cout<<'T'<<endl;
            continue;
        }
        lines[1].s.x=left;
        lines[1].s.y=top;
        lines[1].e.x=right;
        lines[1].e.y=top;
        lines[2].s.x=left;
        lines[2].s.y=bottom;
        lines[2].e.x=left;
        lines[2].e.y=top;
        lines[3].s.x=right;
        lines[3].s.y=bottom;
        lines[3].e.x=right;
        lines[3].e.y=top;
        lines[4].s.x=left;
        lines[4].s.y=bottom;
        lines[4].e.x=right;
        lines[4].e.y=bottom;
        cout<<solve()<<endl;
    }
}

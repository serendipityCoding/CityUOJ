#include <iostream>
#include <utility>
#include <vector>
#include <stack>
using namespace std;
int verticeNo;
struct Point{
    int x,y;
};
vector<Point> s;
Point points[513];
Point p0;
Point nextToTop(stack<Point> &S){
    Point p=S.top();
    S.pop();
    Point res=S.top();
    S.push(p);
    return res;
}
void swap(Point &p1, Point &p2){
    Point temp=p1;
    p1=p2;
    p2=temp;
}
int distSq(Point p1, Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int orientation(Point p, Point q, Point r){
    int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(val== 0) return 0;
    return (val>0)?1:2;
}
int compare(const void *vp1, const void *vp2){
    Point *p1=(Point *)vp1;
    Point *p2=(Point *)vp2;
    int o=orientation(p0, *p1, *p2);
    if(o==0)
        return (distSq(p0,*p2)>=distSq(p0,*p1))?-1:1;
    return (o==2)?-1:1;
}
stack<Point> sortStack(stack<Point> &input){
    stack<Point> tmpStack;
    while (!input.empty()){
        Point tmp = input.top();
        input.pop();
        while(!tmpStack.empty()&&tmpStack.top().y<tmp.y){
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(tmp);
    }
    return tmpStack;
}

void solve(int n){
    int yMin = points[0].y;
    int min = 0;
    for(int i=1;i<n;i++){
        int y=points[i].y;
        if((y<yMin)||(yMin==y&&points[i].x<points[min].x)){
            yMin=points[i].y;
            min=i;
        }
    }
    swap(points[0], points[min]);
    p0=points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);
    int m=1;
    for(int i=1;i<n;i++){
        while(i<n-1&&orientation(p0,points[i],points[i+1])==0)
            i++;
        points[m]=points[i];
        m++;
    }
    if(m<3) return;
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    for(int i=3;i<m;i++){
        while(orientation(nextToTop(S), S.top(),points[i])!=2)
            S.pop();
        S.push(points[i]);
    }
    cout<<S.size()+1<<endl;
    //stack<Point> tmp=sortStack(S);
    //Point first=S.top();
    vector<Point> res;
    while(!S.empty()){
        Point p=S.top();
        res.push_back(p);
        S.pop();
    }
    for(int i=res.size();i>0;i--){
        cout<<res[i-1].x<<" "<<res[i-1].y<<endl;
    }
    int index=res.size()-1;
    cout<<res[index].x<<" "<<res[index].y<<endl;
}

int main(){
    int testCase;
    cin>>testCase;
    cout<<testCase<<endl;
    for(int t=0;t<testCase;t++){
        cin>>verticeNo;
        int x,y;
        Point p;
        for(int i=0;i<verticeNo;i++){
            cin>>x>>y;
            p.x=x;
            p.y=y;
            points[i]=p;
        }
        solve(verticeNo);
        if(t!=(testCase-1)){
        int delimiter;
        cin>>delimiter;
        cout<<delimiter<<endl;
        }
    }
}

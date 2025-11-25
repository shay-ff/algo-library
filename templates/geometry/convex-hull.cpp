#include <bits/stdc++.h>
using namespace std;

struct Point{ long long x,y; bool operator<(const Point& other) const{ return x<other.x || (x==other.x && y<other.y); } };
long long cross(const Point &O, const Point &A, const Point &B){ return (A.x-O.x)*(B.y-O.y) - (A.y-O.y)*(B.x-O.x); }

vector<Point> convexHull(vector<Point>& pts){ int n=pts.size(), k=0; if(n<=1) return pts; sort(pts.begin(), pts.end()); vector<Point> H(2*n);
    for(int i=0;i<n;i++){ while(k>=2 && cross(H[k-2], H[k-1], pts[i]) <= 0) k--; H[k++]=pts[i]; }
    for(int i=n-2,t=k+1;i>=0;i--){ while(k>=t && cross(H[k-2], H[k-1], pts[i]) <=0 ) k--; H[k++]=pts[i]; }
    H.resize(k-1); return H;
}

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; vector<Point> pts(n); for(int i=0;i<n;i++) cin>>pts[i].x>>pts[i].y; auto ch = convexHull(pts); cout<<ch.size()<<"\n"; return 0; }

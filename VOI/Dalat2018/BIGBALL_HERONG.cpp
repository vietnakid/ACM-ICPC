#include<bits/stdc++.h> 
using namespace std; 
  
struct Point {
    long long x, y, z;
    Point(long long x, long long y, long long z) : x(x), y(y), z(z) {}
};

double dist2(Point p, Point q) {
    return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y) + (p.z - q.z)*(p.z - q.z);
}

double dist(Point p, Point q) {
    return sqrt(dist2(p, q));
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
	cin.tie();
    freopen("BIGBALL.inp", "r", stdin);
    freopen("BIGBALL.out", "w", stdout);

    long long n, xa, ya, za, xb, yb, zb;
    scanf("%lld", &n);
    scanf("%lld %lld %lld", &xa, &ya, &za);
    scanf("%lld %lld %lld", &xb, &yb, &zb);

    Point A(xa, ya, za);
    Point B(xb, yb, zb);
    double AB = dist(A, B);
    for (int i = 0; i < n; i++) {
        long long x, y, z;
        scanf("%lld %lld %lld", &x, &y, &z);
        Point C(x, y, z);
        double AC = dist(A, C);
        double BC = dist(B, C);
        double p = (AB + BC + AC) / 2.;
        double area2 = p*(p-AB)*(p-AC)*(p-BC);
        double area = sqrt(area2);
        double distance = area*2 / AB;
        printf("%.0lf\n", ceil(distance));
    }
    return 0; 
} 
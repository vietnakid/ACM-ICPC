#include <bits/stdc++.h>
using namespace std;

#define double double
#define EPS 1e-9
struct PT {
    double x, y;
    PT() : x(0), y(0) {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT& p) : x(p.x), y(p.y) {}
    int operator < (const PT& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
    int operator == (const PT& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
    PT operator + (const PT& p) const {return PT(x + p.x, y + p.y);}
    PT operator - (const PT& p) const {return PT(x - p.x, y - p.y);}
    PT operator * (double c) const {return PT(x * c, y * c);}
    PT operator / (double c) const {return PT(x / c, y / c);}
};
double cross(PT p, PT q) {return p.x * q.y - p.y * q.x;}
double area(PT a, PT b, PT c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
double area2(PT a, PT b, PT c) {return cross(a, b) + cross(b, c) + cross(c, a);}
double dot(PT p, PT q) {return p.x * q.x + p.y * q.y;}
double dist(PT p, PT q) {return sqrt(dot(p - q, p - q));}
double dist2(PT p, PT q) {return dot(p - q, p - q);}
PT RotateCCW90(PT p) {return PT(-p.y, p.x);}
PT RotateCW90(PT p) {return PT(p.y, -p.x);}
PT RotateCCW(PT p, double t) {return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}
int sign(double x) {return x < -EPS ? -1 : x > EPS;}
int sign(double x, double y) {return sign(x - y);}
ostream& operator << (ostream& os, const PT& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
PT ProjectPointLine(PT a, PT b, PT c) {
    return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
double DistancePointLine(PT a, PT b, PT c) {
    return dist(c, ProjectPointLine(a, b, c));
}
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b = b - a; d = c - d; c = c - a;
    return a + b * cross(c, d) / cross(b, d);
}
struct Line {
    PT l, r;
    Line() {}
    Line(PT l, PT r) : l(l), r(r) {}
    Line(const Line& rhs) : l(rhs.l), r(rhs.r) {}
};
Line Bisector(PT a, PT b) {
    PT c = (a + b) / 2;
    return Line(c, c + RotateCCW90(b - c));
}
struct Circle {
    PT cen;
    double rad;
    Circle() : rad(0) {}
    Circle(PT cen, double rad) : cen(cen), rad(rad) {}
    Circle(const Circle& rhs) : cen(rhs.cen), rad(rhs.rad) {}
    int operator < (const Circle& rhs) const {
        return rad < rhs.rad;
    }
};
Circle CircumCircle(PT a, PT b, PT c) {
    if (sign(cross(a - c, b - c)) == 0) {
        Circle res = Circle((a + b) / 2, dist(a, b) / 2);
        res = max(res, Circle((b + c) / 2, dist(b, c) / 2));
        res = max(res, Circle((c + a) / 2, dist(c, a) / 2));
        return res;
    }
    Line ln1 = Bisector(a, b);
    Line ln2 = Bisector(b, c);
    PT cen = ComputeLineIntersection(ln1.l, ln1.r, ln2.l, ln2.r);
    return Circle(cen, dist(cen, a));
}

Circle Enclose(vector<PT>& p) {
    // random_shuffle(p.begin(), p.end());
    int n = p.size();
    Circle c(p[0], 0);
    for (int i = 1; i < n; i++) {
        if (sign(dist(c.cen, p[i]), c.rad) > 0) {
            c = Circle(p[i], 0);
            for (int j = 0; j < i; j++) {
                if (sign(dist(c.cen, p[j]), c.rad) > 0) {
                    c = Circle((p[i] + p[j]) / 2, dist(p[i], p[j]) / 2);
                    for (int k = 0; k < j; k++) {
                        if (sign(dist(c.cen, p[k]), c.rad) > 0) {
                            c = CircumCircle(p[i], p[j], p[k]);
                        }
                    }
                }
            }
        }
    }
    return c;
}

int Inside(vector<PT>& p, Circle c) {
    for (int i = 0; i < p.size(); i++) {
        if (sign(dist(c.cen, p[i]), c.rad) > 0) return 0;
    }
    return 1;
}

Circle bruteforce(vector<PT> p) {
    Circle best = Circle(PT(), +1e100);
    for (int i = 0; i < p.size(); i++) {
        for (int j = i + 1; j < p.size(); j++) {
            for (int k = j + 1; k < p.size(); k++) {
                Circle c = CircumCircle(p[i], p[j], p[k]);
                if (Inside(p, c)) {
                    best = min(best, c);
                }
            }
            Circle c = Circle((p[i] + p[j]) / 2, dist(p[i], p[j]) / 2);
            if (Inside(p, c)) {
                best = min(best, c);
            }
        }
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    double ax, ay, bx, by, cx, cy;
    while (cin >> ax >> ay >> bx >> by >> cx >> cy) {
        PT a = PT(ax, ay);
        PT b = PT(bx, by);
        PT c = PT(cx, cy);
        double are = area(a, b, c);
        double per = dist(a, b) * dist(b, c) * dist(a, c);
        // cout << per << " " << are << " " << per/(4*are) << "\n";
        double r = per/(4*are);
        double res = 2.0 * r * 3.141592653589793;
        // printf("%lf\n", res);
        cout << fixed << setprecision(2) << res << "\n";
    }   
    return 0;
}

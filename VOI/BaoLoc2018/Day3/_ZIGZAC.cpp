#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

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

//Determine if lines from a to b and c to d are parallel or collinear
int LinesParallel(PT a, PT b, PT c, PT d) {
    return fabs(cross(b - a, c - d)) < EPS;
}
int LinesCollinear(PT a, PT b, PT c, PT d) {
    return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS && fabs(cross(c - d, c - a)) < EPS;
}
//Determine if line segment from a to b intersects with line segment from c to d
int SegmentsIntersect(PT a, PT b, PT c, PT d) {
    if (LinesCollinear(a, b, c, d)) {
        if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) return 1;
        if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0) return 0;
        return 1;
    }
    if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return 0;
    if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return 0;
    return 1;
}
//Compute intersection of line passing through a and b
//with line passing through c and d, assuming that unique
//intersection exists; for segment intersection, check if
//segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b = b - a; d = c - d; c = c - a;
    return a + b * cross(c, d) / cross(b, d);
}

int n;
vector<PT> arr(10), brr;
int permu[10];
int resTurn = INF;
double res = INF;

void sovle() {
    vector<PT> tmp;
    tmp.push_back(brr[0]);
    tmp.push_back(brr[1]);
    for (int i = 2; i < n-1; i++) { // to do
        vector<PT> cur;
        int s = tmp.size();
        cur.push_back(tmp[s-2]);
        cur.push_back(tmp[s-1]);
        cur.push_back(brr[i]);
        cur.push_back(brr[i+1]);
        if (!LinesParallel(cur[0], cur[1], cur[2], cur[3]) && !SegmentsIntersect(cur[0], cur[1], cur[2], cur[3])) {
            PT intersecPoint = ComputeLineIntersection(cur[0], cur[1], cur[2], cur[3]);
            if (fabs(intersecPoint.x - tmp[s-1].x) > esp || fabs(intersecPoint.y - tmp[s-1].y) > esp) {
                tmp.push_back(intersecPoint);
                i--;
            } else {
                if (fabs(brr[i].x - tmp[s-1].x) > esp || fabs(brr[i].y - tmp[s-1].y) > esp) {
                    tmp.push_back(brr[i]);    
                }
            }
        } else {
            if (fabs(brr[i].x - tmp[s-1].x) > esp || fabs(brr[i].y - tmp[s-1].y) > esp) {
                tmp.push_back(brr[i]);    
            }
        }
    }
    tmp.push_back(brr[n-1]);

    int curTurn = 0;
    for (int i = 1; i < tmp.size()-1; i++) {
        bool isLine = false;
        if (LinesParallel(tmp[i-1], tmp[i], tmp[i], tmp[i+1])) {
            double d = dist(tmp[i-1], tmp[i]) + dist(tmp[i], tmp[i+1]);
            double dd = dist(tmp[i-1], tmp[i+1]);
            isLine = abs(dd - d) <= esp; 
        }
        curTurn += !isLine;
    }
    double curRes = 0;
    for (int i = 1; i < tmp.size(); i++) {
        curRes += dist(tmp[i-1], tmp[i]);
    }
    if (curTurn < resTurn) {
        resTurn = curTurn;
        res = curRes;
    } else if (curTurn == resTurn && res > curRes) {
        res = curRes;
    }

    // for (auto x: brr) {
    //     cerr << x << " ";
    // }
    // cerr << endl;
    // for (auto x: tmp) {
    //     cerr << x << " ";
    // }
    // cerr << endl;
    // cerr << tmp.size() << " | turn = " << curTurn << " | res = " <<  curRes << endl;
    // cerr << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
        permu[i] = i;
    }
    do {
        brr.clear();
        for (int i = 0; i < n; i++) {
            brr.push_back(arr[permu[i]]);
        }
        sovle();
    } while (next_permutation(permu, permu+n));
    printf("%.4lf\n", res);
    return 0;
}
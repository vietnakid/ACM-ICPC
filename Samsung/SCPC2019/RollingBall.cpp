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
#define EPS 1e-9
#define PI acos((double) - 1)

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

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

double Angle(PT a) {
    if (a.x == 0) {
        if (a.y > 0) return PI / 2;
        return 3 * PI / 2;
    }
    if (a.y == 0) {
        if (a.x > 0) return 0;
        return PI;
    }
    double res = atan(a.y / a.x);
    if (a.x < 0) return res + PI;
    if (a.y < 0) return res + 2 * PI;
    return res;
}

void vietnakid() {
    int T, test_case;
    cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
        long double res = 0;
        long double r, s, e;
        cin >> r >> s >> e;
        long double cntArea = 0;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            long double a, b, h;
            cin >> a >> b >> h;
            if (h >= r) {
                res += (a - r) - s + (b-a); // hortial
                s = b + r;
                res += (h - r) * 2.; // vertical
                cntArea += 1./2.;
                // cerr << a << " " << b << " " << h << "\n";
            } else {
                // long double x0, x1, y0, y1;
                res += (a - r) - s + (b-a); // hortial
                s = a - r;


                // cerr << r << " " << h << " " << s << "\n";
                long double C = -(r*r) + (r-h)*(r-h) + (a*a);
                long double B = -2 * (a);
                long double A = 1;
                long double x = (-B - sqrt(B*B - 4*A*C))/(2.*A);
                // x = 497;
                // cerr << A << " " << B << " " << C << "\n";
                // cerr << A*x*x + B*x + C << "\n";
                // cerr << x << "\n";
                long double smallLeng = x - s;
                res += smallLeng * 2.;
                a = Angle(PT(r-smallLeng, r-h));
                long double Ratio = 1-(a / (PI / 2));

                // cerr << a << " " << Ratio << " | leng = " << a*r  << "\n";
                cntArea += Ratio * (1./4.) * 2.;
                s = b + r;
            }
        }
        res += e - s;
        res += cntArea * (2*PI*r);
        cout << "Case #" << test_case+1 << endl;
		cout << fixed << setprecision(10) << res << endl;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
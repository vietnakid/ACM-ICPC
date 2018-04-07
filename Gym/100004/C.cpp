#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

#define REP(i, a, b) \
    for (int i = (a); i < (b); i++)
#define TRvi(c, it) \
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
    for (vii::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2e9
#define INFLL 2000000000000000000 // 2e18
#define esp 0.0000000001
#define PI 3.14159265

#define RL double
#define EPS 1e-9
struct PT {
    RL x, y;
    PT() : x(0), y(0) {}
    PT(RL x, RL y) : x(x), y(y) {}
    PT(const PT& p) : x(p.x), y(p.y) {}
    int operator < (const PT& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
    int operator == (const PT& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
    PT operator + (const PT& p) const {return PT(x + p.x, y + p.y);}
    PT operator - (const PT& p) const {return PT(x - p.x, y - p.y);}
    PT operator * (RL c) const {return PT(x * c, y * c);}
    PT operator / (RL c) const {return PT(x / c, y / c);}
};

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

RL dot(PT p, PT q) {return p.x * q.x + p.y * q.y;}
RL dist(PT p, PT q) {return sqrt(dot(p - q, p - q));}
RL dist2(PT p, PT q) {return dot(p - q, p - q);}

PT RotateCCW90(PT p) {return PT(-p.y, p.x);}

vector<PT> CircleCircleIntersection(PT a, PT b, RL r, RL R) {
    vector<PT> res;
    RL d = sqrt(dist2(a, b));
    if (d > r + R || d + min(r, R) < max(r, R)) return res;
    RL x = (d * d - R * R + r * r) / (2 * d);
    RL y = sqrt(r * r - x * x);
    PT v = (b - a) / d;
    res.push_back(a + v * x + RotateCCW90(v) * y);
    if (y > 0) res.push_back(a + v * x - RotateCCW90(v) * y);
    return res;
}

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    vector<PT> arr;
    while(true) {
    	double a = -1, b = -1;
    	cin >> a >> b;
    	if (fabs(a - -1) < esp) break;
    	arr.push_back({a, b});
    }
    int res = 0;
    REP(i, 0, arr.size()) {
    	REP(j, 0, arr.size()) {
    		if (i!= j) {
    			vector<PT> points = CircleCircleIntersection(arr[i], arr[j], 2.5, 2.5);
    			REP(ii, 0, points.size()) {
    				PT p = points[ii];
    				int cnt = 0;
    				REP(jj, 0, arr.size())
    					if (dist(p, arr[jj]) - 2.5 <= esp) cnt++;
    				res = max(res, cnt);
    			}
    			
    		}
    	}
    }
    cout << max(res, 1) << endl;
    return 0;
}
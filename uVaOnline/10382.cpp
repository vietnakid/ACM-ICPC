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

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

struct interval {
	double left, right;
};

bool cmp (interval & a, interval & b) {
	if (a.left < b.left) return true;
	if (a.left > b.left) return false;
	if (a.right > b.right) return true;
	return false;
}

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
	double n, l, w;
    while (scanf("%lf %lf %lf", &n, &l, &w) != EOF) {
    	w /= 2.;
    	bool isCan = true;
    	std::vector<interval> arr;

    	double maxright = -1;
    	REP(i, 0, n) {
    		double x, r;
    		cin >> x >> r;
    		double d = 0;
    		if (w - r < -esp) 
    			d = sqrt(r*r - w*w);
    		arr.push_back({x-d, x+d});
    		maxright = max(maxright,x+d);
    	}
    	sort(arr.begin(), arr.end(), cmp);
    	

    	if (arr[0].left > esp || maxright - l < -esp) isCan = false;
    	int res = 0;
    	double rightMost = 0;
    	int index = 0;
    	while (index < n && isCan && rightMost - l < -esp) {
    		int select = -1;
    		double maxright = rightMost;
    		REP(i, index, n) {
    			if (arr[i].left <= rightMost && arr[i].right > maxright) {
    				select = i;
    				maxright = arr[i].right;
    			}
    		}
    		if (select == -1) isCan = false;
    		res++;
    		rightMost = maxright;
    		index = select;
    	}
    	if (isCan) {
    		cout << res << endl;
    	} else {
    		cout << -1 << endl;
    	}
    }
    return 0;
}
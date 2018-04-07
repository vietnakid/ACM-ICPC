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

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)

#define INF 2000000000 // 2e9
#define INFLL 2000000000000000000 // 2e18
#define esp 0.0000000001
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int h1, a1, c1, h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    vi arr;
    while (h2 > 0) {
    	if (h2 <= a1) {
    		arr.push_back(0);
    		h2 -= a1;
    		break;
    	}
    	
    	if (h1 <= a2) {
    		arr.push_back(1);
    		h1 += c1;
    	} else {
    		arr.push_back(0);
    		h2 -= a1;
    	}

    	h1 -= a2;
    }
    cout << arr.size() << endl;
    FOR(i, 0, arr.size()) {
    	if (arr[i] == 0) {
    		cout << "STRIKE" << endl; 
    	} else {
    		cout << "HEAL" << endl; 
    	}
    }
    return 0;
}
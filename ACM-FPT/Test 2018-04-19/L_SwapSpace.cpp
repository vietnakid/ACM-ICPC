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

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i++)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n;
    scanf("%d", &n);
    vii arr, brr;
    FOR(i, 0, n) {
    	int c, n;
    	scanf("%d %d", &c, &n);
    	if (c < n) {
    		arr.push_back({c, n});
    	} else {
    		brr.push_back({n, c});
    	}
    }

    ll need = 0, free = 0;
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end(), greater<ii>());

    FOR(i, 0, arr.size()) {
    	if (arr[i].first > free) {
    		need += arr[i].first - free;
    		free = arr[i].second;
    	} else {
    		free -= arr[i].first;
    		free += arr[i].second;
    	}
    }

    FOR(i, 0, brr.size()) {
    	if (brr[i].second > free) {
    		need += brr[i].second - free;
    		free = brr[i].first;
    	} else {
    		free -= brr[i].second;
    		free += brr[i].first;
    	}
    }
    cout << need << endl;
    return 0;
}
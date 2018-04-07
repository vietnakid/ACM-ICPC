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
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
    	int n;
    	cin >> n;
    	int start = 1, end = 0;
    	int sum = 0, res = 0, rstart = 1, rend = 1;
    	FOR(i, 1, n) {
    		end = i;
    		int x;
    		cin >> x;
    		sum += x;
    		if (sum == res) {
    			if (end - start > rend - rstart) {
    				res = sum;
    				rend = end;
    				rstart = start;
    			}
    		} else if (sum > res) {
				res = sum;
				rend = end;
				rstart = start;
    		}
    		if (sum < 0) {
    			sum = 0;
    			start = i + 1;
    		}
    	}
    	if (res == 0) {
	    	printf("Route %d has no nice parts\n", tc);
	    } else {
	    	printf("The nicest part of route %d is between stops %d and %d\n", tc , rstart, rend+1);
	    }
    }
    
    return 0;
}
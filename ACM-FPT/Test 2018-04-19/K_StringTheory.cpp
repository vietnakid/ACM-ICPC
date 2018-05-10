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
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int n;
vi arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n;
    arr = vi(n);
    int sum = 0;
    FOR(i, 0, n) {
    	cin >> arr[i];
    	sum += arr[i];
    }
    if (sum % 2 != 0) {
    	cout << "no quotation" << '\n';
    } else {
    	int res = -1; 
	    FORD(i, arr[0], 2) {
	    	vi tmp = arr;
	    	int indexl = 0, indexr = n-1, level = i;
	    	while (level != 0) {
	    		if (tmp[indexl] >= level && tmp[indexr] >= level) {
	    			if (tmp[indexl] >= level) {
	    				tmp[indexl] -= level;
		    			if (tmp[indexl] == 0) {
		    				indexl++;
		    			}	
	    			}
	    			if (tmp[indexr] >= level) {
	    				tmp[indexr] -= level;
		    			if (tmp[indexr] == 0) {
		    				indexr--;
		    			}	
	    			} else {
	    				break;
	    			}
	    			level--;
	    		} else {
	    			break;
	    		}
	    	}
	    	if (level == 0) {
	    		res = i;
	    		break;
	    	}
	    }
	    // case for level == 1
	    if (n == 1 && arr[0] == 2)
	    	res = 1;
	    if (n == 2 && arr[0] == 1 && arr[1] == 1)
	    	res = 1;

	    if (res == -1) {
	    	cout << "no quotation" << '\n';
	    } else {
	    	cout << res << '\n';
	    }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int main()
{
	// freopen("input.in", "r", stdin);
	int test = 0;
    while (true) {
    	int k;
    	cin >> k;
    	if (k == 0) break;
    	if (test != 0) cout << endl;
    	test++;

    	vi arr(k);
    	REP(i, 0, k) {
    		cin >> arr[i];
    	}

    	for(int i1 = 0; i1 < k - 5; i1++)
    		for(int i2 = i1+1; i2 < k - 4; i2++)
    			for(int i3 = i2+1; i3 < k - 3; i3++)
    				for(int i4 = i3+1; i4 < k - 2; i4++)
    					for(int i5 = i4+1; i5 < k - 1; i5++)
    						for(int i6 = i5+1; i6 < k; i6++)
    							cout << arr[i1] << " " << arr[i2] << " " << arr[i3] << " " << arr[i4] << " " << arr[i5] << " " << arr[i6] << endl;
    }
    return 0;
}

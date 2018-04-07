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

bool isOn(int s, int i) {
	return s & (1 << i);
}

void printa(vi & a) {
	int n = a.size();
	if (n == 0) return;
	REP(i, 0, n-1) cout << a[i] << "+";
	cout << a[n-1] << endl;
}

int main()
{
    while(true) {
    	int t, n;
    	cin >> t >> n;
    	if (n == 0) break;
    	cout << "Sums of " << t << ":" << endl;
    	int cnt = 0;
    	vi arr(n);
    	REP(i, 0, n) cin >> arr[i];

    	set< vi > setres;
    	for (int i = (1<<n)-1; i >= 0; i--) {
    		vi a;
    		int sum = 0;
    		for (int j = n -1; j >= 0; j--)
    			if (isOn(i, j)) {
    				a.push_back(arr[n-j-1]);
    				sum += arr[n-j-1];
    			}

    		if (sum == t && setres.find(a) == setres.end()) {
    			setres.insert(a);
    			printa(a);
    			cnt++;
    		}
    	}
    	if (cnt == 0) {
    		cout << "NONE" << endl;
    	}
    }
    return 0;
}

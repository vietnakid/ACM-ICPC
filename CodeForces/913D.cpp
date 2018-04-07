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

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

bool comp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	return a.second.first < b.second.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int n, t;
    cin >> n >> t;

    vector<pair<int, pair<int, int> > > arr;
    FORE(i, 1, n) {
    	int a, b;
    	cin >> a >> b;
    	arr.push_back(make_pair(a, make_pair(b, i)));
    }
    sort(arr.begin(), arr.end());
    int low = 0, high = n, res = 0;
    vi ress;
    while (low <= high) {
    	int m = (low + high) / 2;
    	vector<pair<int, pair<int, int> > > brr = arr;
    	vector<pair<int, pair<int, int> > >::iterator it = lower_bound(brr.begin(), brr.end(), make_pair(m, make_pair(0, 0)));

    	sort(it, brr.end(), comp);
    	int time = 0;
    	FOR(i, 0, m) {
    		if (it == brr.end()) {
    			time = t + 1;
    			break;	
    		} 
    		else
    			time += it->second.first;
    		it++;
    	}
    	// cout << m << " " << distance(brr.begin(), it) << " " << time << endl;
    	if (time <= t) {
    		low = m+1;
    		res = m;
    	} else {
    		high = m-1;
    	}
    }

    cout << res << endl << res << endl;

    vector<pair<int, pair<int, int> > > brr = arr;
    vector<pair<int, pair<int, int> > >::iterator it = lower_bound(brr.begin(), brr.end(), make_pair(res, make_pair(0, 0)));
    sort(it, brr.end(), comp);
	FOR(i, 0, res) {
		cout << it->second.second << " ";
		it++;
	}
	cout << endl;
    return 0;
}
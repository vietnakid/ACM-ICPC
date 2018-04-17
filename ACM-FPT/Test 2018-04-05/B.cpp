#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<ll, ll> ii;
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

priority_queue <ii, vector<ii>, greater<ii> > pq;

ll n, k, a, b;
vvi arr;
vi d;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);d
	// freopen("output", "w", stdout);
	cin >> n >> k >> a >> b;
	arr = vvi(n+1);
	bool isFuck = false;
	FOR(i ,0, k) {
		int u, v;
		cin >> u >> v;
		if (u == 1 && v == n || u ==n && v == 1) 
			isFuck = true;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	d = vi(n+1, INF);
	d[1] = 0;
	int i, u, v, du, uv;
	pq.push(ii(0, 1));
	vi isFree(n+1, 0);

    while (pq.size()){
        u=pq.top().second;
        du=pq.top().first;
        pq.pop();
        if (isFree[u] == 1) continue;
        isFree[u] = 1;

        for (i=0; i < arr[u].size(); i++)
        {
        	v = arr[u][i];
            if (d[v]>du+1) {
                d[v]=du+1;
                pq.push(ii(d[v], v));
            }
        }
    }
    if (isFuck) {
    	if (a < b) {
    		cout << a << endl;
    	} else {
    		int minn = INF;
	    	FOR(i, 2, n+1) {
	    		if (arr[i].size() != n-1) {
	    			minn = min(d[i], minn);
	    		}
	    	}
	    	if (minn = d[n]) {
				cout << minn*a << endl;	
	    	} else {
	    		cout << minn*a+b << endl;	
	    	}
    	}
    } else {
    	cout << min(a * ll(d[n]), b) << endl;	
    }
    return 0;
}
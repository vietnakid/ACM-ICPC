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

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
	int n, r, k;
    cin >> n >> r >> k;
    set<int> res;
    set<int>::iterator it;
    set<int> arr;
    REP(i,1,(int)sqrt(k)+1)
    if (k%i==0){
        if (i<=r) 
        	arr.insert(i);
        if (k/i<=r) 
        	arr.insert(k/i);
    }
    
    while (true) {
    	int maxx = 1;
    	for (int i = sqrt(k); i >= 1; i--)  {
		    if (k%i==0 && res.find(i) == res.end()){
    			maxx = i;
    			break;
		    }
		}
	    if (maxx == 1) break;
	    res.insert(maxx);
	    k /= maxx;
    }
    
    for(it=res.begin(); it!=res.end(); it++) cout << *it << " "; cout	 << endl;
    if (k != 1) {
    	cout << "-1" << endl;
    	return 0;
    }
    for(it=arr.begin(); it!=arr.end(); it++) {
    	if (res.size() >= n) break;
    	res.insert(*it);
    }
    if (res.size() == n)
    	for(it=res.begin(); it!=res.end(); it++) cout << *it << " ";
    else {
    	cout << "-1" << endl;
    }
    return 0;
}
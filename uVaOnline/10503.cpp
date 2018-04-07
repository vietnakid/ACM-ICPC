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

int n, m;
vii arr, res;
ii head, tail;
bool isDone;
bitset<20> isFree;

bool isMatch(ii a, ii b) {
	return a.second == b.first;
}

ii swapdir(ii a) {
	int tmp = a.first;
	a.first = a.second;
	a.second = tmp;
	return a;
}

void sovle(int pos) {
	if (pos == n) {
		if (isMatch(res[n-1], tail)) isDone = true;
	} else {

		for(int i = 0; !isDone && i < m; i++) {
			// cout << pos << " " << i << " " << isFree[i] << endl;
			// REP(i, 0, 20) cout << isFree[i] << " ";
   //  		cout << endl;
			if (isFree[i]) {
				ii tmp = arr[i];
				REP(dir, 0, 2) {
					tmp = swapdir(tmp);
					bool isOk = false;
					if (pos == 0) {
						isOk = isMatch(head, tmp);
					} else {
						isOk = isMatch(res[pos-1], tmp);
					}
					if (isOk) {
						res[pos] = tmp;
						isFree[i] = false;
						sovle(pos+1);
						isFree[i]=true;
					}
				}
			}
		}
	}
}

int main()
{
    while (true) {
    	cin >> n;
    	if (n == 0) break;
    	cin >> m;
    	cin >> head.first >> head.second;
    	cin >> tail.first >> tail.second;
    	arr = vii(m);
    	res = vii(n);
    	REP(i, 0, m) {
    		cin >> arr[i].first >> arr[i].second;
    	}
    	isDone = false;
    	isFree.set();
    	sovle(0);
    	if (isDone) {
    		cout << "YES" << endl;
    	} else {
    		cout << "NO" << endl;
    	}
    }
    return 0;
}

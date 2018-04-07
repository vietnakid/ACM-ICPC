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

bool prime[100];
int n;
vi arr(20);
bitset<20> isFree;
int TC = 0;

bool isPrime(int x) {
	bool res = true;
	REP(i, 2 , x) if (x % i == 0) res = false;
	return res;
}

void init() {
	prime[0] = false;
	prime[1] = false;
	REP(i, 2, 100) {
		prime[i] = isPrime(i);
	}
}

void backtrack(int pos) {
	if (pos == n) {
		if (prime[arr[0] + arr[n-1]]) {
			REP(i, 0, n-1) cout << arr[i] << " ";
			cout << arr[n-1];
			cout << endl;
		}
	} else {
		REP(i, 2, n+1) {
			if (isFree[i] && prime[arr[pos-1] + i]) {
				isFree[i] = false;
				arr[pos] = i;
				backtrack(pos + 1);
				isFree[i] = true;
			}
		}
	}
}

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
	init();
	string s;
    while (getline(cin, s)) {
    	stringstream ss(s);
    	ss >> n;
    	if (TC) cout << endl;
    	TC++;
    	isFree.set();
    	printf("Case %d:\n", TC);
    	arr[0] = 1;
    	isFree[1] = false;
    	backtrack(1);
    }
    return 0;
}

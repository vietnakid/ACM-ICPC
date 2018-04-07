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
    int cnt = 0;
    while (true) {
    	int n, res= 0;
    	cin >> n;
    	if (n == 0) break;
    	if (cnt != 0) {
    		cout << endl;
    	}

    	for (int b = 1234; b <= 98765 / n; b++)	{
    		int a = b * n;
    		int tmp, used = (b < 10000);
    		tmp = a;
    		while (tmp) {
    			used |= (1 << (tmp % 10));
    			tmp /= 10;
    		}

    		tmp = b;
    		while (tmp) {
    			used |= (1 << (tmp % 10));
    			tmp /= 10;
    		}

    		if (used == (1 << 10) - 1) {
    			if (b >= 10000)
    				cout << a << " / " << b << " = " << n << endl;
    			else 
    				cout << a << " / 0" << b << " = " << n << endl;
    			res++;
    		}
    	}
    	if (res == 0) {
			cout << "There are no solutions for " << n << "." << endl;
		}
		cnt++;
    }
    return 0;
}

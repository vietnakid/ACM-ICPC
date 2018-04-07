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
	// freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	for (ll i1 = 1; i1 <= 500; i1++)
		for (ll i2 = i1; i1 + i2*3 <= 2000; i2++)
			for (ll i3 = i2; i1 + i2 + i3*2 <= 2000; i3++) {
				if (i1*i2*i3 != 1000000 && 1000000*(i1+i2+i3) % (i1*i2*i3 - 1000000) == 0) {
					ll i4 = 1000000*(i1+i2+i3) / (i1*i2*i3 - 1000000);
					if (i4 >= i3 && i1+i2+i3+i4 <= 2000) {
						printf("%.2f %.2f %.2f %.2f\n", (double)i1/100, (double)i2/100, (double)i3/100, (double)i4/100);
					}
				}
			}
    return 0;
}

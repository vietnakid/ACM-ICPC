#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 1e9+7
#define INFLL 1e18+7
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n;
    while (cin >> n) {
        cout << "TERM " << n << " IS ";
        // if (n == 1) {
        //     cout << "1/1" << endl;
        //     continue;
        // }
        int x = sqrt(n);
        
        while (x * (x+1) / 2 < n) {
            x++;
        }
        int y = x * (x-1) / 2 + 1;
        int a = 1,b = x;
        a += n - y;
        b -= n - y;
        if (x % 2 != 0) {
            swap(a, b);   
        }
        
        cout << a << "/" << b << endl;
    }
    return 0;
}
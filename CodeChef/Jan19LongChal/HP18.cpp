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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, a, b;
int sa, sb, sc;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int TC; cin >> TC;
    while (TC--) {
        cin >> n >> a >> b;
        sa = 0;
        sb = 0;
        sc = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % a == 0 && x % b != 0) sa++;
            if (x % a != 0 && x % b == 0) sb++;
            if (x % a == 0 && x % b == 0) sc++;
        }
        if (a == b) {
            if (sc > 0) cout << "BOB" << endl;
            else cout << "ALICE" << endl;
        } else {
            if (sc == 0) {
                if (sa > sb) cout << "BOB" << endl;
                else cout << "ALICE" << endl;
            } else {
                if (sb > sa) cout << "ALICE" << endl;
                else cout << "BOB" << endl;
            }
        }
        
    }
    return 0;
}
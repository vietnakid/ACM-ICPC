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

ll n, x, y, z;
int type;
ll A, B; 

void sovle() {
    A = 1;
    B = 2*n + 1;
    if (type == 1) {
        A = z;
        if ((x-y)*(y-z) > 0) {
            A = B - A;
        }
    } else if (type == 2 || type == 4) {
        if (x == z) {
            A = 0;
            B = 1;
        } else {
            A = 2*y;
            A = B - A;
        }
    } else if (type == 3) {
        A = x;
        if ((x-y)*(y-z) > 0) {
            A = B - A;
        }
    }
    ll G = GCD(A, B);
    A /= G;
    B /= G;
    cout << A << " " << B << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int TC; cin >> TC;
    while (TC--) {
        cin >> n >> type >> x >> y >> z;
        sovle();
    }
    return 0;
}
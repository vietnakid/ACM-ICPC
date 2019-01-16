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

int n;
string s;
bitset<500005> check;
int minOpen = INF, maxClose = 0;

void init(){ 
    check[0] = false;
    for (int i = 1; i < n; i++) {
        check[i] = check[i-1];
        if (s[i-1] == '[') {
            check[i] = true;
        }
    }
    
    for (int i = 1; i < n; i++) {
        if (check[i] && s[i-1] == ':') {
            minOpen = min(minOpen, i);
        }
    }


    check[n+1] = false;
    for (int i = n; i >= 1; i--) {
        check[i] = check[i+1];
        if (s[i-1] == ']') {
            check[i] = true;
        }
    }

    for (int i = n; i >= 1; i--) {
        if (check[i] && s[i-1] == ':') {
            maxClose = max(maxClose, i);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> s;
    n = s.size();

    init();
    // cerr << minOpen << " " << maxClose << endl;
    if (minOpen < maxClose) {
        int res = 4;
        for (int i = minOpen; i < maxClose; i++) {
            res += s[i-1] == '|';
        }
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
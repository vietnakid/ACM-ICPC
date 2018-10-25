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
    int n, m;
    cin >> n >> m;
    string a, b, s, s1;
    cin >> a >> b;

    int sao = -1;
    FOR(i, 0, n) {
        if (a[i] == '*') {
            sao = i;
            break;
        }
    }
    if (sao == -1) {
        s = a;
    } else {
        s = a.substr(0, sao);

        s1 = a.substr(sao+1);
        
        while (s.size() + s1.size() < b.size()) {
            s.push_back(b[sao]);
            sao++;
        }
        s += s1;
    }
    
    if (s == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
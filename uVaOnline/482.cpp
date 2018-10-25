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
    string input;
    getline(cin, input);
    stringstream ss(input);
    int TC;
    ss >> TC;
    getline(cin, input);
    FOR(tc, 0, TC) {
        if (tc != 0) {
            cout << endl;
        }
        getline(cin, input);
        stringstream ss1(input);
        vi pos;
        int x;
        while (ss1 >> x) {
            x--;
            pos.push_back(x);
        }
        int n = pos.size();
        vi arr(n);
        FOR(i, 0, n) {
            arr[pos[i]] = i;
        }
        getline(cin, input);
        stringstream ss2(input);
        vector<string> value;
        string y;
        while (ss2 >> y) {
            value.push_back(y);
        }
        getline(cin, input);
        FOR(i, 0, n) {
            cout << value[arr[i]] << endl;
        }
    }
    return 0;
}
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

#define INF 1000000007
#define INFLL 1000000000000000000
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
    cin >> n;
    vi arr(n+1);
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    int Res = INF;
    FOR(t, 0, 12) {
        int res = t;
        vi tmp = arr;

        tmp[0] = (tmp[0] - t);
        if (tmp[0] < 0) {
            tmp[0] += 12;
        }
        if (tmp[0] == 0) {
            tmp[0] = 12;
        }

        FOR(i, 0, n) {
            int x = 12 - tmp[i];
            res += x;
            tmp[i+1] -= x;
            if (tmp[i+1] < 0) {
                tmp[i+1] += 12;
            }
            if (tmp[i+1] == 0) {
                tmp[i+1] = 12;
            }
        }
        Res = min(Res, res);
    }
    cout << Res << endl;
    return 0;
}
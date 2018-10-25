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

vvl arr;
ll n;
ll Res = 0;
ll sum = 0;
vl back(2, 0);
int leng = 0;

void nextStep(ll time, ll x, ll y, ll res) {
    
    if (time < 2*n - 1) {
        if (time % 2 != 0) {
            nextStep(time+1, x, y + 1, res + time * arr[x][y]);
        } else {
            nextStep(time+1, 1 - x, y, res + time * arr[x][y]);
        }
    }
    leng++;
    sum += arr[x][y];
    // cerr << time << " " << res << " " << x << " " << y << " " << arr[x][y] << endl;
    Res = max(Res, res + time*sum + back[x]);
    back[x] += sum;
    back[1-x] += arr[x][y] * leng;
    // cerr << res + time*sum + back[x] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n;
    arr = vvl(2, vl(n));
    FOR(i, 0, n) cin >> arr[0][i];
    FOR(i, 0, n) cin >> arr[1][i];
    nextStep(0, 0, 0, 0);
    cout << Res << endl;
    return 0;
}
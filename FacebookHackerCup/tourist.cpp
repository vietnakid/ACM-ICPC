#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	//freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	//freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;
    FORE(tc, 1, TC) {
        ll n, k, v;
        cin >> n >> k >> v;
        vector<string> arr(n+1);
        FORE(i, 1, n ) {
            cin >> arr[i];
        }
        ll index = k * (v-1) % n;
        vector<string> res;
        index++;
        int i = 0;
        while (index <= n && i < k) {
            res.push_back(arr[index]);
            index++;
            i++;
        }
        index = 1;
        vector<string> res2;
        while (i < k) {
            res2.push_back(arr[index]);
            index++;
            i++;
        }
        res.insert(res.begin(), res2.begin(), res2.end());
        cout << "Case #" << tc << ": ";
        
        FOR(i, 0, k) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
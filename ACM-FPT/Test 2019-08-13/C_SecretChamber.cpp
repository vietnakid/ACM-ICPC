#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

#define FOR(i, a, b) \
for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
for (int i = (a); i <= (b); i++)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
//    freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n, m;
    cin >> n >> m;
    vvi arr(26);
    FOR(i, 0, 26) arr[i] = vi(26, 0);
    FOR(i, 0, 26) arr[i][i] = 1;
    FOR(i, 0, n) {
        char a, b;
        cin >> a >> b;
        a -= 'a';
        b -= 'a';
        arr[a][b] = 1;
    }
    FOR(k, 0, 26)
    FOR(i, 0, 26)
    FOR(j, 0, 26) {
        if (arr[i][k] && arr[k][j])
            arr[i][j] = 1;
    }
    FOR(i, 0, m) {
        string a, b;
        cin >> a >> b;
        if (a.size() != b.size()) {
            cout << "no" << endl;
        } else {
            bool ok = true;
            FOR(ii, 0, a.size()) {
                char x = a[ii] - 'a';
                char y = b[ii] - 'a';
                if (arr[x][y] == 0) {
                    cout << "no" << endl;
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "yes" << endl;
            }
        }
    }
    return 0;
}

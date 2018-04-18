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

int dx[] = {0, 0, -1 , -1 , -1, 1, 1, 1};
int dy[] = {-1, 1, -1, 0, 1, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;
    while (TC--) {
        string a, b;
        cin >> a >> b;
        int l1 = a.size(), l2 = b.size();
        vvi arr(l1);
        FOR(i, 0, l1)
        arr[i] = vi(26, 0);
        vi brr(26, 0);
        arr[0][a[0] - 'a'] = 1;
        FOR(i, 1, l1) {
            FOR(j, 0, 26) arr[i][j] = arr[i-1][j];
            arr[i][a[i] - 'a']++;
        }
        FOR(i, 0, l2) {
            brr[b[i] - 'a']++;
        }
        bool ok = false;
        FOR(i, l2-1, l1) {
            int okNested = true;
//            cout << "i = " << i << endl;
            FOR(j, 0, 26) {
                int x;
                if (i-l2 == -1)
                    x = arr[i][j];
                else
                    x = arr[i][j] - arr[i-l2][j];
                int y = brr[j];
//                cout << x << " " << y << endl;
                if (x != y) okNested = false;
            }
            if (okNested) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

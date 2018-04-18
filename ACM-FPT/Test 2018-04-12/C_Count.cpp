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
    // freopen("/Users/macbook/Downloads/p282.t1.in", "r", stdin);
    int n = 2, m;
    fread(&n, sizeof(n), 1, stdin);
    fread(&m, sizeof(int), 1, stdin);
    vvi arr(n);
    FOR(i, 0, n) arr[i] = vi(m);
    FOR(i, 0, n)
    FOR(j, 0, m)
        fread(&arr[i][j], sizeof(int), 1, stdin);
    while (true) {
        int a = -INF, b = INF;
        fread(&a, sizeof(int), 1, stdin);
        fread(&b, sizeof(int), 1, stdin);
        if (b == INF) break;
        int total = 0;
        FOR(i, 0, n) {
            vi::iterator lower = lower_bound(arr[i].begin(), arr[i].end(), a);
            vi::iterator upper = upper_bound(arr[i].begin(), arr[i].end(), b);
            total += upper - lower;
        }
        cout << total << endl;
    }
    return 0;
}

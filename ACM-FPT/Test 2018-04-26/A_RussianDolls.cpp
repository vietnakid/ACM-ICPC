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

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
//    freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n;
    cin >> n;
    multiset<int> mset;
    vii arr(n);
    int res = 0;
    FOR(i, 0, n) {
        int out, in, c;
        cin >> out >> in >> c;
        mset.insert(out);
        arr[i] = {c, in};
        res += c * in;
    }
    sort(arr.begin(), arr.end(), greater<ii>());
    FOR(i, 0, n) {
        int in  = arr[i].second;
        int c = arr[i].first;
        multiset<int>::iterator it = lower_bound(mset.begin(), mset.end(), in);
        if (it == mset.begin()) continue;
        it--;
        res -= c * *it;
        mset.erase(it);
    }
    cout << res << endl;
    return 0;
}

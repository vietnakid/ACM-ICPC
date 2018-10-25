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
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vii arr;
        arr.push_back({n, 1});
        int m = arr[arr.size() - 1].first;
        while (m != 1) {
            if (arr[arr.size() - 1].second == 0) {
                if (m % 2 == 0) {
                    arr.push_back({m/2, 0});
                } else {
                    arr.push_back({m/2+1, 1});
                }
            } else {
                if (m % 2 == 0) {
                    arr.push_back({m/2, 1});
                } else {
                    arr.push_back({m/2, 0});
                }
            }
            m = arr[arr.size() - 1].first;
        }
        // FOR(i, 0, arr.size()) {
        //     cerr << arr[i].first << " " << arr[i].second << endl;
        // }
        int pos = 1;
        FORD(i, arr.size() - 2, 0) {
            if (arr[i].second == 0) {
                pos = (pos-1)*2 + 1;
            } else {
                pos *= 2;
            }
        }
        cout << pos << endl;
    }
    return 0;
}
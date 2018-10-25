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
#define INFLL 1e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

set<ll> like;
set<ll> hate;
bool isLikeFirst = true;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n; cin >> n;
    FOR(i, 0, n) {
        int c, k; cin >> c >> k;
        if (c == 1) {
            if (isLikeFirst) {
                FOR(j, 0, k) {
                    ll x;
                    cin >> x;
                    if (hate.find(x) == hate.end()) {
                        like.insert(x);
                    }
                }
                isLikeFirst = false;
            } else {
                set<ll> tmpLike;
                FOR(j, 0, k) {
                    ll x;
                    cin >> x;
                    if (like.find(x) != like.end()) {
                        tmpLike.insert(x);
                    }
                }
                like = tmpLike;
            }
        } else {
            FOR(j, 0, k) {
                ll x;
                cin >> x;
                if (isLikeFirst) {
                    hate.insert(x);
                }
                if (like.find(x) != like.end()) {
                    like.erase(x);
                }
            }
        }
    }
    
    if (isLikeFirst) {
        cout << 1000000000000000000 - hate.size() << endl;
    } else {
        cout << like.size() << endl;
    }
    return 0;
}
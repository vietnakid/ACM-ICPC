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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

map<ii, vii> mp;

void init() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mp[{i|j, i&j}].push_back({i, j});
            if (i + j != (i|j) + (i&j)) {
                cout << i << " " << j << "\n";
            }
        }
    }

    for (auto v : mp) {
        cerr << "\n" << v.first.first << " " << v.first.second << "\n";
        for (auto x : v.second) {
            cerr << "{" << x.first << ", " << x.second << "}, ";
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    init();
    return 0;
}
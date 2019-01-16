#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

// struct PT {
//     ll x, y, index;
//     bool operator < (const PT & other) const {
//         return make_pair(make_pair(x, y), index) < make_pair(make_pair(other.x, other.y), other.index);
//     }
// };

// vector<PT> arr;
vector<pair<ii, int> > arr;
map<ll, ll> BIT;
ll res[100005];
ll w, h;
int n;

ll getBIT(ll x) {
    ll res = 0;
    while (x > 0) {
        if (BIT.count(x)) {
            res += BIT[x];
        }
        x -= x & (-x);
    }
    return res;
}

void setBIT(ll x, ll value) {
    while (x <= h) {
        BIT[x] += value;
        x += x & (-x);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    scanf("%lld %lld %d", &w, &h, &n);
    w = w*2;
    h = h*2+1;
    double x, y;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        x *= 2;
        y *= 2;
        y++;
        arr.push_back({{(ll)x, (ll)y}, i});
    }
    sort(arr.begin(), arr.end());
    ll r;
    for (int i = 0; i < n; i++) {
        r = arr[i].first.first - getBIT(arr[i].first.second);
        res[arr[i].second] = r;
        setBIT(arr[i].first.second - r, 2*r);
        setBIT(arr[i].first.second + r, -2*r);
        // cerr << arr[i].x << " " << arr[i].y << " " << 2*r << endl;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld\n", res[i]);
    }
    return 0;
}
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

ll fish[] = {1, 0, 0, 1, 0, 0, 1};
ll rabbit[] = {0, 1, 0, 0, 0, 1, 0};
ll chicken[] = {0, 0, 1, 0, 1, 0, 0};
ll sumFish = 3, sumRabbit = 2, sumChicken = 2;

void vietnakid() {
	ll a, b, c;
    ll res = 0;
    cin >> a >> b >> c;
    for (int i = 0; i < 7; i++) {
        ll _a = a, _b = b, _c = c;
        ll sum = 0;
        int j = i;
        while (j < 7 && _a - fish[j] >= 0 && _b - rabbit[j] >= 0 && _c - chicken[j] >= 0) {
            _a -= fish[j];
            _b -= rabbit[j];
            _c -= chicken[j];
            sum++;
            j++;
        }
        int week = min(_a / sumFish, min(_b / sumRabbit, _c / sumChicken));
        sum += 7 * week;
        _a -= sumFish * week;
        _b -= sumRabbit * week;
        _c -= sumChicken * week;
        j = 0;
        while (j < 7 && _a - fish[j] >= 0 && _b - rabbit[j] >= 0 && _c - chicken[j] >= 0) {
            _a -= fish[j];
            _b -= rabbit[j];
            _c -= chicken[j];
            sum++;
            j++;
        }
        res = max(res, sum);
    }
    cout << res << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
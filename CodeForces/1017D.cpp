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
    for (int i = (a); i ^ (b); i++)
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

int n, m, q;
vi cnt;
vi w;
vvi st;
vvi sum;

int bin2dec(ll x) {
    int res = 0;
    int k = 1;
    while (x > 0) {
        res += (x % 10) * k;
        x /= 10;
        k <<= 1;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    scanf("%d %d %d", &n, &m, &q);
    int nn = 1 << n;
    cnt = vi(nn, 0);
    w = vi(n, 0);
    FORD(i, n-1, 0) {
        scanf("%d", &w[i]);
    }
    st = vvi(nn, vi(nn, 0));
    sum = vvi(nn, vi(101, 0));
    ll x;
    FOR(i, 0, m) {
        scanf("%lld", &x);
        x = bin2dec(x);
        cnt[x]++;
    }
    FOR(i, 0, nn) {
        FOR(bit, 0, n) {
            int b = (i >> bit) & 1;
            b <<= bit;
            int lowBits = 0;
            int highBits = 0;
            FOR(j, 0, bit) {
                lowBits |= 1 << j;
            }
            FOR(j, bit, n-1) {
                highBits |= 1 << j;
            }
            int low, high, num;
            FOR(j, 0, 1 << (n-1)) {
                low = j & lowBits;
                high = j & highBits;
                high <<= 1;
                num = low | b | high;
                st[i][num] += w[bit];
            }
        }
    }

    FOR(i, 0, nn) {
        FOR(j, 0, nn) {
            if (st[i][j] <= 100) {
                sum[i][st[i][j]] += cnt[j];
            }
        }
        FOR(j, 1, 101) {
            sum[i][j] += sum[i][j-1];
        }
    }

    int y;
    FOR(i, 0, q) {
        scanf("%lld %d", &x, &y);
        x = bin2dec(x);
        printf("%d\n", sum[x][y]);
    }
    
    return 0;
}
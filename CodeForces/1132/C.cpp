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

int n, q;
vii query;
int sum[5005];
vi BIT1(5005), BIT2(5005);

void update(vi & BIT, int x) {
    while (x < 5005) {
        BIT[x]++;
        x += x & (-x);
    }
}

ll get(vi & BIT, int x) {
    ll res = 0;
    while (x > 0) {
        res += BIT[x];
        x -= x & (-x);
    }
    return res;
}

ll getRange(vi & BIT, int l, int r) {
    if (l > r) {
        return 0;
    }
    return get(BIT, r) - get(BIT, l-1);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> q;
    query.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> query[i].first >> query[i].second;
        sum[query[i].first]++;
        sum[query[i].second+1]--;
    }
    
    int total = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i-1];
        if (sum[i] == 1) {
            update(BIT1, i);
        } 
        if (sum[i] == 2) {
            update(BIT2, i);
        }
        if (sum[i] != 0) {
            total++;
        }
    }

    sort(query.begin(), query.end());
    int res = 0;
    for (int i = 0; i < q; i++) {
        for (int j = i+1; j < q; j++) {
            if (query[i].second >= query[j].first) {
                int l = query[i].first;
                int m1 = query[j].first;
                int m2 = min(query[i].second, query[j].second);
                int r = max(query[i].second, query[j].second);
                int cnt = getRange(BIT1, l, m1-1);
                // cerr << l << " " << m1 << " " << m2 << " " << r << "\n";
                // cerr << cnt << "\n";
                cnt += getRange(BIT2, m1, m2);
                // cerr << cnt << "\n";
                cnt += getRange(BIT1, m2+1, r);
                res = max(res, total - cnt);
                // cerr << res << " " << cnt << "\n";
            } else {
                int l = query[i].first;
                int r = query[i].second;
                int cnt = getRange(BIT1, l, r);
                // cerr << l << " " << r << '\n';
                // cerr << cnt << "\n";
                l = query[j].first;
                r = query[j].second;
                cnt += getRange(BIT1, l, r);
                res = max(res, total - cnt);
                // cerr << l << " " << r << '\n';
                // cerr << cnt << "\n";
            }
        }
    }
    cout << res << '\n';
    return 0;
}
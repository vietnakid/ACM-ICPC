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

ll nMod = 998244353;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

ll n, k;
int arr[200005];
vl a;
ll RES = 0;
ll same[200005], diff[200005];

ll calDiff(int leng);

ll addMod(ll a, ll b) {
    return a+b > nMod ? a+b-nMod : a+b;
}

ll mulMod(ll a, ll b) {
    if (a != 0)
        if (b != 0)
            return (a*b) % nMod;
        else
            return a;
    else return b;

}

ll calSame(int leng) {
    if (leng <= 0) return 0;
    if (leng == 1) return k-1;   

    ll & res = same[leng];
    if (res != -1) return res;
    res = (calDiff(leng-1) * (k-1)) % nMod;
    return res;
}

ll calDiff(int leng) {
    if (leng <= 0) return 0;
    if (leng == 1) return k-2;   

    ll & res = diff[leng];
    if (res != -1) return res;
    res = addMod((calDiff(leng-1) * (k-2)) % nMod, calSame(leng-1));
    return res;
}

ll cal() {
    ll st = a[0], nd;
    ll cnt = 0, res = 1;
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i] == -1) {
            cnt++;
        } else {
            nd = a[i];
            if (st == nd) {
                if (cnt == 0) {
                    cout << 0 << "\n";
                    exit(0);
                }
                if (st == INF) {
                    ll r = k;
                    for (int j = 1; j < cnt; j++) {
                        r = (r * (k-1)) % nMod;
                    }
                    res = mulMod(res, r);
                } else {
                    res = mulMod(res, calSame(cnt));
                }
            } else {
                if (st == INF || nd == INF) {
                    if (cnt == 1) {
                        res = mulMod(res, k-1);
                    } else {
                        res = mulMod(res, addMod(calSame(cnt-1), (calDiff(cnt-1) * (k-1)) % nMod));
                    }
                } else {
                    if (k == 2 && cnt > 0) {
                        cout << 0 << "\n";
                        exit(0);
                    }
                    res = mulMod(res, calDiff(cnt));
                }
            }
            // cerr << st << " -> " << nd << "; cnt = " << cnt << " | res = " << res << "\n";
            st = nd;
            cnt = 0;
            
        }
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);

    memset(same, -1, sizeof(same));
    memset(diff, -1, sizeof(diff));

 	cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    a.push_back(INF);
    for (int i = 0; i < n; i+=2) {
        a.push_back(arr[i]);
    }
    a.push_back(INF);
    RES = cal();

    cerr << RES << "\n";
    a.clear();
    a.push_back(INF);
    for (int i = 1; i < n; i+=2) {
        a.push_back(arr[i]);
    }
    a.push_back(INF);
    RES = (RES * cal()) % nMod;
    cout << RES << "\n";
    return 0;
}
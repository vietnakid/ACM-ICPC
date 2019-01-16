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

int n, m;
ll arr[35];
map<ll, int> s1, s2;
vector<ll> luckyNumber;
vvi res;

void init() {
    ll sum = 0;
    for (int leng = 1; leng <= 10; leng++) {
        sum = sum * 10 + 4;
        luckyNumber.push_back(sum);
    }
    sum = 0;
    for (int leng = 1; leng <= 10; leng++) {
        sum = sum * 10 + 7;
        luckyNumber.push_back(sum);
    }
    sort(luckyNumber.rbegin(), luckyNumber.rend());
    m = n / 2;
    for (int state = 0; state < (1<<m); state++) {
        ll sum = 0;
        for (int i = 0; i < m; i++) {
            if ((state >> i) & 1) {
                sum += arr[i];
            }
        }
        if (s1.count(sum)) {
            s1[sum] = max(s1[sum], state);
        } else {
            s1[sum] = state;
        }
    }
    for (int state = 0; state < (1<<(n-m)); state++) {
        ll sum = 0;
        for (int i = 0; i < (n-m); i++) {
            if ((state >> i) & 1) {
                sum += arr[i+m];
            }
        }
        if (s2.count(sum)) {
            s2[sum] = max(s2[sum], state);
        } else {
            s2[sum] = state;
        }
    }
}

void sovle() {
    
    for (ll & x : luckyNumber) {
        bool isFound = false;
        ll res = 0;
        for (auto & a : s2) {
            ll num = a.first;
            if (s1.count(x - num)) {
                isFound = true;
                ll res2 = a.second, res1 = s1[x-num];
                ll r = res1 + (res2 << m);
                // cerr << res1 << " " << res2 << endl;
                res = max(res, r);
                // vi cur;
                // cerr << x << endl;
                
                // for (int i = 0; i < m; i++) {
                //     if ((res1 >> i) & 1) {
                        // cur.push_back(arr[i]);
                //     }
                // }
                // for (int i = 0; i < (n-m); i++) {
                //     if ((res2 >> i) & 1) {
                //         cur.push_back(arr[i+m]);
                //     }
                // }
                // res.push_back(cur);
            }
        }
        if (isFound) {
            // vvi::iterator cur = min_element(res.begin(), res.end());
            // for (auto & x : *cur) {
            //     cout << x << " ";
            // }
            
            // cerr << res << endl;
            for (int i = n; i >= 0; i--) {
                if ((res >> i) & 1) {
                    cout << arr[i] << " ";
                }
            }
            // cerr << x << endl;
            break;
        } 
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);
    init();
    sovle();
    return 0;
}
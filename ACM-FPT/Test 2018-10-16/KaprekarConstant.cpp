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

string n2s(int n) {
    string res = "";
    while (n > 0) {
        res += char(n % 10 + '0');
        n /= 10;
    }
    while (res.size() < 5) {
        res = '0' + res;
    }
    reverse(res.begin(), res.end());
    return res;
}

int s2n(string s) {
    int res = 0;
    FOR(i, 0, s.size()) {
        res = res * 10 + (s[i] - '0');
    }
    return res;
}

vector<int> res(100000);

void cal(int n) {
    int m = n;
    map<int, int> mp;
    int cnt = 0;
    vi arr(10);
    
    FOR(it, 0, 10) {
        string mi = n2s(n);
        sort(mi.begin(), mi.end());

        string mx = n2s(n);
        sort(mx.rbegin(), mx.rend());

        n = s2n(mx) - s2n(mi);

        // cout << n << " " << mx << " " << mi << " " << cnt << endl;
        if (mp.find(n) == mp.end()) {
            arr[cnt] = n;
            mp[n] = cnt;
            cnt++;
        } else {
            // if (n != arr[0]) {
                //  cout << n << " " << arr[0] << " yes " << m << endl;
            // }
            int index = 999999 - mp[n];
            int loop = cnt - mp[n];
            index = (index - 1) % loop + mp[n];
            res[m] = arr[index];
            // cout << res[m] << endl;
            // cout << cnt << " " << mp[n] << " " << index << " " << arr[index] << endl;
            // cout << cnt << " " << arr[999998 % cnt] << endl;
            return;
        }
        
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    FOR(i, 0, 100000) {
        cal(i);
        // cout << n2s(res[i]) << endl;
    }
    int TC; scanf("%d", &TC);
    int x;
    while (TC--) {
        scanf("%d", &x);
        printf("%s\n", n2s(res[x]).c_str());
    }
    return 0;
}
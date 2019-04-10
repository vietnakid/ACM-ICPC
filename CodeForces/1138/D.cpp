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

string s, t;
uint64_t arr[500005];
int num[2], need[2], cnt[2];
uint64_t myBase = 13;

uint64_t Pow(int n) {
    if (n == 1) return myBase;
    uint64_t a = Pow(n/2);
    if (n % 2 == 0) {
        return a*a;
    } else {
        return a*a*myBase;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
 	cin >> s >> t;
    arr[0] = t[0] - '0';
    cnt[t[0] - '0']++;
    for (int i = 1; i < (int)t.size(); i++) {
        arr[i] = arr[i-1] * myBase + t[i] - '0';
        cnt[t[i] - '0']++;
    }
    uint64_t k = arr[(int)t.size() - 1];
    ll start = 0;
    for (int i = 1; i < (int)t.size(); i++) {
        int n = (int)t.size() - i;
        uint64_t x = k - arr[i-1] * (Pow(n));
        uint64_t y = arr[n-1];
        // cerr << i << " " << x << " " << y << "\n";
        if (x == y) {
            bool check = true;
            for (int j = 0; j < n; j++) {
                if (t[j] != t[j+i]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                start = n;
                break;
            }
        }
    }

    cerr << start << "\n";

    for (int i = 0; i < (int)s.size(); i++) {
        num[s[i] - '0']++;
    }

    string _t;
    for (int i = start; i < (int)t.size(); i++) {
        need[t[i] - '0']++;
        _t.push_back(t[i]);
    }

    while (num[0] >= cnt[0] && num[1] >= cnt[1]) {
        cout << t;
        num[0] -= cnt[0];
        num[1] -= cnt[1];
        cnt[0] = need[0];
        cnt[1] = need[1];
        t = _t;
    }

    for (int i = 0; i < num[0]; i++) cout << 0;
    for (int i = 0; i < num[1]; i++) cout << 1;
    cout << "\n";
    return 0;
}
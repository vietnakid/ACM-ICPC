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

void vietnakid() {
    ll pow9[11];
    pow9[0] = 1;
    for (int i = 1; i< 11; i++) pow9[i] = 9 * pow9[i-1];

	string s; cin >> s;
    if (s.size() == 1) {
        cout << s << "\n";
    } else {
        if (s[0] == '1') {
            cout << pow9[(ll)(s.size() - 1)] << "\n";
        } else {
            ll res = 1;
            for (int i = 0; i < (int)s.size(); i++) {
                res *= s[i] - '0';
            }
            for (int i = 0; i < (int)s.size(); i++) {
                if (s[i] > '0') {
                    ll cnt = 1;
                    for (int j = 0; j < i; j++)
                        cnt *= s[j] - '0';
                    cnt *= s[i] - '1';
                    cnt *= pow9[(int)(s.size() - i - 1)];
                    res = max(res, cnt);
                }
            }
            cout << res << "\n";
        }
    }
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
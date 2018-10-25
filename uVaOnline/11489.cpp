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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        string s; cin >> s;
        int sum = 0;
        FOR(i, 0, s.size()) {
            sum += s[i] - '0';
        }
        bool canMove = false;
        int num3 = 0, diff3 = 0;
        FOR(i, 0, s.size()) {
            if ((sum - s[i] - '0') % 3 == 0) {
                canMove = true;
                if ((s[i] - '0') % 3 != 0) {
                    diff3++;
                }
            }
            if ((s[i] - '0') % 3 == 0) {
                num3++;
            }
        }
        // cerr << canMove << " " << num3 << " " << diff3 << endl;
        char res;
        if (diff3 > 0) {
            num3++;
        }
        if (!canMove) res = 'T';
        else {
            if (num3 % 2 != 0) res = 'S';
                    else res = 'T';
        }
        
        // if (!canMove) {
        //     res = 'T';
        // } else {
        //     if (num3 == 0) res = 'S';
        //     else {
        //         if (diff3 > 0) res = 'S';
        //         else {
        //             if (num3 % 2 != 0) res = 'S';
        //             else res = 'T';
        //         }
        //     }
        // }
        cout << "Case " << tc << ": " << res << endl;
    }
    return 0;
}
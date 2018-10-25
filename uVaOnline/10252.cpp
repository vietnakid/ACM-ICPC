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
    string s1, s2;
    while (getline(cin, s1)) {
        getline(cin, s2);
        vi cnt1(26, 0), cnt2(26, 0);
        FOR(i, 0, s1.size()) {
            cnt1[s1[i]-'a']++;
        }
        FOR(i, 0, s2.size()) {
            cnt2[s2[i]-'a']++;
        }
        FOR(i, 0, 26) {
            FOR(j, 0, min(cnt1[i], cnt2[i])) {
                cout << char(i + 'a');
            }
        }
        cout << endl;
    }
    return 0;
}
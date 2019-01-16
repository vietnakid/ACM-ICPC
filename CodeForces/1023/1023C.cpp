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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    stack<int> st;
    vii arr;
    FOR(i, 0, n) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            int p = st.top(); 
            st.pop();
            arr.push_back({p, i});
        }
    }
    vi check(n, false);
    FOR(i, 0, k/2) {
        check[arr[i].first] = true;
        check[arr[i].second] = true;
    }
    FOR(i, 0, n) {
        if (check[i]) {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}

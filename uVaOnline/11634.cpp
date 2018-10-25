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



int findNext(int n) {
    n = n*n;
    string s = "";
    while (n > 0) {
        s = char(n%10 + '0') + s;
        n /= 10;
    }
    while (s.size() < 8) {
        s = '0' + s;
    }
    n = 0;
    FOR(i, 2, 6) {
        n = n*10 + (s[i] - '0');
    }
    return n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    ll n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        set<int> st;
        st.insert(n);
        while (true) {
            n = findNext(n);
            if (st.find(n) != st.end()) {
                break;
            }
            
            st.insert(n);
        }
        cout << st.size() << endl;
    }
    return 0;
}
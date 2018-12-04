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
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

string a, b;


bool sovle(int leng) {
    vi arr(30, 0);
    set<vi> st;
    for(int i = 0; a[i]; i++) {
        arr[a[i] - 'a']++;
        if (i >= leng) {
            arr[a[i-leng] - 'a']--;
        }
        if (i >= leng-1) {
            st.insert(arr);
        }
    }

    arr = vi(30, 0);
    for(int i = 0; b[i]; i++) {
        arr[b[i] - 'a']++;
        if (i >= leng) {
            arr[b[i-leng] - 'a']--;
        }
        if (i >= leng-1) {
            if (st.find(arr) != st.end())
                return true;
        }
    }

    return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);

    cin >> a;
    cin >> b;

    for (int i = a.size(); i >= 0; i--) {
        if (sovle(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
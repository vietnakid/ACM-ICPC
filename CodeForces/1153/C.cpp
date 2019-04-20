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

int n;
string s;

void vietnakid() {
	cin >> n;
    cin >> s;
    if (n % 2 == 1 || s[0] == ')' || s[n-1] == '(') {
        cout << ":(\n";
        return;
    }
    s[0] = '('; s[n-1] = ')';
    stack<int> st, st1;
    for (int i = n-2; i > 0; i--) {
        if (s[i] == ')') {
            st.push(i);
        } else if (s[i] == '?') {
            st1.push(i);  
        } else if (s[i] == '(') {
            if (st.empty() && st1.empty()) {
                cout << ":(\n";
                return;
            } else if (!st.empty()) {
                int u = st.top(); st.pop();
                s[u] = ')';
            } else {
                int u = st1.top(); st1.pop();
                s[u] = ')';
            }
        }
    }
    st = stack<int>();
    st1 = stack<int>();
    for (int i = 1; i < n-1; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == '?') {
            st1.push(i);
        } else if (s[i] == ')') {
            if (st.empty() && st1.empty()) {
                cout << ":(\n";
                return;
            } else if (!st.empty()) {
                int u = st.top(); st.pop();
                s[u] = '(';
            } else {
                int u = st1.top(); st1.pop();
                s[u] = '(';
            }
        }
    }
    cerr << s << "\n";
    int cnt = 0;
    for (int i = 1; i < n-1; i++) {
        if (s[i] == '?') {
            if (cnt == 0) {
                s[i] = '(';
                cnt = 1;
            } else {
                s[i] = ')';
                cnt = 0;
            }
        }
    }
    if (cnt != 0) {
        cout << ":(\n";
    } else {
        cout << s << "\n";
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
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

map<int, int> mp;
vi arr;
multiset<ll> st;

int solve(ll start) {
    int res = 0;
    vi remain;
    while (true) {
        multiset<ll>::iterator it = st.lower_bound(start);
        if (it != st.end()) {
            remain.push_back(*it);
            st.erase(it);
            res += start;
            start *= 2;
        } else {
            break;
        }
    }
    for (auto x : remain) {
        st.insert(x);
    }
    return res;
}

void vietnakid() {
	int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    int curMax = 0;
    for (auto x : mp) {
        // arr.push_back(x.second);
        // Heap.push(x.second);
        st.insert(x.second);
        curMax = max(curMax, x.second);
    }
    // sort(arr.begin(), arr.end());
    int res = 0;
    for (int i = 1; i <= curMax; i++) {
        res = max(res, solve(i));
    }
    cout << res << "\n";
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
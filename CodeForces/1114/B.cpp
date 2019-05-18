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

int n, m, k;
int arr[200005];
vi brr;
multiset<int> st;
ll sum = 0;

void vietnakid() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        brr.push_back(arr[i]);
    }
    sort(brr.rbegin(), brr.rend());
    for (int i = 0; i < k*m; i++) {
        sum += brr[i];
        st.insert(brr[i]);
    }
    cout << sum << "\n";
    int cnt = 0, g = 1;
    for (int i = 0; i < n; i++) {
        multiset<int>::iterator it = st.find(arr[i]);
        if (it != st.end()) {
            cnt++;
            st.erase(it);
            // cerr << i << " " << arr[i] << "\n";
        }
        if (cnt == m && g < k) {
            cout << i+1 << " ";
            cnt = 0;
            g++;
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
#include <bits/stdc++.h>
#include <unistd.h>

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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i< n; i++) {
        cin >> arr[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int _min = arr[i];
        int _max = arr[i];
        set<int> st;
        st.insert(arr[i]);
        res++;
        for (int j = i+1; j < n; j++) {
            if (st.find(arr[j]) == st.end()) {
                _min = min(_min, arr[j]);
                _max = max(_max, arr[j]);
                st.insert(arr[j]);
                if (_max - _min + 1 == st.size()) {
                    res++;
                }
            } else {
                break;
            }
        }
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
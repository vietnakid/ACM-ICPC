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
int arr[200005];
deque<int> q, res;

void vietnakid() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    for (int i = 0; i < n; i++) {
        cerr << i << "\n";
        q.push_front(arr[i]);
        for (i++; i < n; i++) {
            // cerr << q.front() << " " << q.back() << "\n";
            if (arr[i] - q.front() <= 1 && arr[i] - q.back() <= 1) {
                if (q.size() % 2 == 0) q.push_front(arr[i]);
                else q.push_back(arr[i]);
            } else {
                i = distance(arr, lower_bound(arr, arr+n, arr[i]-1))-1;
                break;
            }
        }    
        if (q.size() > res.size()) res = q;
        q.clear();
        // cerr << "\n";
    }
    cout << res.size() << "\n";
    while (!res.empty()) {
        cout << res.front() << " ";
        res.pop_front();
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
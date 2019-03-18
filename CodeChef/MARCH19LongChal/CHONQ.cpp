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

ll n, k;
vector<double> arr;
vl sum;
int sqrtn = 316;

void solve() {
    for (int i = 0; i < n; i++) {
        sqrtn = floor(sqrt(arr[i]));
        for (int j = 1; j <= sqrtn; j++) {
            double l = j;
            int index = i - j + 1;
            if (index < 0) break;
            // cerr << i << " " << index << " " << floor(arr[i] / l) << "\n";
            sum[index] += floor(arr[i] / l);
            sum[index+1] -= floor(arr[i] / l);
        }
        int oldIndex = 0;
        for (int j = 0; j <= sqrtn; j++) {
            int value = j + 1;
            int index = i-floor(arr[i] / double(value));
            // if (floor(arr[i] / double(value)) == ceil(arr[i] / double(value))) {
            //     index--;
            // }
            index = min(index, i-sqrtn);
            // cerr << i << " " << index << " " << j << "\n";
            if (index >= 0) {
                sum[oldIndex] += j;
                sum[index+1] -= j;
                oldIndex = index+1;
            }
        }
    }
    cerr << sum[0] << " ";
    if (sum[0] <= k) {
        cout << 1 << "\n";
        return;
    }
    for (int i = 1; i < n; i++) {
        sum[i] += sum[i-1];
        cerr << sum[i] << " ";
        if (sum[i] <= k) {
            cout << i+1 << "\n";
            return;
        }
    }
    cout << n+1 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int TC; 
    scanf("%d", &TC);
    while (TC--) {
        scanf("%lld %lld", &n, &k);
        arr.clear();
        arr.resize(n+1);
        sum.clear();
        sum.resize(n+1, 0);
        for (int i = 0; i < n; i++) {
            scanf("%lf", &arr[i]);
        }
        solve();
    }
    return 0;
}
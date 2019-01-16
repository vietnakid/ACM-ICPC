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
bitset<300005> isCheck;
vl arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    isCheck.reset();
    cin >> n >> k;
    arr.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < k; i++) {
        if (!isCheck[arr[i]]) {
            ll j = arr[i];
            while (j <= n) {
                isCheck[j] = true;
                j += arr[i];
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += (isCheck[i] == 0);
    }
    cout << cnt << endl;
    return 0;
}
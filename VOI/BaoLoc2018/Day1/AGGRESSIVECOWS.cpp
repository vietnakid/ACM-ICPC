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

int n, c;
int arr[100005];

int count(int leng) {
    int res = 1;
    int cur = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] >= cur + leng) {
            res++;
            cur = arr[i];
        }
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    int res = 0;
    int left = 0, right = arr[n-1];
    for (int ii = 0; ii < 100; ii++) {
        if (left > right) break;
        int mid = (left + right) / 2;
        if (count(mid) >= c) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid-1;
        }
    }
    cout << res << endl;
    return 0;
}
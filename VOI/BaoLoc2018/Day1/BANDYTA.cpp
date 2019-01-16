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

int arr[2][300005];
int mp[300005];
map<ii, int> MP;
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mp[x] = i;
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        arr[0][x] = (mp[x] - i + n) % n;
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        arr[1][x] = (mp[x] - i + n) % n;
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        MP[{arr[0][i],arr[1][i]}]++;
        res = max(res, MP[{arr[0][i],arr[1][i]}]);
    }

    printf("%d\n", res);
    // cout << res << endl;
    return 0;
}
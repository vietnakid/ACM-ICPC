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
map<int, int> mp, pos;
int res = 0, vres;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
 	cin >> n;
    for (int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        if (mp[x] > res) {
            res = mp[x];
            vres = x;
        }
        pos[x] = i;
        arr[i] = x;
    } 
    cout << n - res << "\n";
    for (int i = pos[vres] + 1; i < n; i++) {
        if (arr[i] == vres) continue;
        if (arr[i] < vres) {
            cout << "1 " << i+1 << " " << i << "\n";
        } else {
            cout << "2 " << i+1 << " " << i << "\n";
        }
    }
    for (int i = pos[vres] - 1; i >= 0; i--) {
        if (arr[i] == vres) continue;
        if (arr[i] < vres) {
            cout << "1 " << i+1 << " " << i+2 << "\n";
        } else {
            cout << "2 " << i+1 << " " << i+2 << "\n";
        }
    }
    return 0;
}
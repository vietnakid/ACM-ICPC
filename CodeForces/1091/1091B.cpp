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
#define X first
#define Y second

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

vii arr, brr;
int n;
map<ii, int> mp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    arr.resize(n);
    brr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].X >> arr[i].Y;
    }
    for (int i = 0; i < n; i++) {
        cin >> brr[i].X >> brr[i].Y;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = arr[i].X + brr[j].X;
            int y = arr[i].Y + brr[j].Y;
            mp[{x, y}]++;
        }
    }
    for (auto & element : mp) {
        if (element.second == n) {
            cout << element.first.X << " " << element.first.Y << endl;
            break;
        }
    }
    return 0;
}
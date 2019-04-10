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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
 	int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    int rem = 0;
    vi arr(n+1);
    for (int i = s1.size()-1; i >= 0; i--) {
        arr[i+1] = (s1[i] + s2[i] + rem - 2*'a') % 26;
        rem = (s1[i] + s2[i] + rem - 2*'a') / 26;
    }
    arr[0] = rem;

    for (int i = 0; i <= n; i++) {
        // cerr << arr[i] << "\n";
        arr[i+1] += arr[i] % 2 * 26;
        arr[i] /= 2;
        if (i > 0) {
            cout << char(arr[i] + 'a');
        }
    }
    return 0;
}
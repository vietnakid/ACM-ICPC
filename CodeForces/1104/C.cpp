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
    string s;
    cin >> s;
    bitset<4> ver;
    bitset<2> hor;
    ver.reset();
    hor.reset();
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '0') {
            for (int c = 0; c < 4; c++) {
                if (ver[c] == false) {
                    cout << 1 << " " << c+1 << endl;
                    ver[c] = true;
                    break;
                }
            }
            if (ver[3]) {
                ver.reset();
            }
        } else {
            for (int c = 0; c < 2; c++) {
                if (hor[c] == false) {
                    cout << 4 << " " << c*2+1 << endl;
                    hor[c] = true;
                    break;
                }
            }
            if (hor[1]) {
                hor.reset();
            }
        }
    }
    return 0;
}
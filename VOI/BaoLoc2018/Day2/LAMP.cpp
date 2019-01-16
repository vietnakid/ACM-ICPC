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
string s1, s2;
int f[10005][2][2];

void sovle() {
    f[0][1][0] = INF;
    f[0][0][1] = INF;
    f[0][1][1] = INF;
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int isSelect1 = 0; isSelect1 < 2; isSelect1++) {
            for (int isSelect2 = 0; isSelect2 < 2; isSelect2++) {
                f[i][isSelect1][isSelect2] = f[i-1][isSelect1][isSelect2];
                f[i][isSelect1][isSelect2] = min(f[i][isSelect1][isSelect2], f[i-1][1-isSelect1][isSelect2] + (isSelect1==1?1:0));
                f[i][isSelect1][isSelect2] = min(f[i][isSelect1][isSelect2], f[i-1][isSelect1][1-isSelect2] + (isSelect2==1?1:0));
                f[i][isSelect1][isSelect2] = min(f[i][isSelect1][isSelect2], f[i-1][1-isSelect1][1-isSelect2] + (isSelect2==1?1:0) + (isSelect1==1?1:0));
                int state1 = s1[i] - '0';
                int state2 = s2[i] - '0';
                if (state1 != isSelect1 || state2 != isSelect2) {
                    f[i][isSelect1][isSelect2]++;
                }
                // cerr << i << " " << isSelect1 << " " << isSelect2 << " " << f[i][isSelect1][isSelect2] << endl;
            }
        }
    }
    int res = f[n][0][0];
    res = min(res, f[n][1][0]);
    res = min(res, f[n][0][1]);
    res = min(res, f[n][1][1]);
    cout << res << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    cin >> s1 >> s2;
    s1 = '.'+s1;
    s2 = '.'+s2;
    sovle();
    return 0;
}
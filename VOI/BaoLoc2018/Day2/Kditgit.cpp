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

ll a, b, k;
ll dp[21][2][21][21][21][2];

string toString(ll a) {
    string res = "";
    while (a > 0) {
        char cur = ((a % 10) + '0');
        res.push_back(cur);
        a /= 10;
        
    }
    reverse(res.begin(), res.end());
    return res;
}

ll calDP(int index, bool isLess, int preNum, int curLeng, int maxLeng, bool zero, string n) {
    if (dp[index][isLess][preNum][curLeng][maxLeng][zero] != -1) {
        return dp[index][isLess][preNum][curLeng][maxLeng][zero];
    }
    // cerr << index << " | isLess = " << isLess << " | preNum = " << preNum << " | curLeng = " << curLeng << " | maxLeng = " << maxLeng << endl;
    if (index == n.size()) {
        return maxLeng >= k;
    }

    int curNum = n[index] - '0';
    ll res = 0 ;
    for (int num = 0; num < 10; num++) {
        if (isLess) {
            if (num < curNum) {
                int _curLeng = 1;
                if (num == preNum) {
                    _curLeng = curLeng + 1;
                }
                int _maxLeng = max(_curLeng, maxLeng);
                if (zero && num == 0) {
                    _curLeng = 0;
                    _maxLeng = 0;
                }
                res += calDP(index+1, false, num, _curLeng, _maxLeng, (zero && num == 0), n);
            } else if (num == curNum) {
                int _curLeng = 1;
                if (num == preNum) {
                    _curLeng = curLeng + 1;
                }
                int _maxLeng = max(_curLeng, maxLeng);
                if (zero && num == 0) {
                    _curLeng = 0;
                    _maxLeng = 0;
                }
                    
                res += calDP(index+1, true, num, _curLeng, _maxLeng, (zero && num == 0), n);
            }
        } else {
            int _curLeng = 1;
            if (num == preNum) {
                _curLeng = curLeng + 1;
            }
            int _maxLeng = max(_curLeng, maxLeng);
            if (zero && num == 0) {
                // cerr << index << " " << isLess << " | preNum = " << preNum << " | curLeng = " << curLeng << " | maxLeng = " << maxLeng << endl;
                _curLeng = 0;
                _maxLeng = 0;
            }
            res += calDP(index+1, false, num, _curLeng, _maxLeng, (zero && num == 0), n);
        }
    }

    dp[index][isLess][preNum][curLeng][maxLeng][zero] = res;
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> a >> b >> k;

    memset(dp, -1, sizeof(dp));
    ll resb = calDP(0, true, -1, 0, 0, true, toString(b));
    memset(dp, -1, sizeof(dp));
    ll resa = calDP(0, true, -1, 0, 0, true, toString(a-1));
    // cerr << resb << " " << resa << endl;
    cout << resb - resa << endl;
    return 0;
}
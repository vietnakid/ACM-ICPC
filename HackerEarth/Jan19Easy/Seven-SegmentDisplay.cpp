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

int dx[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int getNum(string num) {
    int res = 0;
    for (int i = 0; i < num.size(); i++) {
        res += dx[num[i] - '0'];
    }
    return res;
}

void sovle(string n) {
    int sum = getNum(n);
    // cerr << sum << endl;
    string res = "";
    while (sum > 3) {
        res.push_back('1');
        sum -= 2;
    }
    if (sum == 3) {
        res.push_back('7');
    } else if (sum == 2) {
        res.push_back('1');
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int TC; cin >> TC;
    while (TC--) {
        string n;
        cin >> n;
        sovle(n);
    }
    return 0;
}
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

string s;
int k;
int let, mark, all;

void vietnakid() {
    cin >> s;
    cin >> k;
    for (auto x : s) {
        if (x >= 'a' && x <= 'z') let++;
        else if (x == '?') mark++;
        else if (x == '*') all++;
    }
    s.push_back('!');
    if (k < let - mark - all) {
        cout << "Impossible\n";
    } else if (all == 0) {
        if (k > let) {
            cout << "Impossible\n";
        } else {
            int realLet = let - mark;
            int usedMark = k - realLet;
            int cnt = 0;
            string res = "";
            for (int i = 0; i < s.size()-1; i++) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    if (s[i+1] == '?') {
                        if (cnt < usedMark) {
                            cnt++;
                            res.push_back(s[i]);
                        }
                    } else {
                        res.push_back(s[i]);
                    }
                }
            }
            cout << res << "\n";
        }
    } else {
        int realLet = let - mark - all;
        int remainLet = k - realLet;
        string res = "";
        bool isFirst = false;
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (s[i+1] == '?') {
                    continue;
                } else if (s[i+1] == '*') {
                    if (!isFirst) {
                        isFirst = true;
                        for (int j = 0; j < remainLet; j++) {
                            res.push_back(s[i]);        
                        }
                    }
                } else {
                    res.push_back(s[i]);
                }
            }
        }
        cout << res << "\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
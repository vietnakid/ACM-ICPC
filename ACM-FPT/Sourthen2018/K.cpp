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

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int l;
string s;

int contain() {
    FOR(i, 0, l) {
        if (!(s[i] == '6' || s[i] == '8')) {
            return i;
        }
    }
    return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> s;
    l = s.size();
    string tmp = "";
    FOR(i, 0, l) {
        tmp.push_back('6');
    }
    if (tmp > s) {
        string res = "";
        FOR(i, 0, l-1) {
            res.push_back('8');
        }
        cout << res << endl;
    } else {
        int pos = contain();
        if (pos == -1) {
            cout << s << endl;
        } else {
            if (s[pos] == '7') {
                string tmp = "";
                FOR(i, 0, pos) {
                    tmp.push_back(s[i]);
                }
                tmp.push_back('6');
                while (tmp.size() < l) {
                    tmp.push_back('8');
                }
                cout << tmp << endl;
            } else if (s[pos] == '9') {
                string tmp = "";
                FOR(i, 0, pos) {
                    tmp.push_back(s[i]);
                }
                while (tmp.size() < l) {
                    tmp.push_back('8');
                }
                cout << tmp << endl;
            } else {
                FORD(i, pos-1, 0) {
                    // cerr << "OK " << i << endl;
                    if (s[i] == '8') {
                        string tmp = "";
                        FOR(j, 0, i) {
                            tmp.push_back(s[j]);
                        }
                        tmp.push_back('6');
                        while (tmp.size() < l) {
                            tmp.push_back('8');
                        }
                        cout << tmp << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
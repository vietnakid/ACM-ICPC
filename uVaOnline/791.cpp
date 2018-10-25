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

#define INF 1e9+7
#define INFLL 1e18+7
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

string toBase4(string s) {
    string res = "";
    FOR(i, 0, s.size()) {
        char c = s[i];
        if (c == 'V') {
            res += '0';
        } else if (c == 'U') {
            res += '1';
        } else if (c == 'C') {
            res += '2';
        } else {
            res += '3';
        }
    }
    return res;
}

string add(string s1, string s2) {
    int carry = 0;
    // cerr << s1 << " " << s2 << endl;
    while (s1.size() < s2.size()) {
        s1 = '0' + s1;
    }
    FORD(i, s1.size() -1, 0) {
        int c1 = s1[i] - '0';
        int c2 = s2[i] - '0';
        int s = carry + c1 + c2;
        s2[i] = (s % 4) + '0';
        carry = (s / 4);
        // cerr << c1 << " " << c2 << " " << s << " " << carry << endl;
    }
    if (carry != 0) {
        s2 = (char)(carry + '0') + s2;
    }
    return s2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    cout << "COWCULATIONS OUTPUT" << endl;
    FOR(tc, 0, TC) {
        string s1, s2;
        cin >> s1 >> s2;
        s1 = toBase4(s1);
        s2 = toBase4(s2);
        FOR(j, 0, 3) {
            char o; cin >> o;
            if (o == 'A') {
                s2 = add(s1, s2);
            } else if (o == 'L') {
                s2 += '0';
            } else if (o == 'R') {
                s2.pop_back();
                s2 = '0' + s2;
            }
            // cerr << s2 << endl;
        }
        while (s2.size() < 8) {
            s2 = '0' + s2;
        }
        string s3; cin >> s3;
        s3 = toBase4(s3);
        // cerr << s2 << " " << s3 << endl;
        if (s2 == s3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
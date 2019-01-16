#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

bool isVowel(char c) {
    if (c == 'a' || c == 'o' || c == 'u' || c == 'i' || c == 'e') {
         return true;
    }
    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    string s;
    bool check = true;
    cin >> s;
    FOR(i, 1, s.size()) {
        char c = s[i-1];
        if (!isVowel(c) && c != 'n') {
            if (!isVowel(s[i])) {
                check = false;
            }
        }
    }
    char c = s[s.size() - 1];
    if (!isVowel(c) && c != 'n') {
        check = false;
    }
    if (check) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
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

vector<string> arr;

bool checkChar(char a, char b, char c) {
    return ((a == b && b == c) || (a != b && b != c && a != c));
}

bool check(string a, string b, string c) {
    FOR(i, 0, 4) {
        if (!checkChar(a[i], b[i], c[i])) {
            return false;
        }
    }
    return true;
}

void sovle() {
    cout << "CARDS: ";
    FOR(i, 0, arr.size()) {
        cout << " " << arr[i];
    }
    cout << endl;
    cout << "SETS:   ";
    int cnt = 0;
    int n = arr.size();
    FOR(i, 0, n-2) {
        FOR(j, i+1, n-1) {
            FOR(k, j+1, n) {
                if (check(arr[i], arr[j], arr[k])) {
                    cnt++;
                    if (cnt > 1) {
                        cout << "        ";
                    }
                    cout << cnt << ".  " << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                }
            }
        }
    }
    if (cnt == 0) {
        cout << "*** None Found ***" << endl;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    string s;
    
    while (getline(cin,  s)) {
        if (s.size() == 4) {
            arr.push_back(s);
        } else {
            sovle();
            cout << endl;
            arr.clear();
        }
    }
    sovle();
    return 0;
}
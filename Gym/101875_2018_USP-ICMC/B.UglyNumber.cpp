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

int n;
string s;

void checkNotSmalest() {
    FOR(i, 1, n) {
        if (s[i] < s[0]) {
            cout << "No" << endl;
            exit(0);
        }
    }
}

void checkAllEqual() {
    FOR(i, 1, n) {
        if (s[i] > s[0]) {
            return;
        }
    }
    cout << "Yes" << endl;
    exit(0);
}

void checkLeng() {
    int firstLeng = 1;
    FOR(i, 1, n) {
        if (s[i] == s[0]) {
            firstLeng++;
        } else {
            break;
        }
    }
    int leng = 0;
    FOR(i, firstLeng, n) {
        if (s[i] == s[0]) {
            leng++;
            if (leng > firstLeng) {
                cout << "No" << endl;
                exit(0);
            }
        } else {
            leng = 0;
        }
    }
}

void checkLastDigit() {
    if (s[0] == s[n-1]) {
        cout << "No" << endl;
        exit(0);
    }
}

void sovle() {
    checkNotSmalest();
    checkAllEqual();
    checkLeng();
    checkLastDigit();
    cout << "Yes" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    
    cin >> n;
    cin >> s;

    sovle();

    return 0;
}
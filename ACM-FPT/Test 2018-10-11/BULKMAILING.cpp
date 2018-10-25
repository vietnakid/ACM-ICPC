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

vector<string> invalid;
map<string, int> five;
map<string, vector<string> > three;
map<string, int> firstClass;
int totalLetter = 0, totalBundle = 0;

bool isValid(string s) {
    if (s.size() != 5) return false;
    if (s == "00000") return false;
    FOR(i, 0, s.size()) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

void putInvalid(string s) {
    FOR(i, 0, invalid.size()) {
        if (invalid[i] == s) return;
    }
    invalid.push_back(s);
}

void printValue(string s, int letter, int bundle) {
    totalLetter += letter;
    totalBundle += bundle;
    printf("%s %12d %12d\n", s.c_str(), letter, bundle);
}

void sovleFive() {
    for(map<string, int>::iterator it = five.begin(); it != five.end(); it++ ) {
        if (it->second >= 10) {
            if (it->second >= 16 && it->second <= 19) {
                printValue(it->first, 15, 1);
                it->second -= 15;
            } else {
                printValue(it->first, it->second, ceil(double(it->second)/15.));
                it->second = 0;
            }
        }
    }
}

void sovleThree() {
    for(map<string, int>::iterator it = five.begin(); it != five.end(); it++ ) {
        string pre = it->first.substr(0, 3);
        FOR(i, 0, it->second)
            three[pre].push_back(it->first);
    }

    for(map<string, vector<string> >::iterator it = three.begin(); it != three.end(); it++) {
        if (it->second.size() >= 10) {
            if (it->second.size() >= 16 && it->second.size() <= 19) {
                printValue(it->first + "xx", 15, 1);
                // it->second -= 15;
                FOR(i, 15, it->second.size()) {
                    firstClass[it->second[i]]++;
                }
            } else {
                printValue(it->first + "xx", it->second.size(), ceil(double(it->second.size())/15.));
            }
        } else {
            FOR(i, 0, it->second.size()) {
                firstClass[it->second[i]]++;
            }
        }
    }
}

void sovleFirstClass() {
    for(map<string, int>::iterator it = firstClass.begin(); it != firstClass.end(); it++ ) {
        if (it->second >= 10) {
            printValue(it->first, it->second, ceil(double(it->second)/15.));
        } else {
            printValue(it->first, it->second, 0);
        }
    }
}

void sovleInvalid() {
    FOR(i, 0, invalid.size()) {
        printf("%s\n", invalid[i].c_str());
    }
}

void solve() {
    printf("ZIP         LETTERS     BUNDLES\n");
    sovleFive();
    printf("\n");
    sovleThree();
    printf("\n");
    sovleFirstClass();
    printf("\n");
    printf("TOTALS %11d %12d\n\n", totalLetter, totalBundle);
    printf("INVALID ZIP CODES\n\n");
    sovleInvalid();
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    string s;
    while (cin >> s) {
        if (!isValid(s)) {
            putInvalid(s);
        } else {
            five[s]++;
        }
    }

    solve();
    return 0;
}
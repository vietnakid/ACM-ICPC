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

vi palindrome;
vvi res(10001);
vii palin2;

bool isPalindrome(int a) {
    vi arr;
    while (a > 0) {
        arr.push_back(a % 10);
        a /= 10;
    }
    int n = arr.size();
    FORE(i, 0, (n-2)/2) {
        if (arr[i] != arr[n-i-1]) {
            return false;
        }
    }
    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    FORE(i, 1, 10000) {
        if (isPalindrome(i)) {
            palindrome.push_back(i);
            res[i].push_back(i);
            // cerr << i << endl;
        }
    }
    for(vi::iterator it = palindrome.begin(); it != palindrome.end(); it++) {
        vi::iterator it2 = it;
        it2++;
        for(; it2 != palindrome.end(); it2++) {
            if ((*it) + (*it2) <= 10000) {
                palin2.push_back({*it, *it2});
                if (res[(*it) + (*it2)].size() == 0) {
                    res[(*it) + (*it2)].push_back(*it);
                    res[(*it) + (*it2)].push_back(*it2);
                }
            }
        }
    }
    for(vi::iterator it = palindrome.begin(); it != palindrome.end(); it++) {
        for(vii::iterator it2 = palin2.begin(); it2 != palin2.end(); it2++) {
            if (*it != it2->first && *it != it2->second) {
                if ((*it) + it2->first + it2->second <= 10000 && res[(*it) + it2->first + it2->second].size() == 0) {
                    res[(*it) + it2->first + it2->second].push_back(*it);
                    res[(*it) + it2->first + it2->second].push_back(it2->first);
                    res[(*it) + it2->first + it2->second].push_back(it2->second);
                }
            }
        }
    }
    int tc;
    cin >> tc;
    FORE(i, 1, tc) {
        cout << "Case #" << i << endl;
        int n;
        cin >> n;
        cout << res[n].size() << " ";
        sort(res[n].rbegin(), res[n].rend());
        FOR(j, 0, res[n].size()) {
            cout << res[n][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
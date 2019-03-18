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

int common(set<int> a, set<int> b) {
    int res = 0;
    for (auto x:a) {
        res += b.count(x);
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    string s;
    while (getline(cin, s)) {
        int n;
        set<int> a, b;
        stringstream ss(s);
        while (ss >> n) {
            a.insert(n);
        }
        getline(cin, s);
        stringstream sss(s);
        while (sss >> n) {
            b.insert(n);
        }
        if (a == b) {
            cout << "A equals B\n";
        } else {
            int na = a.size();
            int nb = b.size();
            int numCommon = common(a, b);
            if (numCommon == 0) {
                cout << "A and B are disjoint\n";
            } else if (numCommon == na) {
                cout << "A is a proper subset of B\n";
            } else if (numCommon == nb) {
                cout << "B is a proper subset of A\n";
            } else {
                cout << "I'm confused!\n";
            }
        }
    }
    
    return 0;
}
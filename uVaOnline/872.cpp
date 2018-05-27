#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

priority_queue< ll, vector<ll>, greater<ll> > heap;

vvi E;
vi inDeg;
int n;
map<char, int> name;
vector<char> order;
vi isFree;
int res;

void backtrack(string s) {
    FOR(i, 0, n) {
        if (isFree[i] && inDeg[i] == 0) {
            // cout << order[i] << " " << inDeg[i] << endl;
            isFree[i] = false;
            FOR(j, 0, E[i].size()) {
                inDeg[E[i][j]]--;
            }

            string x = s;
            if (x.size() > 0) {
                x += ' ';
            }
            x += (char)order[i];
            
            backtrack(x);

            FOR(j, 0, E[i].size()) {
                inDeg[E[i][j]]++;
            }
            isFree[i] = true;
        }
    }
    if (s.size() == n*2-1) {
        cout << s << endl;
        res++;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    string s;
    getline(cin, s);
    stringstream ss(s);
    int TC; 
    ss >> TC;
    FORE(tc, 1, TC) {
        res = 0;
        if (tc > 1) {
            cout << endl;
        }
        name.clear();
        order.clear();

        getline(cin, s);
        getline(cin, s);
        vector<char> arr;
        
        for(int i = 0; i < s.size(); i+=2) {
            arr.push_back(s[i]);
        }
        sort(arr.begin(), arr.end());
        FOR(i, 0, arr.size()) {
            name[arr[i]] = i;
            order.push_back(arr[i]);
        }
        n = arr.size();
        E = vvi(n);
        inDeg = vi(n, 0);
        isFree = vi(n, true);
        getline(cin, s);
        for(int i = 0; i < s.size(); i+=4) {
            char u = s[i];
            char v = s[i+2];
            E[name[u]].push_back(name[v]);
            inDeg[name[v]]++;
        }
        backtrack("");
        if (res == 0) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
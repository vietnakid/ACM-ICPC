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

const int MAX_N = 100;
int b[MAX_N];

void kmpPreprocess(string P) { 
    int m = P.size();
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    } 
}

int kmpSearch(string T, string P) {
    int i = 0, j = 0, res = 0;
    int n = T.size(), m = P.size();
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) 
            j = b[j];
        i++; j++; // if same, advance both pointers
        if (j == m) { // a match found when j == m
        res++;
        j = b[j]; // prepare j for the next possible match
        } 
    }
    return res;
}

int cal(string a, string b) {
    int res = 0;
    int n = a.size(), m = b.size();
    FORE(i, 0, n-m) {
        string c = "";
        FOR(j, i, i+m) {
            c.push_back(a[j]);
        }
        if (c == b) {
            res++;
        }
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n;
    cin >> n;
    string word;
    getline(cin, word);
    getline(cin, word);
    kmpPreprocess(word);
    vector<pair<int, string> > arr(n);
    FOR(i, 0, n) {
        string s;
        getline(cin, s);
        int cnt = cal(s, word);
        arr[i] = {cnt, s};
    }
    sort(arr.begin(), arr.end());
    FOR(i, 0, n) {
        cout << arr[i].second << endl;
    }
    return 0;
}
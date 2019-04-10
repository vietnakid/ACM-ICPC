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
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;
ll INFLL = 1000000000000000000;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

ll n, m, k;

string pre[205], suf[205];
ll numAppear[205];

#define MAX_N 100010


int b[MAX_N]; // b = back table, n = length of T, m = length of P

void kmpPreprocess(string pattern, string s) { // call this before calling kmpSearch()
    int n = s.size();
    int m = pattern.size();
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < m) { // pre-process the pattern string P
    while (j >= 0 && pattern[i] != pattern[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
} }           // in the example of P = "SEVENTY SEVEN" above

ll KMP(string pattern, string s) {
    ll res = 0;
    kmpPreprocess(pattern, s);
    int n = s.size();
    int m = pattern.size();
  int i = 0, j = 0; // starting values
  while (i < n) { // search through string T
    while (j >= 0 && s[i] != pattern[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    if (j == m) { // a match found when j == m
    //   printf("P is found at index %d in T\n", i - j);
    res++;
      j = b[j]; // prepare j for the next possible match
} } 
    return res;
}

string getPre(string s, int leng) {
    string res = "";
    for (int i = 0; i < min((int)s.size(), leng); i++) {
        res.push_back(s[i]);
    }
    return res;
}

string getSuf(string s, int leng) {
    reverse(s.begin(), s.end());
    string res = getPre(s, leng);
    reverse(res.begin(), res.end());
    return res;
}

ll count(string s) {
    memset(numAppear, 0, sizeof(numAppear));
    if (s == "0") numAppear[0] = 1;
    if (s == "1") numAppear[1] = 1;
    int leng = s.size();
    for (int i = 2; i <= n; i++) {
        numAppear[i] = numAppear[i-1] + numAppear[i-2];
        numAppear[i] = min(numAppear[i], INFLL);
        numAppear[i] += KMP(s, getSuf(suf[i-2], leng-1) + getPre(pre[i-1], leng-1));
        numAppear[i] = min(numAppear[i], INFLL);
        // cerr << s << " count " << "i = " << i << ": " << numAppear[i] << "\n";
    }
    if (leng > 1) {
        string tmp = getSuf(suf[n], leng-1);
        string tmp2 = getPre(s, leng-1);
        if (tmp == tmp2) numAppear[n]++;
    }
    
    return numAppear[n];
}



void init() {
    string fibo[15];
    fibo[0] = "0";
    fibo[1] = "1";
    for (int i = 2; i < 15; i++) {
        fibo[i] = fibo[i-2] + fibo[i-1];
        // cout << fibo[i] << "\n";
    }
    for (int i = 0; i < 15; i++) {
        pre[i] = getPre(fibo[i], 200);
        suf[i] = getSuf(fibo[i], 200);
        // cerr << pre[i] << " " << suf[i] << "\n";
    }
    for (int i = 15; i < 201; i++) {
        pre[i] = pre[i-2];
        suf[i] = suf[i-1];
    }
}

bool isEnd(string res, ll cnt) {
    if (k - cnt > 1) return false;
    int leng = res.size();
    if (leng > 1) {
        string tmp = getSuf(suf[n], leng);
        if (tmp == res) return true;
    }
    if (leng == 1) return true;
    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    init();
    cin >> n >> k >> m;
    string res = "";
    ll cnt = 0;
    for (int i = 0; i < m; i++) {
        ll c = count(res + '0');
        if (c + cnt >= k) {
            res.push_back('0');
            int leng = res.size();
            if (leng > 1) {
                string tmp = getSuf(suf[n], leng-1);
                string tmp2 = getPre(res, leng-1);
                if (tmp == tmp2) cnt++;
            }
        } else {
            cnt += c;
            res.push_back('1');
            if (isEnd(res, cnt)) {
                cout << res << "\n";
                exit(0);
            }
        }
        // cerr << res << " " << cnt << " " << c << "\n";
    }
    cout << res << "\n";
 	// cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
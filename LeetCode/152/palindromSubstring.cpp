#include <bits/stdc++.h>
#include <unistd.h>

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

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> cnt(n, vector<int>(26));
        cnt[0][s[0] - 'a']++;
        for (int i = 1; i < n; i++) {
            cnt[i] = cnt[i-1];
            cnt[i][s[i] - 'a']++;
        }
        
        vector<bool> res;
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            
            if (r - l == 0) {
                cerr << true << "-\n";
                res.push_back(true);
                continue;
            }
            if (r - l == 1) {
                if (s[l] == s[r]) {
                    cerr << true << "--\n";
                    res.push_back(true);
                } else {
                    cerr << (k > 0 ? true : false) << "--\n";
                    res.push_back(k > 0 ? true : false);  
                }
                continue;
            }
            
            vector<int> process(26, 0);
            if (l == 0) {
                process = cnt[r];
            } else {
                for (int j = 0; j < 26; j++) {
                    process[j] = cnt[r][j] - cnt[l-1][j];
                }
            }
            int re = 0;
            for (int j = 0; j < 26; j++) {
                int h = process[j];
                re += h % 2;
            }
            re /= 2;
            res.push_back(re <= k?true : false);
        }
        return res;
}

void vietnakid() {
    string s = "pqtadspgvinafefk";
    vector<vector<int>> queries = {{1,15,5},{14,15,1},{15,15,1}};
    canMakePaliQueries(s, queries);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
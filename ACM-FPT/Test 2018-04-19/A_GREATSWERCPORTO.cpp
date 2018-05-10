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
for (int i = (a); i >= (b); i++)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

vi mp(256, 0);

ll cal(string & s) {
    ll res = 0;
    FOR(i, 0, s.size()) {
        res = res * 10 + mp[s[i]];
    }
    return res;
}

ll factorial(int n) {
    ll res = 1;
    FORE(i, 1, n)
    res *= i;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
   freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n;
    cin >> n;
    vector<string> arr(n);
    set<char> setChar;
    vector<bool> cantZero(256, false);
    FOR(i, 0, n) {
        cin >> arr[i];
        FOR(j, 0, arr[i].size()) {
            setChar.insert(arr[i][j]);
        }
        cantZero[arr[i][0]] = true;
    }
    vector<char> chars;
    for (char x : setChar) {
        chars.push_back(x);
    }
    
    vector<int> permu;
    FOR(i, 0, 10) {
        permu.push_back(i);
    }
    int res = 0;
    int cnt = 0;
    do {
        cnt++;
        bool check = true;
        FOR(i, 0, chars.size()) {
            if (permu[i] == 0 && cantZero[chars[i]])
                check = false;
            mp[chars[i]] = permu[i];
        }
        if (check == false)
            continue;
        ll sum = 0;
        FOR(i, 0, n-1) {
            sum += cal(arr[i]);
        }
        
        ll an = cal(arr[n-1]);
        if (sum == an) {
//            FOR(i, 0, chars.size()) {
//                cout << chars[i] << " = " << permu[i] << " --- ";
//            }
//            FOR(i, 0, n) {
//                cout << cal(arr[i]) << endl;
//            }
//            cout << endl;
            res++;
        }
        
    } while (next_permutation(permu.begin(), permu.end()));
    cout << res / factorial(10-chars.size()) << '\n';
    return 0;
}

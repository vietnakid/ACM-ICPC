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

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
//    freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    map<string, int> mp;
    vector<string> s(10);
    s[0] = "xxxxxx...xx...xx...xx...xx...xxxxxx";
    s[1] = "....x....x....x....x....x....x....x";
    s[2] = "xxxxx....x....xxxxxxx....x....xxxxx";
    s[3] = "xxxxx....x....xxxxxx....x....xxxxxx";
    s[4] = "x...xx...xx...xxxxxx....x....x....x";
    s[5] = "xxxxxx....x....xxxxx....x....xxxxxx";
    s[6] = "xxxxxx....x....xxxxxx...xx...xxxxxx";
    s[7] = "xxxxx....x....x....x....x....x....x";
    s[8] = "xxxxxx...xx...xxxxxxx...xx...xxxxxx";
    s[9] = "xxxxxx...xx...xxxxxx....x....xxxxxx";
    mp[s[0]] = 0;
    mp[s[1]] = 1;
    mp[s[2]] = 2;
    mp[s[3]] = 3;
    mp[s[4]] = 4;
    mp[s[5]] = 5;
    mp[s[6]] = 6;
    mp[s[7]] = 7;
    mp[s[8]] = 8;
    mp[s[9]] = 9;
    
    string plus = ".......x....x..xxxxx..x....x.......";
    ll a = 0, lenga = 0;
    ll b = 0, lengb = 0;
    vector<string> sa, sb;
    FOR(i, 0, 7) {
        string s;
        getline(cin, s);
        if (i == 0) {
            int j = 0;
            while (j < s.length()) {
                string x = "";
                x += s[j];
                x += s[j+1];
                x += s[j+2];
                x += s[j+3];
                x += s[j+4];
                j += 6;
                if (x == ".....") {
                    break;
                }
                lenga++;
            }
            lengb = (s.length() - j) / 6 + 1;
            sa = vector<string>(lenga);
            sb = vector<string>(lengb);
        }
        int j = 0;
        FOR(ii, 0, lenga) {
            string x = "";
            x += s[j];
            x += s[j+1];
            x += s[j+2];
            x += s[j+3];
            x += s[j+4];
            j += 6;
            sa[ii] += x;
        }
        j += 6;
        FOR(ii, 0, lengb) {
            string x = "";
            x += s[j];
            x += s[j+1];
            x += s[j+2];
            x += s[j+3];
            x += s[j+4];
            j += 6;
            sb[ii] += x;
        }
    }
    FOR(i, 0, lenga) {
        a = a * 10 + mp[sa[i]];
    }
    FOR(i, 0, lengb) {
        b = b * 10 + mp[sb[i]];
    }
    int sum = a + b;
    vi arr;
    while (sum > 0) {
        arr.push_back(sum % 10);
        sum /= 10;
    }
    reverse(arr.begin(), arr.end());
    
    FOR(r, 0, 7) {
        FOR(i, 0, arr.size()) {
            cout << s[arr[i]][r*5+0];
            cout << s[arr[i]][r*5+1];
            cout << s[arr[i]][r*5+2];
            cout << s[arr[i]][r*5+3];
            cout << s[arr[i]][r*5+4];
            if (i != arr.size() -1)
                cout << ".";
        }
        cout << endl;
    }
    return 0;
}

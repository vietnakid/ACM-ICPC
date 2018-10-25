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

map<string, int> mp;

string special = " ,.#?!'()|/\"";

bool isSpecial(char x) {
    FOR(i, 0, special.size()) {
        if (x == special[i]) {
            return true;
        }
    }
    return false;
}

string toLower(string s) {
    string res = "";
    FOR(i, 0, s.size()) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
        res += c;
    }
    return res;
}

bool check(string s) {
    FOR(i, 0, s.size()) {
        if (s[i] < 'a' || s[i] > 'z') {
            return false;
        }
    }
    return true;
}

void Delim (string fileName){

  int n = fileName.length();  
    char arr[n+1];   
    strcpy(arr, fileName.c_str());  
  char * cut;
  cut = strtok (arr,"\" ,.#?!'()|/");

  while (cut != NULL)
  {
      if (strlen(cut) > 0) {
            string cur = toLower(cut);
            // cerr << cur << endl;
            // if (check(cur))
            mp[cur]++;
        }
    // printf ("%s\n",cut);
    cut = strtok (NULL, "\" ,.#?!'()|/");
  }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    string s;
    while (cin >> s) {
        Delim(s);
    }
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if (it->first.length() > 0) {
            string s = it->first;
            // FOR(i, 0, s.size()) {
            //     cout << (int)s[i] << " ";
            // }
            // cout << endl;
            cout << it->first << "(" << it->second << ")" << endl;
        }
    }
    return 0;
}
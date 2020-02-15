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

struct TRIE {
    string val;
    TRIE* child[2];
};

TRIE* root = new TRIE();

void putTrie(string s) {
    TRIE* node = root;
    string val = "";
    for (auto c : s) {
        int childNum = c - '0';
        val.push_back(c);
        if (node->child[childNum] == NULL) {
            node->child[childNum] = new TRIE();
            node->child[childNum]->val = val;
        }
        node = node->child[childNum];
    }
}

void vietnakid() {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        string s = a.substr(i, a.size() - i);
        putTrie(s);
    }
    for (int i = 0; i < b.size(); i++) {
        string s = b.substr(i, b.size() - i);
        putTrie(s);
    }

    queue<TRIE*> q;
    q.push(root);
    while (!q.empty()) {
        TRIE* node = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            if (node->child[i] == NULL) {
                cout << node->val + (char)('0' + i) << "\n";
                return;
            } else {
                q.push(node->child[i]);
            }
        }
    }
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
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

struct trie {
    trie* child[26];
    int isWord = 0;
    trie() {
        memset(child, 0, sizeof(child));   
    }
};

string arr[10005];
int n;
set<string> suffix;
ll sum = 0, res = 0;
ll cnt[26];
trie* prefix;
ll last[30];

void push_trie(char* s) {
    trie* node = prefix;
    int leng = strlen(s);
    for (int i = 0; i < leng; i++) {
        int x = s[i] - 'a';
        if (node->child[x] == NULL) {
            node->child[x] = new trie;
        }
        // cerr << s[i] << " " << x << " " << node << " " << node->child[x] << endl;
        node = node->child[x];
    }
    node->isWord = true;
}

void DFS_trie(trie * node, int depth, int c) {
    res += (node->isWord || (last[c] && depth >= 2));
    for (int i = 0; i < 26; i++) {
        if (node->child[i] != NULL) {
            DFS_trie(node->child[i], depth+1, i);
        } else if (node != prefix) {
            res += cnt[i];
        }   
    }
    // cerr << res << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    memset(last, 0, sizeof(last));
    prefix = new trie;

    scanf("%d", &n);
    for (int i = 0 ; i < n; i++) {
        char arr[50];
        scanf("%s", arr);
        push_trie(arr);
        int leng = strlen(arr);
        last[arr[leng - 1] - 'a'] = 1;
        string s = "";
        for (int j = leng-1; j >= 0; j--) {
            s.push_back(arr[j]);
            if (suffix.insert(s).second) {
                cnt[arr[j] - 'a']++;
                sum++;
            }
        }
    }


    // for (auto x : suffix) {
    //     cerr << x << endl;
    // }
    // cerr << sum << endl;
    
    res = 0;
    DFS_trie(prefix, 0, 27);
    printf("%lld\n", res);
    return 0;
}
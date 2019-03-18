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

struct Node {
    int value, height;
    Node* left, * right;

    Node() {} 
    Node(Node* l, Node* r, int v, int h) 
    { 
        left = l; 
        right = r; 
        value = v; 
        height = h;
    } 
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int n; cin >> n;
    Node* root = new Node(NULL, NULL, n, 1);
    int res = 1;
    while (cin >> n) {
        Node* node = root;
        while (true) {
            if (n < node->value) {
                if (node->left == NULL) {
                    node->left = new Node(NULL, NULL, n, node->height + 1);
                    res = max(res, node->left->height);
                    break;
                } else {
                    node = node->left;
                }
            }
            if (n > node->value) {
                if (node->right == NULL) {
                    node->right = new Node(NULL, NULL, n, node->height + 1);
                    res = max(res, node->right->height);
                    break;
                } else {
                    node = node->right;
                }
            }
        }
    }
    cout << res << "\n";
    return 0;
}
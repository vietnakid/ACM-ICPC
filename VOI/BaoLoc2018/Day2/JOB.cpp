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

int n;
vii arr;
ll res = 0;
int maxValue = 0;

priority_queue<ll, vector<ll> > heap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.rbegin(), arr.rend());
    int t = arr[0].first;
    int i = 0;
    while (i < n) {
        // cerr << i << " " << t << endl;
        while (i < n && t == arr[i].first) {
            heap.push(arr[i].second);
            i++;
        }
        if (!heap.empty() && t > 0) {
            t--;
            res += heap.top();
            heap.pop();
        }
        if (heap.empty()) {
            if (i < n)
                t = min(arr[i].first, t);
        }
    }
    while (!heap.empty() && t > 0) {
        t--;
        res += heap.top();
        heap.pop();
    }
    cout << res << endl;
    return 0;
}
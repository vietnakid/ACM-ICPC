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

int n, x;
int arr[1000006];
vi head, tail;
vi minPos(1000006, INF), maxPos(1000006, 0);
vi maxHead, minTail;
set<ii> res;
ll cnt = 0;

void init() {
    head.push_back(arr[0]);
    maxHead.push_back(maxPos[1]);
    for (int i = arr[0]+1; i <= x; i++) {
        if (minPos[i] >= maxPos[i-1]) {
            head.push_back(i);
            maxHead.push_back(maxPos[i]);
        } else {
            break;
        }
    }
    
    tail.push_back(arr[n-1]);
    minTail.push_back(minPos[arr[n-1]]);
    for (int i = arr[n-1]-1; i >= 1; i--) {
        if (maxPos[i] <= minPos[i+1]) {
            tail.push_back(i);
            minTail.push_back(minPos[i]);
        } else {
            break;
        }
    }
    reverse(tail.begin(), tail.end());
    reverse(minTail.begin(), minTail.end());
}

void solve() {
    if (head.size() == x) {
        cout << (ll)x*(ll)(x+1) / 2 << "\n";
        return;
    }

    // End part is sort ==> erase begin part
    for (int i = *tail.begin() - 1; i <= x; i++) {
        res.insert({1, i});
    }

    // Begin part is sort ==> erase end part
    for (int i = head.back() + 1; i >= 1; i--) {
        res.insert({i, x});
    }

    for (auto a : res) {
        cerr << a.first << " " << a.second << "\n";
    }

    cnt = res.size();
    for (int i = 0; i < (int)head.size(); i++) {
        int value = maxHead[i];
        int pos = distance(minTail.begin(), lower_bound(minTail.begin(), minTail.end(), value));
        ll remainPos = tail.size() - pos;
        if (remainPos > 0 && head.back() == *tail.begin() - 1) remainPos--;
        cerr << value << " .. " << tail[pos] << " - " << remainPos << "\n";
        cnt += remainPos;
    }
    cout << cnt << "\n";
}

void vietnakid() {
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        minPos[arr[i]] = min(minPos[arr[i]], i);
        maxPos[arr[i]] = max(maxPos[arr[i]], i);
    }

    init();

    solve();
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
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

ll memo[100005][4];

int n;
int arr[100005];
ll result;

bitset<100005> isFree;
int rr[100005];

int back[100005], forw[100005];
ll sum[100005], p[100005], sub[100005];

bool inRange(int index) {
    return index >= 0 && index < n;
}

void sovle10(int index) {
    isFree[index] = false;
    result++;
    // for (int g = 0; g < n; g++) {
    //     cerr << 1 - (int)isFree[g];
    // }
    // cerr << "\n";
    rr[index]++;
    for (int i = -arr[index]; i <= arr[index]; i++) {
    // for (int i = -1; i <= arr[index]; i++) {
        int j = index + i;
        if (inRange(j) && isFree[j]) {
            sovle10(j);
        }
    }
    isFree[index] = true;
}

// step = 0 --> -1
// step = 1 --> 1
// step = 2 --> 2

ll cal(int index, int step) {
    if (!inRange(index)) return 0;
    if (memo[index][step] != -1) 
        return memo[index][step];
    ll res = 0;
    switch (step) {
        case 0:
            if (inRange(index+1))
                res = (res + cal(index+1, 2)) % nMod;
            break;
        case 1:
            res = (res + cal(index-1, 1)) % nMod;
            res = (res + cal(index-1, 2)) % nMod;
            if (index > 1 && (arr[index-2] == 2))
                res = (res + cal(index-2, 0)) % nMod;
            break;
        case 2:
            if (arr[index-2] == 2) {
                res = (res + cal(index-2, 1)) % nMod;
                res = (res + cal(index-2, 2)) % nMod;
            }
            break;
    }
    return memo[index][step] = res;
}

void solveForward() {
    memo[0][0] = 0;
    memo[0][1] = 1;
    memo[0][2] = 0;
    memo[1][2] = 0;

    for (int i = 0; i < n; i++) {
        ll res = 0;
        for (int step = 0; step < 3; step++) {
            res = (res + cal(i, step)) % nMod;
        }
        result = (result + res) % nMod;
        // cerr << res << " -- " << rr[i] <<  "\n\n";
    }
    // cerr << "not backward = " << result << "\n";
}

void solveBackward() {
    // for (int i = 1; i < n; i++) {
        // {   
        //     int step = forw[i];
        //     for (int j = i - (forw[i] * 2); j < i; j += 2) {
        //         ll cnt = min(back[i+1], step);
        //         ll curForward = cal(j, 1);

        //         ll res = (cnt * curForward) % nMod;
        //         result = (result + res) % nMod;
        //         step--;
        //     }
        // }

        // {
        //     int step = forw[i] - 1;
        //     for (int j = i - (forw[i] * 2); j < i; j += 2) {
        //         ll cnt = min(back[i-1], step);
        //         ll curForward = cal(j, 1);

        //         ll res = (cnt * curForward) % nMod;
        //         result = (result + res) % nMod;
        //         step--;
        //     }
        // }
    // }

    for (int i = 1; i < n; i++) {
        int step = forw[i];
        int bck = min(back[i+1], step);
        if (bck == 0) continue;
        int start = i - (step * 2);
        int end = i+1 - (bck * 2) + 1;
        sum[start] += bck;
        sum[i] -= bck;
        p[end] += 1;
        p[i] -= 1;
        sub[i] += bck-1;
        // cerr << i << ": " << step << " " << bck << " " << start << " " << end << "\n";
    }

    for (int i = 1; i < n; i++) {
        int step = forw[i];
        int bck = min(back[i-1], step - 1);
        if (bck <= 0) continue;
        int start = i - (step * 2);
        int end = i+1 - (bck * 2) - 1;
        sum[start] += bck;
        sum[i-2] -= bck;
        p[end] += 1;
        p[i-2] -= 1;
        sub[i-2] += bck-1;
        // cerr << i << ": " << step << " " << bck << " " << start << " " << end << "\n";
    }

    ll res = 0;
    sub[0] = -p[0];
    sub[1] = -p[1];
    for (int i = 0; i < n; i++) {
        
        if (i >= 2) {
            p[i] += p[i-2];
            sum[i] += sum[i-2];
            sub[i] += sub[i-2] - p[i];
        }
        res = (res + ((sum[i] + sub[i]) * cal(i, 1)) ) % nMod;
        // cerr << i << ": " << sum[i] << " " << p[i] << " " << sub[i] << "\n";
    }
    result = (result + res) % nMod;

    
}

void init() {
    back[0] = back[1] = 0;
    for (int i = 2; i < n; i++) {
        back[i] = 0;
        if (arr[i] == 2) {
            back[i] = back[i-2] + 1;
        }
    }

    forw[0] = forw[1] = 0;
    for (int i = 2; i < n; i++) {
        forw[i] = 0;
        if (arr[i-2] == 2) 
            forw[i] = forw[i-2] + 1;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int TC; cin >> TC;
    while (TC--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        memset(back, 0, sizeof(back));
        memset(forw, 0, sizeof(forw));
        memset(sum, 0, sizeof(sum));
        memset(sub, 0, sizeof(sub));
        memset(p, 0, sizeof(p));
        init();

        // result = 0;
        // isFree.set();
        // memset(rr, 0, sizeof(rr));
        // sovle10(0);
        // cout << result << "\n";

        result = 0;
        memset(memo, -1, sizeof(memo));
        solveForward();
        solveBackward();
        cout << result << "\n";

        // cout << "\n";
    }
    return 0;
}
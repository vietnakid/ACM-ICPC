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

int largersRec2(vector<int> blockNumber) {
    int res = 0;
    if (blockNumber[0] >= 2) {
        res = blockNumber[0]/2*2 + blockNumber[1] + blockNumber[2]/2*2 + blockNumber[5]/2*2;
    }
    return res * 4;
}

int largersRec4(vector<int> blockNumber) {
    vector<vector<int> > devideCase = {
        {1, 0, 1, 1, 1, 0, 2},
        {1, 0, 0, 1, 1, 1, 2},
        {0, 0, 1, 0, 1, 2, 2},
        {0, 0, 1, 1, 0, 2, 2},
        {0, 0, 0, 1, 1, 1, 2},
        {0, 0, 1, 1, 1, 0, 2},
        {0, 0, 0, 0, 0, 1, 2},
        {0, 0, 0, 0, 1, 0, 2},
        {0, 0, 0, 0, 0, 0, 4}
        
    };
    int res = 0;
    for (int i = 0; i < devideCase.size(); i++) {
        while (true) {
            bool check = true;
            for (int j = 0; j < 7; j++) {
                check &= blockNumber[j] >= devideCase[i][j];
            }
            if (!check) break;
            int cnt = 0;
            for (int j = 0; j < 7; j++) {
                blockNumber[j] -= devideCase[i][j];
                cnt += devideCase[i][j];
            }
            res += cnt;
        }
    }
    int cnt2 = blockNumber[3] + blockNumber[4];
    int cnt = min(cnt2, min(blockNumber[2], blockNumber[5]));
    res += blockNumber[0] + blockNumber[1] + cnt*3 + (blockNumber[2] - cnt)/2*2 + (blockNumber[5] - cnt)/2*2;

    return res * 4;
}

int findLargestRectangle(std::vector<int> blockNumber)
{
    int res = largersRec2(blockNumber);
    res = max(res, largersRec4(blockNumber));
    return res;

}

void vietnakid() {
    vi in = {1, 1, 1, 1, 1, 1, 0}; // 24
    // in = {1, 1, 3, 2, 0, 0, 2}; // 36
    // in = { 1, 2, 1, 0, 2, 1, 2 };	// 36
    // in = { 2, 2, 1, 1, 1, 1, 2 };	// 40
    // in = { 0, 0, 2, 1, 0, 0, 0 };	// 12
    // in = { 0, 0, 2, 0, 1, 0, 0 };	// 8
    in = { 2, 5, 0, 0, 0, 0, 0 };	// 8
    cout << findLargestRectangle(in) << "\n";
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
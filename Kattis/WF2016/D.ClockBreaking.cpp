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
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int k;

char digit[7][10][5] = {
{".XX.","....",".XX.",".XX.","....",".XX.",".XX.",".XX.",".XX.",".XX."},
{"X..X","...X","...X","...X","X..X","X...","X...","...X","X..X","X..X"},
{"X..X","...X","...X","...X","X..X","X...","X...","...X","X..X","X..X"},
{"....","....",".XX.",".XX.",".XX.",".XX.",".XX.","....",".XX.",".XX."},
{"X..X","...X","X...","...X","...X","...X","X..X","...X","X..X","...X"},
{"X..X","...X","X...","...X","...X","...X","X..X","...X","X..X","...X"},
{".XX.","....",".XX.",".XX.","....",".XX.",".XX.","....",".XX.",".XX."}
};

char display[7][22] = {
".??...??.....??...??.",
"?..?.?..?...?..?.?..?",
"?..?.?..?.?.?..?.?..?",
".??...??.....??...??.",
"?..?.?..?.?.?..?.?..?",
"?..?.?..?...?..?.?..?",
".??...??.....??...??."
};

vector<string> result(7, ".....................");

vector<vector<string> > arr;

set<ii > isWork;

vector<string > generate(int minute) {
    vector<string> res(7, "");
    int hours = minute / 60;
    minute %= 60;
    hours %= 24;
    // cerr << hours << " : " << minute << endl;

    // First digits hours
    if (hours < 10) {
        FOR(i, 0, 7) {
            FOR(j, 0, 4) {
                res[i].push_back('.');
            }
        }
    } else {
        FOR(i, 0, 7) {
            FOR(j, 0, 4) {
                res[i].push_back(digit[i][hours / 10][j]);
            }
        }
    }

    FOR(i, 0, 7) {
        res[i].push_back('.');
    }

    // Second digits hours

    FOR(i, 0, 7) {
        FOR(j, 0, 4) {
            res[i].push_back(digit[i][hours % 10][j]);
        }
    }

    FOR(i, 0, 7) {
        res[i].push_back('.');
    }

    // Colons

    FOR(i, 0, 7) {
        if (i == 2 || i == 4)
            res[i].push_back('X');
        else
            res[i].push_back('.');
    }

    FOR(i, 0, 7) {
        res[i].push_back('.');
    }

    // First digits minute

    FOR(i, 0, 7) {
        FOR(j, 0, 4) {
            res[i].push_back(digit[i][minute / 10][j]);
        }
    }

    FOR(i, 0, 7) {
        res[i].push_back('.');
    }

    // Second digits minute

    FOR(i, 0, 7) {
        FOR(j, 0, 4) {
            res[i].push_back(digit[i][minute % 10][j]);
        }
    }

    // FOR(i, 0, 7) {
    //     cout << res[i] << endl;
    // }
    // cout << endl;

    return res;
}

vector<vector<string> > generateArray(int start, int k) {
    vector<vector<string> > res(k);
    FOR(i, 0, k) {
        res[i] = generate(start+i);
    }

    return res;
}

bool isValid(int x, int y) {
    return display[x][y] == '?';
}

bool check(int minute) {
    vector<vector<string> > array = generateArray(minute, k);
    vvi isRemain(7, vi(21, 0));
    FOR(i, 0, k) {
        for(set<ii >::iterator it = isWork.begin(); it != isWork.end(); it++) {
            int x = it->first;
            int y = it->second;
            if (arr[i][x][y] != array[i][x][y]) {
                return false;
            }
        }
    }
    FOR(i, 0, k) {
        FOR(x, 0, 7) {
            FOR(y, 0, 21) {
                if (array[i][x][y] != array[0][x][y]) {
                    isRemain[x][y] = 1;
                }
            }
        }
    }

    for(set<ii >::iterator it = isWork.begin(); it != isWork.end(); it++) {
        int x = it->first;
        int y = it->second;
        result[x][y] = 'W';
    }


    FOR(i, 0, 7) {
        FOR(j, 0, 21) {
            int x = i, y = j;
            if (result[i][j] != 'W' && result[i][j] != '?' && isValid(i, j)) {
                if (isRemain[x][y] == 0 && arr[0][i][j] == array[0][i][j]) {
                    // cerr << i << " " << j << endl;
                    result[i][j] = '?';
                } else {
                    if (arr[0][i][j] == '.') {
                        result[i][j] = '0';
                    } else {
                        result[i][j] = '1';
                    }
                }
            }
        }
    }
    return true;
}

void input() {
    arr.resize(k);

    FOR(i, 0, k) {
        FOR(j, 0, 7) {
            string s; cin >> s;
            // cout << s << " " << i << " " << j << endl;
            arr[i].push_back(s);
        }
    }

    for (int j = 0; j < 7; j++) {
        for (int jj = 0; jj < 21; jj++) {
            for (int i = 0, check = true; i < k && check; i++) {
                if (arr[0][j][jj] != arr[i][j][jj]) {
                    isWork.insert({j, jj});
                    // cerr << j << " " << jj  << " " << arr[0][j][jj] <<  " " << arr[i][j][jj] << endl;
                    check = false;
                    break;
                }
            }
        }
    }

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> k;
    input();
    bool isok = false;
    FOR(i, 0, 24*60) {
        if (check(i)) {
            isok = true;
            // cerr << i << endl;
            // break;
        }
    }
    if (isok) {
        FOR(i, 0, 7) {
            cout << result[i] << endl;
        }
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}
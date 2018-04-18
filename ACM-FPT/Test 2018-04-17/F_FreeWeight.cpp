#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <string.h>
#include <cmath>

using namespace std;

#define REP(i, a, b) for (int i = (a); i < (b); i++)

const int nMAX = 1e6;

int itree[4*nMAX];

map<int, vector<int> > ma;

void update(int node, int value, int pos, int left, int right) {
    if (left > pos || right < pos) return;
    itree[node] = max(itree[node], value);
    if (left == right) return;
    int mid = (left + right) / 2;
    update(node * 2 + 1, value, pos, left, mid);
    update(node * 2 + 2, value, pos, mid+1, right);
}

int query(int node, int left, int right, int L, int R) {
    if (right < L || left > R) {
        return 0;
    }
    //cout << node << " " << L << " " << R << endl;
    if (left <= L && right >= R) {
        return itree[node];
    }
    int mid = (L + R) / 2;
    int m1 = query(node * 2 + 1, left, right, L, mid);
    int m2 = query(node * 2 + 2, left, right, mid+1, R);
    return max(m1, m2);
}

int main()
{
    int n;
    scanf("%d", &n);
    int res = 0;

    REP(ii, 0, 2) {
        ma.clear();
        memset(itree, 0, sizeof itree);
        REP(i, 0, n) {
            int x;
            scanf("%d", &x);
            update(0, x, i, 0, n-1);
            ma[x].push_back(i);
        }

        for (map<int, vector<int> >::iterator it = ma.begin(); it != ma.end(); it++) {
            if (it->second.size() == 1) {
                res = max(res, it->first);
            } else {
                if ( it->second[1] - it->second[0] != 1) {
                    int q = query(0, it->second[0] + 1, it->second[1] - 1, 0, n-1);
                    int _res = min(q , it->first);
                    //cout << q << " from " << it->second[0] + 1 << " to " << it->second[1] - 1 << " " << it->first << endl;
                    res = max(res, _res);
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}

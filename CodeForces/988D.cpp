//
// Created by khanhvu2212 on 01/06/2018.
//
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int n;
vector<ll> a;
map<ll, int> m;

vector<ll> check(ll a) {
    vector<ll> res;
    vector<ll> res3;
    res.push_back(a);
    res3.push_back(a);
    ll init = a;
    ll add = 2;
    while (init + add <= 1e9) {
        if (m[init + add]) res.push_back(init + add);
        add *= add;
    }

    for(int i = 1; i<=2; i++) {
        if (m[a+i]) res3.push_back(a+i);
    }

    return (res.size() > res3.size()) ? res : res3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        m[tmp] = 1;
    }
    vector<ll> res;
    for (int i = 0; i < n; i++) {
        vector<ll> now = check(a[i]);
        if (now.size() > res.size()) res = now;
    }
    cout << res.size() << '\n';
    for (auto v : res) {
        cout << v << ' ';
    }

}

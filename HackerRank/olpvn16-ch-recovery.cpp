#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 2e8;

ll cal(string & nummin, string & nummax) {
	if (nummin <= nummax) return 0;
	int difleng = nummax.size() - nummin.size();
	int lengmin = nummin.size();
	int lengmax = nummax.size();
	string res = "";
	nummin.push_back(0);
	for (int i = 0; i < lengmin; i++) {
		if (difleng > 0 && nummin[i] > nummin[i+1]) {
			difleng--;
		} else {
			res.push_back(nummin[i]);
		}
	}
	nummin = "";
	for (int i = 0; i < lengmax; i++)
		nummin.push_back(res[i]);
	cout << nummin << endl;
	if (nummin <= nummax) return difleng;
	nummin.erase(nummin.size()-1, 1);
	if (nummin.size() <= 0) return -INF;
	return difleng + 1;
}

int main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	string nummin = arr[n-1], nummax;
	ll res = 0;
	for (int i = n-2; i >= 0; i--) {
		nummax = nummin;
		nummin = arr[i];
		res += cal(nummin, nummax);
		cout << res << " " << nummin << " " << nummax <<  endl;
	}
	if (res < 0) {
		cout << -1 << endl;
	} else {
		cout << res << endl;
	}
	return 0;
}
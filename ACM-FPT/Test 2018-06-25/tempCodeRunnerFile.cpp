void dijkstra() {
    while (!heap.empty()) {
        ii node = heap.top();
        heap.pop();
        int u = node.second;
        int x = node.first;
        isFree[u] = false;
        cerr << u << " " << d[u] << endl;
        if (abs(brr[u].first - m) + abs(brr[u].second - n) == 0) {
            // cerr << "finish " << d[u] << endl;
            res = min(res, x);
            break;
        } else if (brr[u].first == m || brr[u].second == n) {
            res = min(res, x + 1);
            // cerr << "res = " << res << endl;
        }
        FOR(i, 0, arr[u].size()) {
            int v = arr[u][i].first;
            int c = arr[u][i].second;
            if (isFree[v] && d[v] > d[u] + c) {
                d[v] = d[u] + c;
                heap.push({d[v], v});
            }
        }
    }
}
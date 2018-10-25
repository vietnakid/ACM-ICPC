#include <bits/stdc++.h> 
 
using namespace std;
 
const int MAXW = 75;
const int MAXH = 75;
 
bool isBorder(int x, int y, int H, int W) {
	return x == 0 || y == 0 || x == H + 1 || y == W + 1;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
	int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	int board[MAXH][MAXW + 3];
	int dis[MAXH + 2][MAXW + 2];
 
	int w, h, t = 0;
	int x1, y1, x2, y2;
    string input;
	while (true) {
        getline(cin, input);
        stringstream strings(input);
        strings >> w >> h;
        if (w == 0 && h == 0) break;
		t++;
		for (int h1 = 0; h1 < h; ++h1) {	
            getline(cin, input);
			for(int w1 = 0; w1 < w; ++w1) {
                char xx = input[w1];
                // cerr << xx << endl;
				if (xx == 'X') {
					board[h1][w1] = 1;
				}
			}
		}
 
		if (t > 1) {
            printf("\n");
        }
		printf("Board #%d:\n", t);
		int count = 0;
		while (true) {
            getline(cin, input);
            stringstream stringss(input);
            stringss >> y1 >> x1 >> y2 >> x2;
            if (y1 == 0 && x1 == 0 && y2 == 0 && x2 == 0) break;
			count++;
			if (x1 > h || x2 > h || y1 > w || y2 > w || x1 < 1 || x2 < 1 || y1 < 1 || y2 < 1) {
				printf("Pair %d: impossible.\n", count);
				continue;
			}
			
			for (int h1 = 0; h1 <= h + 1; ++h1) {
				for (int w1 = 0; w1 <= w + 1; ++w1) {
					dis[h1][w1] = -1;
				}
			}
 
			dis[x1][y1] = 0;
			queue<pair<int, int> > que;
			que.push(make_pair(x1, y1));
			while (!que.empty()) {
				pair<int, int> cur = que.front();
				que.pop();
				int x = cur.first, y = cur.second;
 
				if (x == x2 && y == y2) {
					break;
				}
 
				for (int d = 0; d < 4; ++d) {
					int nx = x, ny = y;	
					bool move = true;
					while (move) {
						nx += directions[d][0];
						ny += directions[d][1];
 
						move = false;
						if (0 <= nx && nx <= h + 1 && 0 <= ny && ny <= w + 1 && dis[nx][ny] < 0) {
							dis[nx][ny] = dis[x][y] + 1;
							if (isBorder(nx, ny, h, w) || board[nx - 1][ny - 1] != 1) {
								que.push(make_pair(nx, ny));
								move = true;
							}
						}
					}
				}
			}
 
 
			printf("Pair %d: ", count);
			if (dis[x2][y2] >= 0) {
				printf("%d segments.\n", dis[x2][y2]);
			} else {
				printf("impossible.\n");
			}
		}
	}
		
	return 0;  
}
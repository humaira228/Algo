#include <bits/stdc++.h>
using namespace std;

// Knight moves: 8 possible offsets
const int dr[8] = {-2,-2,-1,-1,1,1,2,2};
const int dc[8] = {-1,1,-2,2,-2,2,-1,1};

int bfs_min_knight_moves(int sr, int sc, int tr, int tc) {
    // distance array, -1 = unvisited
    int dist[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            dist[i][j] = -1;

    queue<pair<int,int>> q;
    dist[sr][sc] = 0;
    q.push({sr, sc});

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        if (r == tr && c == tc) {
            return dist[r][c];
        }
        for (int k = 0; k < 8; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return -1; // should never happen on a connected 8x8 board
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    while ( (cin >> a >> b) ) {
        // Convert from chess notation to 0-based indices
        // 'a'..'h' -> 0..7, '1'..'8' -> 0..7
        int sc = a[0] - 'a';
        int sr = a[1] - '1';
        int tc = b[0] - 'a';
        int tr = b[1] - '1';

        int moves = bfs_min_knight_moves(sr, sc, tr, tc);
        cout << "To get from " << a << " to " << b
             << " takes " << moves << " knight moves.\n";
    }

    return 0;
}
 
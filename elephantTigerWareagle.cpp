#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> grid;
bool visited[30][30];
int dr[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0,  1,-1, 1,-1, 0, 1};

void dfs(int r, int c) {
    visited[r][c] = true;
    for (int d = 0; d < 8; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr >= 0 && nr < N && nc >= 0 && nc < N &&
            !visited[nr][nc] && grid[nr][nc] == '1') {
            dfs(nr, nc);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int imageNum = 1;
    while ( (cin >> N) ) {
        grid.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> grid[i];
        }
        // reset visited
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                visited[i][j] = false;

        int warEagles = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    // found a new war eagle
                    warEagles++;
                    dfs(i, j);
                }
            }
        }

        cout << "Image number " << imageNum
             << " contains " << warEagles
             << " war eagles.\n";

        imageNum++;
    }
    return 0;
}

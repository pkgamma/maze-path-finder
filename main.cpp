#include <cstring>
#include <iostream>

using namespace std;

#define N 5

bool isValidCell(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N) {
        return false;
    }

    return true;
}

void countPaths(int maze[N][N], int path_length, int des_x, int des_y, int x,
                int y, int visited[N][N], int& count) {
    if (x == des_x && y == des_y && path_length == 0) {
        count++;
        return;
    }

    if (path_length == 0) {
        return;
    }

    visited[x][y] = 1;

    if (isValidCell(x, y) && maze[x][y]) {
        // go down
        if (x + 1 < N && !visited[x + 1][y] && y % 2 == 0) {
            countPaths(maze, path_length - 1, des_x, des_y, x + 1, y, visited,
                       count);
        }
        // go up
        if (x - 1 >= 0 && !visited[x - 1][y] && y % 2 == 1) {
            countPaths(maze, path_length - 1, des_x, des_y, x - 1, y, visited,
                       count);
        }
        // go right
        if (y + 1 < N && !visited[x][y + 1] && x % 2 == 0) {
            countPaths(maze, path_length - 1, des_x, des_y, x, y + 1, visited,
                       count);
        }
        // go left
        if (y - 1 >= 0 && !visited[x][y - 1] && x % 2 == 1) {
            countPaths(maze, path_length - 1, des_x, des_y, x, y - 1, visited,
                       count);
        }
    }
    
    visited[x][y] = 0;
}

void printArray(int maze[N][N], int starting_y_offset) {

    // print first line (starting arrow)

    string first_line = "";

    for (int i = 0; i < N; i++) {
        if (maze[0][i] == 1) {
            first_line = first_line + "↓";
            break;
        } else {
            first_line = first_line + "    ";
        }
    }

    cout << first_line << endl;

    // clean print rest of maze

    for (int i = 0; i < N; i++) {
        string temp = "";
        for (int j = 0; j < N; j++) {
            if (maze[i][j] == 1) {
                cout << maze[i][j] << " ";

                if (j != N - 1) {
                    if (maze[i][j + 1] == 1) {
                        if (i % 2 == 0) {
                            cout << "→ ";
                        } else {
                            cout << "← ";
                        }
                    } else {
                        cout << "  ";
                    }
                }

                if (i != N - 1) {
                    if (maze[i + 1][j] == 1) {
                        if ((j + starting_y_offset) % 2 == 0) {
                            temp = temp + "↓   ";
                        } else {
                            temp = temp + "↑   ";
                        }
                    } else {
                        temp = temp + "    ";
                    }
                }
            } else {
                cout << "  ";

                if (j != N - 1) {
                    if (i % 2 == 0) {
                        cout << "  ";
                    } else {
                        cout << "  ";
                    }
                }

                if (i != N - 1) {
                    if (j % 2 == 0) {
                        temp = temp + "    ";
                    } else {
                        temp = temp + "    ";
                    }
                }
            }
        }

        cout << endl << temp << endl;
    }
}

int main() {
    // this program calculates the number of quique paths
    // from upper left (1, 1) to defined locatoin (x, y).
    // written by Philip Kuo for Judy's research

    // ========================================
    // =========== Input Maze Here ============
    // ========================================
    // ========================================

    int maze[N][N] = {{0, 1, 1, 0, 0},
                      {1, 1, 1, 0, 0},
                      {1, 1, 1, 0, 0},
                      {0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0}};

    // ========================================
    // ========================================

    int visited[N][N];

    int des_x = 0;
    int des_y = 0;
    int path_length = 0;

    cout << endl;
    cout << "輸入圖形（於 main.cpp）：完成" << endl;
    cout << "輸入起點座標（1, 1）：完成" << endl;
    cout << "輸入終點座標 (x, y)：" << endl;
    cout << "    輸入 x 值：";
    cin >> des_y;
    cout << "    輸入 y 值：";
    cin >> des_x;
    cout << "輸入路線長：";
    cin >> path_length;

    cout << endl;

    des_x--;  // so that the upper right corner can be
    des_y--;  // entered as (1, 1) and not (0, 0).

    printArray(maze, x);

    int count = 0;

    memset(visited, 0, sizeof visited);

    // start from upper left (0, 0).

    countPaths(maze, path_length, des_x, des_y, 0, 0, visited, count);

    cout << "由起點（左上）至終點，共有 " << count << " 條路徑" << endl;

    return 0;
}

#include <cstring>
#include <iostream>

using namespace std;

#define N 12

bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N) {
        return false;
    }

    return true;
}

int findStartingEmptyRow(int maze[N][N]) {
    int start_empty_y = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (maze[i][j] == 1) {
                start_empty_y++;
                break;
            }
        }
    }
    return start_empty_y;
}

void findUniquePaths(int maze[N][N], int path_length, int start_x, int des_x,
                     int des_y, int x, int y, int visited[N][N], int& count) {
    // note: the x and y notation is flipped here.

    if (x == des_x && y == des_y && path_length == 0) {
        count++;
        return;
    }

    if (path_length == 0) {
        return;
    }

    visited[x][y] = 1;

    if (isValid(x, y) && maze[x][y]) {
        // go down
        if (x + 1 < N && !visited[x + 1][y] && ((y + start_x) % 2 == 0)) {
            findUniquePaths(maze, path_length - 1, start_x, des_x, des_y, x + 1,
                            y, visited, count);
        }
        // go up
        if (x - 1 >= 0 && !visited[x - 1][y] && ((y + start_x) % 2 == 1)) {
            findUniquePaths(maze, path_length - 1, start_x, des_x, des_y, x - 1,
                            y, visited, count);
        }
        // go right
        if (y + 1 < N && !visited[x][y + 1] && x % 2 == 0) {
            findUniquePaths(maze, path_length - 1, start_x, des_x, des_y, x,
                            y + 1, visited, count);
        }
        // go left
        if (y - 1 >= 0 && !visited[x][y - 1] && x % 2 == 1) {
            findUniquePaths(maze, path_length - 1, start_x, des_x, des_y, x,
                            y - 1, visited, count);
        }
    }

    visited[x][y] = 0;
}

int findStartX(int maze[N][N]) {
    int start_x = 0;
    for (int i = 0; i < N; i++) {
        if (maze[0][i] == 1) {
            return start_x;
        } else {
            start_x++;
        }
    }
    return 0;
}

void printMaze(int maze[N][N], int start_x, int des_x, int des_y) {
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

    int start_empty_y = findStartingEmptyRow(maze);

    for (int i = 0; i < start_empty_y; i++) {
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
                        if (j != des_y) {
                            cout << "  ";
                        }
                    }
                }

                if (i == des_x && j == des_y) {
                    cout << "→ ";
                }

                if (i != N - 1) {
                    if (maze[i + 1][j] == 1) {
                        if ((j + start_x) % 2 == 0) {
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
    // from upper left (1, something) to defined locatoin (x, y).
    // written by Philip Kuo for Judy's research

    // ========================================
    // =========== Input Maze Here ============
    // =========== 在此輸入預設的迷宮 ============
    // ========================================
    // ========================================
    // == remember to change defined N size ===

    int maze[N][N] = {
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    // int maze[N][N] = {
    //     {0, 0, 1, 1, 1, 0, 0, 0}, {1, 1, 1, 1, 1, 0, 0, 0},
    //     {1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0},
    //     {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
    // };

    // ========================================
    // ========================================

    int visited[N][N];

    int mode_select_1;
    cout << "----------------------------------------" << endl;
    cout << "選擇資料載入模式（1: 手動輸入迷宮 / 2: 使用預設的迷宮）" << endl;
    cout << "請輸入選擇：";
    cin >> mode_select_1;

    if (mode_select_1 == 1) {
        cout << "----------------------------------------" << endl;
        cout << "請以 1 表示可拜訪的交會點，0 "
                "代表不可，並以單橫行表示要輸入的二維陣列迷宮，以第一橫行為先，"
                "左至右輸入，後接其下橫行，依此類推"
             << endl;
        cout << "請輸入迷宮：";
        string input;
        cin >> input;

        while (input.length() != N * N) {
            cout << "長度好像不對，請再試一次：";
            cin >> input;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (input[i * N + j] == '1') {
                    maze[i][j] = 1;
                } else {
                    maze[i][j] = 0;
                }
            }
        }
    }

    int des_x = 0;
    int des_y = 0;
    int path_length = 0;

    cout << "----------------------------------------" << endl;
    cout << "選擇終點座標 (x, y)，左上為 (1, 1)" << endl;
    cout << "請輸入 x 值：";
    cin >> des_y;
    cout << "請輸入 y 值：";
    cin >> des_x;

    while ((des_x - 1) % 2 == 1) {
        cout << "輸入的 y 好像不對，請再試一次：";
        cin >> des_x;
    }

    int mode_select_2 = 0;
    cout << "----------------------------------------" << endl;
    cout << "選擇程式模式（1: 自動尋找所有路徑長 / 2: 手動輸入路線長）" << endl;
    cout << "請輸入選擇：";
    cin >> mode_select_2;

    des_x--;  // so that the upper right corner can be
    des_y--;  // entered as (1, 1) and not (0, 0).

    int start_x = findStartX(maze);
    int start_y = 0;

    cout << "----------------------------------------" << endl;
    printMaze(maze, start_x, des_x, des_y);

    if (mode_select_2 == 1) {
        cout << "----------------------------------------" << endl;
        cout << "所有 0 至 100 單位長的路徑中：" << endl << endl;
        for (int i = 0; i <= 100; i++) {
            path_length = i;
            int count = 0;
            memset(visited, 0, sizeof visited);
            // start from upper left (0, 0).
            findUniquePaths(maze, path_length, start_x, des_x, des_y, start_y,
                            start_x, visited, count);
            if (count != 0) {
                cout << "路線長為 " << path_length << " 的話，有 " << count
                     << " 條路徑" << endl;
            }
        }

        cout << "----------------------------------------" << endl;
        cout << "運算結束，掰掰！" << endl;
        exit(0);

    } else {
        cout << "----------------------------------------" << endl;
        cout << "註：輸入 -1 以離開程式" << endl;
        while (true) {
            cout << "----------------------------------------" << endl;
            cout << "請輸入路線長：";

            // cin with exception prevention
            // taken from:
            // https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
            while (!(cin >> path_length)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "你輸入的好像不是個數字耶，請再試一次：";
            }

            if (path_length == -1) {
                cout << "----------------------------------------" << endl;
                cout << "要離開了？好吧，掰掰！" << endl;
                exit(0);
            }

            int count = 0;

            memset(visited, 0, sizeof visited);

            // start from upper left (0, 0).

            findUniquePaths(maze, path_length, start_x, des_x, des_y, start_y,
                            start_x, visited, count);

            cout << "不同路徑數：" << count << " 條路徑" << endl;
        }
    }

    return 0;
}

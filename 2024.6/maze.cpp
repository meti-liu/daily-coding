#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <algorithm>
#include <random>
#include <graphics.h> // EasyX库头文件

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;
const int CELL_SIZE = 25;
const char WALL = '#';
const char PATH = ' ';
const char PLAYER = '@';
const char START = 'S';
const char EXIT = 'E';

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

vector<vector<char>> maze(WIDTH, vector<char>(HEIGHT, WALL));
Point start(0, 0);
Point exitPoint(WIDTH - 1, HEIGHT - 1);

void initializeMaze() {
    srand(time(0));
    random_device rd;
    mt19937 g(rd());

    for (int i = 1; i < WIDTH - 1; i += 2) {
        for (int j = 1; j < HEIGHT - 1; j += 2) {
            maze[i][j] = PATH;
            vector<Point> directions = {Point(2, 0), Point(-2, 0), Point(0, 2), Point(0, -2)};
            shuffle(directions.begin(), directions.end(), g);
            for (auto dir : directions) {
                int nx = i + dir.x, ny = j + dir.y;
                if (nx > 0 && nx < WIDTH - 1 && ny > 0 && ny < HEIGHT - 1 && maze[nx][ny] == WALL) {
                    maze[i + dir.x / 2][j + dir.y / 2] = PATH;
                    maze[nx][ny] = PATH;
                    break;
                }
            }
        }
    }
    maze[start.x][start.y] = START;
    maze[exitPoint.x][exitPoint.y] = EXIT;
}

void drawMaze(const vector<vector<char>>& m) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int x = j * CELL_SIZE;
            int y = i * CELL_SIZE;
            if (m[i][j] == WALL) {
                setfillcolor(BLACK);
                solidrectangle(x, y, x + CELL_SIZE, y + CELL_SIZE);
            } else if (m[i][j] == PATH || m[i][j] == START || m[i][j] == EXIT) {
                setfillcolor(WHITE);
                solidrectangle(x, y, x + CELL_SIZE, y + CELL_SIZE);
            } else if (m[i][j] == PLAYER) {
                setfillcolor(GREEN);
                solidrectangle(x, y, x + CELL_SIZE, y + CELL_SIZE);
            } else if (m[i][j] == '.') {
                setfillcolor(RED);
                solidrectangle(x, y, x + CELL_SIZE, y + CELL_SIZE);
            }
            if (m[i][j] == START) {
                setfillcolor(BLUE);
                solidrectangle(x, y, x + CELL_SIZE, y + CELL_SIZE);
            }
            if (m[i][j] == EXIT) {
                setfillcolor(MAGENTA);
                solidrectangle(x, y, x + CELL_SIZE, y + CELL_SIZE);
            }
        }
    }
}

bool isValidMove(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && maze[x][y] != WALL;
}

void playerFindPath() {
    Point playerPos = start;
    maze[playerPos.x][playerPos.y] = PLAYER;
    while (playerPos.x != exitPoint.x || playerPos.y != exitPoint.y) {
        drawMaze(maze);
        FlushBatchDraw();
        char move = _getch();
        int dx = 0, dy = 0;
        if (move == 'w') dx = -1;
        if (move == 's') dx = 1;
        if (move == 'a') dy = -1;
        if (move == 'd') dy = 1;
        int newX = playerPos.x + dx;
        int newY = playerPos.y + dy;
        if (isValidMove(newX, newY)) {
            maze[playerPos.x][playerPos.y] = PATH;
            playerPos.x = newX;
            playerPos.y = newY;
            maze[playerPos.x][playerPos.y] = PLAYER;
        } else {
            cout << "\a";
        }
    }
    drawMaze(maze);
    FlushBatchDraw();
    MessageBox(NULL, "Victory!", "Congratulations", MB_OK);
}

bool computerFindPath() {
    vector<vector<bool>> visited(WIDTH, vector<bool>(HEIGHT, false));
    queue<Point> q;
    vector<vector<Point>> parent(WIDTH, vector<Point>(HEIGHT));
    q.push(start);
    visited[start.x][start.y] = true;
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        if (p.x == exitPoint.x && p.y == exitPoint.y) {
            Point path = exitPoint;
            while (!(path.x == start.x && path.y == start.y)) {
                maze[path.x][path.y] = '.';
                path = parent[path.x][path.y];
            }
            return true;
        }
        vector<Point> directions = {Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1)};
        for (auto dir : directions) {
            int nx = p.x + dir.x, ny = p.y + dir.y;
            if (isValidMove(nx, ny) && !visited[nx][ny]) {
                q.push(Point(nx, ny));
                visited[nx][ny] = true;
                parent[nx][ny] = p;
            }
        }
    }
    return false;
}

int main() {
    initgraph(WIDTH * CELL_SIZE, HEIGHT * CELL_SIZE);
    setbkcolor(WHITE);
    cleardevice();
    initializeMaze();
    drawMaze(maze);
    FlushBatchDraw();

    cout << "Choose mode: 1. Player find path 2. Computer find path" << endl;
    int choice;
    cin >> choice;

    BeginBatchDraw();
    if (choice == 1) {
        playerFindPath();
    } else if (choice == 2) {
        if (computerFindPath()) {
            drawMaze(maze);
            FlushBatchDraw();
            MessageBox(NULL, "Path found!", "Result", MB_OK);
        } else {
            MessageBox(NULL, "No path found!", "Result", MB_OK);
        }
    }
    EndBatchDraw();

    closegraph();
    return 0;
}

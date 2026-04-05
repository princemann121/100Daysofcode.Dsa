/* You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1. */

#include <stdio.h>

#define MAX 100

typedef struct {
    int x, y;
} Pair;

Pair queue[MAX * MAX];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    queue[rear++] = (Pair){x, y};
}

Pair dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int orangesRotting(int grid[MAX][MAX], int rows, int cols) {
    front = rear = 0;

    int fresh = 0;

    // Step 1: Add all rotten oranges
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                enqueue(i, j);
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0)
        return 0;

    int minutes = 0;
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    // BFS
    while (!isEmpty()) {
        int size = rear - front;
        int infected = 0;

        for (int i = 0; i < size; i++) {
            Pair curr = dequeue();

            for (int d = 0; d < 4; d++) {
                int nx = curr.x + directions[d][0];
                int ny = curr.y + directions[d][1];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    enqueue(nx, ny);
                    fresh--;
                    infected = 1;
                }
            }
        }

        if (infected)
            minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}

int main() {
    int rows, cols;
    int grid[MAX][MAX];

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter grid (0 empty, 1 fresh, 2 rotten):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, rows, cols);

    printf("Minimum minutes: %d\n", result);

    return 0;
}
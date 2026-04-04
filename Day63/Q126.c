/* Flood Fill

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill. */

#include <stdio.h>
#include <stdlib.h>

void dfs(int** image, int r, int c, int rows, int cols, int orig, int color) {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return;

    if (image[r][c] != orig)
        return;

    image[r][c] = color;

    dfs(image, r + 1, c, rows, cols, orig, color);
    dfs(image, r - 1, c, rows, cols, orig, color);
    dfs(image, r, c + 1, rows, cols, orig, color);
    dfs(image, r, c - 1, rows, cols, orig, color);
}

int main() {
    int m, n;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    // Allocate memory
    int** image = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        image[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int sr, sc, color;
    printf("Enter sr, sc and new color: ");
    scanf("%d %d %d", &sr, &sc, &color);

    int orig = image[sr][sc];

    if (orig != color) {
        dfs(image, sr, sc, m, n, orig, color);
    }

    printf("Updated Image:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
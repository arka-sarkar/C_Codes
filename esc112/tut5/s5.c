#include<stdio.h>

int solve(int maze[20][20], int r, int c, int R, int C, char path[20][20]) {
    if(r<0 || c<0 || r>=R || c>=C) return 0; // Dead ends
    if(maze[r][c] == 1 || path[r][c] == '*') return 0; // (r,c) - wall or already marked then return 0

    path[r][c] = '*'; // Mark the cell
    if(r == R-1 && c == C-1) return 1; // If it reaches (R-1, C-1)

    int res = solve(maze, r+1, c, R, C, path); // Forward
    if(res==0) res = solve(maze, r, c+1, R, C, path); // Down
    if(res==0) res = solve(maze, r-1, c, R, C, path); // Backward
    if(res==0) res = solve(maze, r, c-1, R, C, path); // Up
    if(res==0) {
        path[r][c] = '.'; // Backtrack if all path fails
        return 0;
    } else return 1; // If a path is successfully found return 1
}

int main() {
    int R, C;
    scanf(" %d %d", &R, &C);
    int maze[20][20];
    char path[20][20];

    for(int i=0; i<R; i++) for(int j=0; j<C; j++) {
        scanf(" %d", &maze[i][j]);
        if(maze[i][j]==0) path[i][j]='.';
        else if(maze[i][j]==1) path[i][j]='#'; // Wall
    }
    int res = solve(maze, 0, 0, R, C, path);
    
    putchar('\n');
    if(res == 1) {
        printf("Path found:\n");
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if(j != 0) putchar(' ');
                putchar(path[i][j]);
            }
            putchar('\n');
        }
    } else printf("No path found\n");
    
    return 0;
}
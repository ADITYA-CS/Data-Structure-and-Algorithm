#include <bits/stdc++.h>
using namespace std;

int c = 0;
void Print(vector<vector<char>> &grid) {
  cout << "Solution : " << ++c << "\n";
  for(auto row : grid) {
    for(auto el : row) {
      cout << el << " ";
    }
    cout << endl;
  }
}

bool IsSafe(vector<vector<char>> &grid, int r, int c) {
  int n = grid.size();

  int y = r - 1, x = c - 2;
  if (y >=0 && x >=0 && grid[y][x] == 'K')
    return false;

  y = r - 2, x = c - 1;
  if (y >=0 && x >=0 && grid[y][x] == 'K')
    return false;

  y = r - 2, x = c + 1;
  if (y >=0 && x < n && grid[y][x] == 'K')
    return false;

  y = r - 1, x = c + 2;
  if (y >=0 && x < n && grid[y][x] == 'K')
    return false;

  return true;
}

void Knight(vector<vector<char>> &grid, int q, int r = 0) {
  if(q == r) {
    Print(grid);
    return;
  }

  int n = grid.size();
  for (int j = 0; j < n; j++) {
    if(IsSafe(grid, r, j)) {
      grid[r][j] = 'K';
      Knight(grid, q, r + 1);
      grid[r][j] = '.';
    }
  }
}



int main() {
  int n;
  cout << "No of Knight :"
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n, '.'));
  Knight(grid, n);
}

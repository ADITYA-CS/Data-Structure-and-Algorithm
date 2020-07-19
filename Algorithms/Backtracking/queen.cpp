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
  for (int i = 0; i < n; i++) {
    if (grid[i][c] == 'Q')
      return false;
  }

  for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
    if (grid[i][j] == 'Q')
      return false;
  }

  for (int i = r, j = c; i >= 0 && j < n; i--, j++) {
    if (grid[i][j] == 'Q')
      return false;
  }
  return true;
}

void Queen(vector<vector<char>> &grid, int q, int r = 0) {
  if(q == r) {
    Print(grid);
  }

  int n = grid.size();
  for (int j = 0; j < n; j++) {
    if(IsSafe(grid, r, j)) {
      grid[r][j] = 'Q';
      Queen(grid, q, r + 1);
      grid[r][j] = '.';
    }
  }
}



int main() {
  int n;
  cout << "No of Queen :"
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n, '.'));
  Queen(grid, n);

}

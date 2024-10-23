#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
using namespace std;
ifstream fin("4.in");
ofstream fout("4.out");

/*auto partial_check_associativity = [&]() -> bool{
  /// Only check associativity for the newly added element at (row, col)
  /// We check that:
  /// (i * row) * col == i*(row*col)
  /// (row * col) * i == row * (col * i)
  int row = step / n;
  int col = step % n;
  for(int i=0;i<n;i++){
      if(mat[i][row] == -1 || mat[col][i] == -1 || mat[mat[i][row]][col] == -1 || mat[i][mat[row][col]] == -1 || mat[mat[row][col]][i] == -1 || mat[row][mat[col][i]] == -1)
      continue;
      if(mat[mat[i][row]][col] != mat[i][mat[row][col]]){
      return false;
      }
      if(mat[mat[row][col]][i] != mat[row][mat[col][i]]){
      return false;
      }
  }
  return true;
};
*/
/*
auto check_associativiy = [&]() -> bool{
  /// We check each possible pair of 3 numbers a,b,c in the set.
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        /// We can't check this pair, as it contains number that haven't been set yet.
        int mat12 = mat[i][j];
        int mat23 = mat[j][k];
        /// If (a*b)*c is not equal to a*(b*c) then we can stop the process because the operation is not associative
        if(mat[mat12][k] != mat[i][mat23]) return false;
      }
    }
  }
  /// All pairs of 3 numbers satisfied the condition, thus the operation is associative.
  return true;
};
*/


int main()
{
    int mat[20][20];
    int ans = 0;
    int n;
    int step = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    /// Initially we fill the table with -1's, -1 indicating the number has not been set yet.
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      mat[i][j] = -1;

      function<void()> backtrack = ([&]{
  /// We have filled the operation table and it's time to check if it's associative.
  if(step==n*n){
    bool ok = true;
    for(int i=0;i<n&&ok;i++){
    for(int j=0;j<n&&ok;j++){
      for(int k=0;k<n;k++){
        /// We can't check this pair, as it contains number that haven't been set yet.
        int mat12 = mat[i][j];
        int mat23 = mat[j][k];
        /// If (a*b)*c is not equal to a*(b*c) then we can stop the process because the operation is not associative
        if(mat[mat12][k] != mat[i][mat23]){
          ok = false;
          break;
        }
      }
    }
  }
    if(ok){
    ans++;
    //if(ans%10==0) cout<<ans<<'\n';
    }
    /// Regardless of if it is or not associative, we stop the process and don't go further.
    return;
  }
  /// We determine the row and the column of the element that we are currently setting.
  int row = step/n;
  int col = step%n;
  /// We try each possible number from 0 to n-1 and continue the process generating all tables with current configuration.
  for(int j=0;j<n;j++){
    mat[row][col] = j;
    /// We check to be sure that adding this number wont create a contradiction with the numbers we already have, to save computing time.
    /// If it would, then we can just skip ahead to the next number to try.
    /*if(!partial_check_associativity()){
      mat[row][col] = -1;
      continue;
    }*/

    /// Only check associativity for the newly added element at (row, col)
  /// We check that:
  /// (i * row) * col == i*(row*col)
  /// (row * col) * i == row * (col * i)
  int row = step / n;
  int col = step % n;
  bool ok = true;
  for(int i=0;i<n&&ok;i++){
      if(mat[i][row] != -1 &&
         mat[mat[i][row]][col] != -1 &&
         mat[row][col] != -1 &&
         mat[i][mat[row][col]] != -1 &&
         mat[mat[i][row]][col] != mat[i][mat[row][col]]){
      ok = false;
      break;
      }

      if(mat[row][col] != -1 &&
         mat[mat[row][col]][i] != -1 &&
         mat[col][i] != -1 &&
         mat[row][mat[col][i]] != -1 &&
         mat[mat[row][col]][i] != mat[row][mat[col][i]]){
      ok = false;
      break;
         }
  }
  if(!ok){
    mat[row][col] = -1;
    continue;
  }

    step++;
    backtrack();
    step--;
    mat[row][col] = -1;
  }
});

    backtrack();
    cout<<ans<<'\n';
    return 0;
}

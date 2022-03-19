#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minPathSum(vector<vector<int>>& grid, int i, int j) {

  if(i==0 && j==0){
    return grid.at(i).at(j);
  }else if(i==0 && j>0){
    return grid.at(i).at(j) + minPathSum(grid, i, j-1);
  }else if (i>0 && j==0){
    return grid.at(i).at(j) + minPathSum(grid, i-1, j);
  }else{
    return grid.at(i).at(j) + min(minPathSum(grid, i-1, j), minPathSum(grid, i, j-1));
  }
}

void lc_minPathSum()
{
  vector<vector<int>> grid {
    {1,3,1},
    {1,5,1},
    {4,2,1}
  };
  cout<<minPathSum(grid, 2, 2)<<endl;
}

int _minimumTotal(vector<vector<int>>& triangle, int i, int j) {
  if (i!=j)
  {
    if(i==0 && j==0){
      return triangle.at(i).at(j);
    }else if(i>0 && j==0){
      return triangle.at(i).at(j) + _minimumTotal(triangle, i-1, j);
    }else{
      return triangle.at(i).at(j) + min(_minimumTotal(triangle, i-1, j), _minimumTotal(triangle, i-1, j-1));
    }
  }else{
    if(i==0 && j==0){
      return triangle.at(i).at(j);
    }else{
      return triangle.at(i).at(j) + _minimumTotal(triangle, i-1, j-1);
    }
  }
  
  
}

int minimumTotal(vector<vector<int>>& triangle, int i) {
  int min=999999;
  for (size_t ii = 0; ii < triangle.at(i).size(); ii++)
  {
    int t = _minimumTotal(triangle, i, ii);
    if (t<min)
    {
      min=t;
    }
  }
  return min;  
}

void lc_minimumTotal()
{
  vector<vector<int>> triangle  {
    {2},
    {3,4},
    {6,5,7},
    {4,1,8,3}
  };
  cout<<minimumTotal(triangle, 3)<<endl;
}

int minFallingPathSum(vector<vector<int>>& matrix) {

}

void lc_minFallingPathSum(){

}

int main()
{
  // lc_minPathSum();
  // lc_minimumTotal();
  lc_minFallingPathSum();
}
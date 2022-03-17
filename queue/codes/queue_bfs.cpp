#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <tuple>

using namespace std;

bool vector_contain(vector<pair<int, int>> used, pair<int, int> target)
{
  for (int i = 0; i < used.size(); i++)
  {
    if (used.at(i).first == target.first && used.at(i).second == target.second){
      return true;
    }
  }
  return false;
}

void print_vector_dim2(vector<vector<int>>& rooms) {
  for (int i = 0; i < rooms.size(); i++)
  {
    for (int j = 0; j < rooms[i].size(); j++)
    {
        cout << rooms[i][j] << " ";
    }   
    cout << endl;
  }
}

class Solution{
  public:
    void wallsAndGates(vector<vector<int>>& rooms, vector<vector<int>>& results) {
      int rows = rooms.size();
      int cols = rooms.at(0).size();

      for (size_t i = 0; i < rows; i++)
      {
         for (size_t j = 0; j < cols; j++)
        {
          results.at(i).at(j) = _wallsAndGates(rooms, results, i, j, rows, cols);
        }
      }
      
    }

    int _wallsAndGates(vector<vector<int>>& rooms, vector<vector<int>>& results, int i, int j, int rows, int cols) {
      vector<pair<int, int>> direct;
      direct.push_back(pair<int,int>(0,1));
      direct.push_back(pair<int,int>(0,-1));
      direct.push_back(pair<int,int>(1,0));
      direct.push_back(pair<int,int>(-1,0));
      vector<pair<int, int>> used;
      queue<pair<int, int>> search;
      pair<int, int> start(i, j);
      vector<vector<int>> dis{
          {0,0,0,0},
          {0,0,0,0},
          {0,0,0,0},
          {0,0,0,0}
      };

      search.push(start);
      used.push_back(start);
      dis.at(i).at(j) = 0;

      
      while(search.size()>0)
      {
        int cur_i = search.front().first;
        int cur_j = search.front().second;
        int cur_step = dis.at(cur_i).at(cur_j);

        if (rooms.at(cur_i).at(cur_j)==-1)
        {
          return -1;
        }else if (rooms.at(cur_i).at(cur_j)==0){
          return dis.at(cur_i).at(cur_j);
        } else {
          for (int i_p = 0; i_p < direct.size(); i_p++)
          {
            int i_t = cur_i + direct.at(i_p).first;
            int j_t = cur_j + direct.at(i_p).second;
            pair<int, int> tempt(i_t, j_t);
            if (i_t >=0 && i_t<rows && j_t >=0 && j_t<cols and !vector_contain(used, tempt) and rooms.at(i_t).at(j_t)!=-1)
            {
              search.push(tempt);
              used.push_back(tempt);
              dis.at(i_t).at(j_t) = cur_step + 1;
            }
            
          }
        }
        search.pop();
      }
    }
};



void lc_wallsAndGates(Solution s){
  vector<vector<int>> rooms
  {
      {2147483647,-1,0,2147483647},
      {2147483647,2147483647,2147483647,-1},
      {2147483647,-1,2147483647,-1},
      {0,-1,2147483647,2147483647}
  };

  vector<vector<int>> results
  {
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0}
  };

  // print_vector_dim2(rooms);
  s.wallsAndGates(rooms, results);
  print_vector_dim2(results);
}

int main()
{
  Solution s;
  lc_wallsAndGates(s);
}
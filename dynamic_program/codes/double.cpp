#include <iostream>
#include <vector>
#include <string>

using namespace std;

int min_of_3(int src0, int src1, int src2){
  int min = src0;
  if (src1< min)
  {
    min = src1;
  }
  if (src2< min)
  {
    min = src2;
  }
  return min;
}

bool string0_has_char1(string string0, char char1)
{
  auto idx=string0.find(char1);
  if(idx == string::npos){
    return false;
  }else{
    return true;
  }
}

int longestCommonSubsequence(string text1, string text2, int i, int j) {
  int text1_l = text1.length();
  int text2_l = text2.length();

  if (i==0 && j==0)
  {
    if (text1[0]==text2[0])
    {
      return 1;
    }else{
      return 0;
    }
  } else if(i==0 && j>0){
    for(int k=0;k<j;k++){
      if (text2[k]==text1[0])
      {
        return 1;
      }
      return 0;
    }
  } else if(i>0 && j==0){
    for(int k=0;k<i;k++){
      if (text1[k]==text2[0])
      {
        return 1;
      }
      return 0;
    }
  } else {
    if (text1[i]==text2[j])
    {
      return longestCommonSubsequence(text1, text2, i-1, j-1) + 1;
    }else{
      int a = longestCommonSubsequence(text1, text2, i, j-1);
      int b = longestCommonSubsequence(text1, text2, i-1, j);
      if (a>b)
      {
        return a;
      }else{
        return b;
      }
    }
  }
}

int minDistance(string word1, string word2, int i, int j) {
  if (i==0 && j==0)
  {
    if(word1[i]==word2[j]){
      return 0;
    }else{
      return 1;
    }
  }else if (i==0 && j> 0){
    if (string0_has_char1(word2.substr(0, j+1), word1[0]))
    {
      return j;
    }else{
      return j+1;
    }
  }else if (i>0 && j==0){
    if (string0_has_char1(word1.substr(0, i+1), word2[0]))
    {
      return i;
    }else{
      return i+1;
    }
  }else{
    if (word1[i] == word2[j])
    {
      return minDistance(word1, word2, i-1, j-1);
    }else{
      int insert_v = minDistance(word1, word2, i-1, j) + 1;
      int delete_v = minDistance(word1, word2, i, j-1) + 1;
      int replace_v = minDistance(word1, word2, i-1, j-1) + 1;
      return min_of_3(insert_v, delete_v, replace_v);
    }
  }
}

void lc_longestCommonSubsequence()
{
  string a0 = "abcde";
  string b0 = "ace";
  cout<<longestCommonSubsequence(a0, b0, 4, 2)<<endl;

  a0 = "abc";
  b0 = "abc";
  cout<<longestCommonSubsequence(a0, b0, 2, 2)<<endl;

  a0 = "abc";
  b0 = "def";
  cout<<longestCommonSubsequence(a0, b0, 2, 2)<<endl;
}

void lc_minDistance()
{
  string word1 = "horse";
  string word2 = "ros";
  cout<<minDistance(word1, word2, 4, 2)<<endl;

  word1 = "intention";
  word2 = "execution";
  cout<<minDistance(word1, word2, 8, 8)<<endl;

}

void test_string0_has_char1()
{
  string word1 = "horse";
  string word2 = "rosj";
  cout<<string0_has_char1(word1.substr(0, 5), word2[0])<<endl;
  cout<<string0_has_char1(word1.substr(0, 5), word2[3])<<endl;

}

bool vector_contain_1dm(vector<int> src0, int src1, int src0_i){
  for (size_t i = 0; i<=src0_i; i++)
  {
    if (src0.at(i)==src1)
    {
      return true;
    }
  }
  return false;  
}

int _findLength(vector<int>& nums1, vector<int>& nums2, int i, int j) {
  if (i==0 || j==0)
  {
    if (nums1.at(i)==nums2.at(j))
    {
      return 1;
    }else{
      return 0;
    }
  }else{
    if (nums1.at(i)==nums2.at(j))
    {
      return _findLength(nums1, nums2, i-1, j-1) + 1;
    }else{
      return 0;
    }
  }
}

int findLength(vector<int>& nums1, vector<int>& nums2, int n, int m) {
  int max_l = 0;
  for (size_t i = 0; i <= n; i++)
  {
    for (size_t j = 0; j <= m; j++)
    {
      int cur_l = _findLength(nums1, nums2, i, j);
      if(cur_l>max_l){
        max_l = cur_l;
      }
    }
  }
  return max_l;
}

void lc_findLength()
{
  vector<int> nums1 {1,2,3,2,1};
  vector<int> nums2 {3,2,1,4,7};
  cout<<findLength(nums1, nums2, 4, 4)<<endl;

  vector<int> nums3 {0,0,0,0,0};
  vector<int> nums4 {0,0,0,0,0};
  cout<<findLength(nums3, nums4, 4, 4)<<endl;

  vector<int> nums5 {1,2,3,2,1};
  vector<int> nums6 {0,1,2,2,1};
  cout<<findLength(nums5, nums6, 4, 4)<<endl;

}

int main()
{
  // test_string0_has_char1();
  // lc_longestCommonSubsequence();
  // lc_minDistance();
  lc_findLength();
}
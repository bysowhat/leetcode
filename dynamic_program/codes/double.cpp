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

bool all_xing(string src, int start, int end){
  for (size_t i = start; i <= end; i++)
  {
    if(src[i]!='*'){
      return false;
    }
  }
  return true;
}

bool one_wenhao_others_xing(string src, int start, int end, char target)
{
  int num_wenhao = 0;
  int num_xing = 0;
  for (size_t i = start; i <= end; i++)
  {
    if (src[i]=='*')
    {
      num_xing++;
    }
    if (src[i]==target)
    {
      num_wenhao++;
    }
  }
  if (num_wenhao==1 && num_xing==end)
  {
    return true;
  }else{
    return false;
  }
  
}

bool isMatch(string s, string p, int i, int j) {

  if (i==0 && j==0)
  {
    if (s[i]==p[j] || p[j]=='?' || p[j]=='*')
    {
      return true;
    } else {
      return false;
    }
  } else if(i==0 && j>0){
    string tempt_p = p.substr(0, j+1);
    if (one_wenhao_others_xing(p, 0, j, s[0]))
    {
      return true;
    }else if (one_wenhao_others_xing(p, 0, j, '?'))
      {
        return true;
      }else{
        return false;
      }
  } else if(i>0 && j==0){
    if (p[j]=='*')
    {
      return true;
    }else{
      return false;
    }
    
  }else{
    if (p[j] != '*')
    {
      if (s[i] == p[j] || p[j] == '?')
      {
        return isMatch(s, p, i-1, j-1);
      }else{
        return false;
      }
    }else{
      bool a = isMatch(s, p, i, j-1);
      bool b = isMatch(s, p, i-1, j);
      return a || b;
    }
  }
}

void lc_isMatch()
{
  string s0 = "aa";
  string p0 = "a";
  cout<<isMatch(s0, p0, s0.size()-1, p0.size()-1)<<endl;

  string s1 = "aa";
  string p1 = "*";
  cout<<isMatch(s1, p1, s1.size()-1, p1.size()-1)<<endl;

  string s2 = "cb";
  string p2 = "?a";
  cout<<isMatch(s2, p2, s2.size()-1, p2.size()-1)<<endl;

  string s3 = "adceb";
  string p3 = "*a*b";
  cout<<isMatch(s3, p3, s3.size()-1, p3.size()-1)<<endl;

  string s4 = "acdcb";
  string p4 = "a*c?b";
  cout<<isMatch(s4, p4, s4.size()-1, p4.size()-1)<<endl;

}

int main()
{
  // test_string0_has_char1();
  // lc_longestCommonSubsequence();
  // lc_minDistance();
  // lc_findLength();
  lc_isMatch();
}
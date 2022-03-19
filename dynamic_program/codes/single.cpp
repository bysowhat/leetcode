#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int longest_greater_uncontinue_substr(vector<int>& src, int end, map<int, int>& history)
{
  if (end == 0)
  {
    return 1;
  } else {
    if (history.find(end)==history.end())
    {
      if (src.at(end) > src.at(end-1))
      {
        history[end] = longest_greater_uncontinue_substr(src, end-1, history) + 1;
        return history[end];
      } else {
        history[end] = longest_greater_uncontinue_substr(src, end-1, history);
        return history[end];
      }
    } else {
      return history[end];
    }
  }
};

void lc_longest_greater_uncontinue_substr()
{
  vector<int> str {10,9,2,5,3,7,101,18};
  map<int, int> history;
  cout<<longest_greater_uncontinue_substr(str, 7, history);
}

int max_3(int src0, int src1, int src2)
{
  int max=0;
  if (src0> src1)
  {
    max = src0;
  }else{
    max = src1;
  }
  if (max > src2)
  {
    return max;
  }else{
    return src2;
  }
  
  
}

int _largest_sum_continue_substr(vector<int>& src, int end)
{
  if (end==0)
  {
    return src.at(0);
  } else {
    return src.at(end) + max(_largest_sum_continue_substr(src, end-1), 0);
  }
}

int _largest_sum_continue_substr2(vector<int>& src, int end)
{
  if (end==0)
  {
    return src.at(0);
  } else {
    if (src.at(end)>0)
    {
      return _largest_sum_continue_substr(src, end-1) + src.at(end);
    }else{
      return _largest_sum_continue_substr(src, end-1);
    }
  }
}

int largest_sum_continue_substr(vector<int>& src, int end)
{
  int max_v = _largest_sum_continue_substr(src, 0);
  for (size_t i = 0; i < src.size(); i++)
  {
    int cur = _largest_sum_continue_substr(src, i);
    max_v = max(cur, max_v);
  }
  return max_v;
  
}

int largest_sum_continue_substr2(vector<int>& src, int end)
{
  int max_v = _largest_sum_continue_substr2(src, 0);
  for (size_t i = 0; i < src.size(); i++)
  {
    int cur = _largest_sum_continue_substr2(src, i);
    max_v = max(cur, max_v);
  }
  return max_v;
  
}

int num_longest_greater_uncontinue_substr(vector<int>& nums, int n)
{
  vector<int> l(n+1,1);
  vector<int> c(n+1,0);
  c.at(0)=1;


  for (size_t i = 1; i <= n; i++)
  {
    int max_l = 1;
    bool flag = false;
    for (size_t j = 0; j < i; j++)
    {
      if (nums[j]<nums[i])
      {
        if (l.at(j)>= max_l)
        {
          max_l = l.at(j);
          flag = true;
        }  
      }
    }
    if (flag)
    {
      l.at(i) = max_l + 1;
    }
    
    bool flag2 = false;
    for (size_t j = 0; j < i; j++)
    {
      if (nums[j]<nums[i] && (l.at(j)+1)==l.at(i))
      {
        c.at(i) += c.at(j);
        flag2=true;
      }
    }
    if (not flag2)
    {
      c.at(i)=1;
    }
    
  }

  int max_l = 0;
  for (size_t i = 1; i <= n; i++)
  {
    if (l.at(i)>max_l)
    {
      max_l = l.at(i);
    }
  }

  int total_num = 0;

  for (size_t i = 0; i <= n; i++)
  {
    if (l.at(i)==max_l)
    {
      total_num += c.at(i);
    }
  }

  return total_num;
}

int _maxProduct(vector<int>& nums, int n) {
  if (n==0)
  {
    return nums.at(0);
  }

  int pre_v = _maxProduct(nums, n-1);
  int v_n = nums.at(n);

  if (nums.at(n)*pre_v<0 || (pre_v==0 && v_n>0))
  {
    return v_n;
  }
  if (nums.at(n)*pre_v>0 || (pre_v==0 && v_n<0))
  {
    return pre_v*v_n;
  }
}

int maxProduct(vector<int>& nums, int n) {
  int max=_maxProduct(nums, 0);
  for (size_t i = 1; i < n; i++)
  {
    int v = _maxProduct(nums, i);
    if (v>max)
    {
      max = v;
    }
  }
  return max;  
}

void lc_maxProduct()
{
  vector<int> a0 {2,3,-2,4};
  cout<<maxProduct(a0, 3)<<endl;
  vector<int> a1 {-2,0,-1};
  cout<<maxProduct(a1, 2)<<endl;
}

void lc_largest_sum_continue_substr()
{
  vector<int> str0 {-2,1,-3,4,-1,2,1,-5,4};
  map<int, int> history;
  cout<<largest_sum_continue_substr(str0, str0.size()-1)<<endl;
  cout<<largest_sum_continue_substr2(str0, str0.size()-1)<<endl;

  vector<int> str1 {5,4,-1,7,8};
  cout<<largest_sum_continue_substr(str1, str1.size()-1)<<endl;
  cout<<largest_sum_continue_substr2(str1, str1.size()-1)<<endl;
}

void lc_num_longest_greater_uncontinue_substr(){
  vector<int> str0 {1,3,5,4,7};
  cout<<num_longest_greater_uncontinue_substr(str0, 4)<<endl;

  vector<int> str1 {2,2,2,2,2};
  cout<<num_longest_greater_uncontinue_substr(str1, 4)<<endl;

  vector<int> str2 {9,8,2,3,2};
  cout<<num_longest_greater_uncontinue_substr(str2, 4)<<endl;

}

int main()
{
  // lc_longest_greater_uncontinue_substr();
  // lc_largest_sum_continue_substr();
  // lc_num_longest_greater_uncontinue_substr();
  lc_maxProduct();

}
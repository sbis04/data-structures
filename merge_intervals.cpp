#include<iostream>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
  sort(intervals.begin(), intervals.end());
  vector<vector<int>> ans;
  int n = intervals.size();
  int end_idx = -1;
  for (int i = 0; i < n; i++)
  {
    if (intervals[i][0] > end_idx)
    {
      ans.push_back(intervals[i]);
    }
    else
    {
      ans[ans.size() - 1][1] = max(end_idx, intervals[i][1]);
    }
    end_idx = max(end_idx, intervals[i][1]);
  }
  return ans;
}
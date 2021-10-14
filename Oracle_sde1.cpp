Problem: Given mutiple meetings which happen within a day. Return all the time brackets of no meetings.
input given in sorted order;
Input: [(2, 6), (2, 3) (8, 10), (15, 18)]
Output: [(1, 2), (6, 8), (10, 15), (18, 24)]

// Note if the array is not sorted then add sort(vect.begin(), vect.end()); it will sort the vector of pair on the basis of starting time;
#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin >> n;
 vector<pair<int, int>> v;
 for (int i = 0; i < n; i++)
 {
  int a, b;
  cin >> a >> b;
  v.push_back(make_pair(a, b));
 }
 vector<pair<int, int>> ans;
 if (v[0].first > 1)
 {
  ans.push_back(make_pair(1, v[0].first));
 }
 for (int i = 0; i < n - 1; i++)
 {
  if (v[i].second < v[i + 1].first)
  {
   ans.push_back(make_pair(v[i].second, v[i + 1].first));
  }
  else
  {
   v[i + 1].second = max(v[i].second, v[i + 1].second);
  }
 }
 if (v[n - 1].second < 24)
 {
  ans.push_back(make_pair(v[n - 1].second, 24));
 }

 for (auto e : ans)
 {
  cout << e.first << " " << e.second << "\n";
 }
 return 0;
}

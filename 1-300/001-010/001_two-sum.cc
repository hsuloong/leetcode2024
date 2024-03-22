#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/two-sum/

/*
 * 最暴力的做法：两层for循环 O(n^2) 48ms
 */
vector<int> twoSum1(vector<int>& nums, int target) {
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] + nums[j] == target) {
        return {i, j};
      }
    }
  }
  return {};
}

/*
 * 引入 std::unordered_map 理论上O(n)  11ms
 */
vector<int> twoSum2(vector<int>& nums, int target) {
  std::unordered_map<int, int> hash_map;
  for (int i = 0; i < nums.size(); i++) {
    hash_map[nums[i]] = i;
  }
  for (int i = 0; i < nums.size(); i++) {
    int other = target - nums[i];
    if (hash_map.count(other) > 0 && hash_map.at(other) != i) {
      return {i, hash_map.at(other)};
    }
  }

  return {};
}

/*
 * 先排序，然后头尾双指针 理论上O(nlgn) 5ms
 */
vector<int> twoSum3(vector<int>& nums, int target) {
  std::vector<std::pair<int, int>> new_vec;
  for (int i = 0; i < nums.size(); i++) {
    new_vec.push_back(std::make_pair(nums[i], i));
  }
  std::sort(new_vec.begin(), new_vec.end(),
            [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) { return lhs.first < rhs.first; });
  for (int i = 0, j = new_vec.size() - 1; i != j;) {
    int sum = new_vec[i].first + new_vec[j].first;
    if (sum == target) {
      return {new_vec[i].second, new_vec[j].second};
    } else if (sum < target) {
      ++i;
    } else {
      --j;
    }
  }
  return {};
}

int main() {
  vector<int> nums = {2, 7, 11, 15};
  twoSum1(nums, 9);
  twoSum2(nums, 9);
  twoSum3(nums, 9);
  return 0;
}

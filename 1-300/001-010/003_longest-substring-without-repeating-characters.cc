#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/*
 * 最长无重复字符字串，假设dp[i] = 以s[i]结尾的最长子串 14ms
 */
int lengthOfLongestSubstring1(string s) {
  if (s.size() <= 1) {
    return s.size();
  }
  std::unordered_map<char, int> um;
  std::vector<int> dp(s.size(), -1);
  dp[0] = 1;
  um[s[0]] = 0;
  int left = 0;
  for (int i = 1; i < s.size(); i++) {
    if (um.count(s[i]) > 0 && um[s[i]] >= left) {
      dp[i] = i - um[s[i]];
      left = um[s[i]];
    } else {
      dp[i] = dp[i - 1] + 1;
    }
    um[s[i]] = i;
  }
  int max_r = 0;
  for (int i = 0; i < dp.size(); i++) {
    max_r = std::max(max_r, dp[i]);
  }
  return max_r;
}

/*
 * 不使用dp数组，用一个值记录出现的最大值 18ms
 */

int lengthOfLongestSubstring2(string s) {
  std::unordered_map<char, int> um;
  int max_length = 0;
  int left = 0;
  for (int i = 0; i < s.size(); i++) {
    if (um.count(s[i]) > 0 && um[s[i]] >= left) {
      max_length = std::max(max_length, i - um[s[i]]);
      left = um[s[i]] + 1;
    } else {
      max_length = std::max(max_length, i - left + 1);
    }
    um[s[i]] = i;
  }

  return max_length;
}

int main() {
  lengthOfLongestSubstring1("abcabcbb");
  lengthOfLongestSubstring1("au");
  lengthOfLongestSubstring1("abba");

  lengthOfLongestSubstring2("abcabcbb");
  lengthOfLongestSubstring2("au");
  lengthOfLongestSubstring2("abba");
}
#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/string-to-integer-atoi/description/

/*
 * 主要注意溢出以及正负号
 */
int myAtoi1(string s) {
  int i = 0;
  while (i < s.size()) {
    if (s[i] == ' ') {
      ++i;
      continue;
    }
    break;
  }
  if (i >= s.size()) {
    return 0;
  }
  int flag = 1;
  if (s[i] == '+' || s[i] == '-') {
    if (s[i] == '-') {
      flag = -1;
    }
    ++i;
  }
  constexpr int kMin = std::numeric_limits<int>::min();  // -2,147,483,648
  constexpr int kMax = std::numeric_limits<int>::max();  // 2,147,483,647
  int x = 0;
  while (i < s.size()) {
    if ('0' <= s[i] && s[i] <= '9') {
      int carry = (s[i] - '0') * flag;
      if (x > kMax / 10 || (x == kMax / 10 && carry > 7)) {
        return kMax;
      }

      if (x < kMin / 10 || (x == kMin / 10 && carry < -8)) {
        return kMin;
      }
      x = x * 10 + carry;
      ++i;
      continue;
    }
    break;
  }
  return x;
}

/*
 * 自动机 3ms
 */
int myAtoi2(string s) {
  // 0 start 1 signed 2 number 3 end
  // ' ' +/- nmber other
  constexpr int kStart = 0;
  constexpr int kSigned = 1;
  constexpr int kNumber = 2;
  constexpr int kEnd = 3;
  int state_table[4][4] = {{0, 1, 2, 3}, {3, 3, 2, 3}, {3, 3, 2, 3}, {3, 3, 3, 3}};
  constexpr int kMin = std::numeric_limits<int>::min();  // -2,147,483,648
  constexpr int kMax = std::numeric_limits<int>::max();  // 2,147,483,647
  int state = kStart;
  int x = 0;
  int flag = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      state = state_table[state][0];
    } else if (s[i] == '+' || s[i] == '-') {
      state = state_table[state][1];
      flag = (s[i] == '-' ? -1 : flag);
    } else if ('0' <= s[i] && s[i] <= '9') {
      state = state_table[state][2];
      int carry = (s[i] - '0') * flag;
      if (x > kMax / 10 || (x == kMax / 10 && carry > 7)) {
        x = kMax;
      } else if (x < kMin / 10 || (x == kMin / 10 && carry < -8)) {
        x = kMin;
      } else {
        x = x * 10 + carry;
      }
    } else {
      state = state_table[state][3];
    }
    if (state == kEnd) {
      break;
    }
  }

  return x;
}

int main() {
  myAtoi1("123");

  myAtoi2("321");

  return 0;
}

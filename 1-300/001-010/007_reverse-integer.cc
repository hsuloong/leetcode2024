#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/reverse-integer/

/*
 * 用更大的数值去做计算 0ms
 */
int reverse1(int x) {
  int64_t x0 = x;
  x0 = x0 > 0 ? x0 : -x0;

  int64_t y = 0;

  while (x0 > 0) {
    y = y * 10 + x0 % 10;
    x0 = x0 / 10;
  }

  int64_t y0 = (x > 0 ? y : -y);

  if (y0 < std::numeric_limits<int>::min() || y0 > std::numeric_limits<int>::max()) {
    return 0;
  }

  return y0;
}

/*
 * 字符串中间转换 5ms
 */
int reverse2(int x) {
  std::string s = std::to_string(x);
  if (s.size() > 0 && s[0] == '-') {
    std::reverse(s.begin() + 1, s.end());
  } else {
    std::reverse(s.begin(), s.end());
  }

  int64_t y0 = std::stoll(s);

  if (y0 < std::numeric_limits<int>::min() || y0 > std::numeric_limits<int>::max()) {
    return 0;
  }

  return y0;
}

/*
 * 不使用更大数值或者字符串 5ms
 */
int reverse3(int x) {
  constexpr int kMin = std::numeric_limits<int>::min();
  constexpr int kMax = std::numeric_limits<int>::max();

  int r = 0;
  while (x != 0) {
    if (r > kMax / 10 || r < kMin / 10) {
      return 0;
    }
    r = r * 10 + x % 10;
    x = x / 10;
  }
  return r;
}

int main() {
  std::cout << reverse1(123456789) << "\n";
  std::cout << reverse1(100) << "\n";
  std::cout << reverse2(001) << "\n";
  std::cout << reverse2(-123) << "\n";
  std::cout << reverse3(-123) << "\n";
  return 0;
}

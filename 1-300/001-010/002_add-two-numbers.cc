#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/add-two-numbers/description/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
 * 由于按照逆序存储，因此只要简单模拟手算进位，主要是注意链表操作 11ms O(max_length(l1,l2))
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode head;
  int carry = 0;
  ListNode* cur = &head;
  while (l1 != nullptr || l2 != nullptr) {
    int sum = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + carry;
    auto node = new ListNode(sum % 10);
    carry = sum / 10;
    cur->next = node;
    cur = cur->next;
    if (l1 != nullptr) {
      l1 = l1->next;
    }
    if (l2 != nullptr) {
      l2 = l2->next;
    }
  }

  if (carry > 0) {
    auto node = new ListNode(carry % 10);
    cur->next = node;
  }

  return head.next;
};

int main() {
  addTwoNumbers(nullptr, nullptr);
  return 0;
}
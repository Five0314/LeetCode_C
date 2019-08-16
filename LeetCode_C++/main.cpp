//
//  main.cpp
//  LeetCode_C++
//
//  Created by 董伍 on 2019/4/30.
//  Copyright © 2019 董伍. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// 无重复字符的最长子串
long _3_lengthOfLongestSubstring(string str){
    long c = str.length();
    
    if (c <= 1) {
        return c;
    }
    
    long maxLength = 1;
    
    long l = 0;
    long r = 1;
    
    while (r < c) {
        
        char nv = str[r];
        for (long i = l; i < r; i++) {
            if (str[i] == nv){
                l = i + 1;
                break;
            }
        }
        
        maxLength = max(maxLength, r - l + 1);
        
        r++;
    }
    
    return maxLength;
}

/// 字符串转换整数 (atoi)
long _8_myAtoi(string str) {
    long n = str.length();
    
    long flag = 0;
    long ans = 0;
    
    for(int i = 0 ; i < n ; i ++){
        char cv = str[i];
        
        if (flag == 0) {
            if (cv == ' '){ continue; }
            else if (cv == '+'){ flag = 1; }
            else if (cv == '-'){ flag = -1; }
            else if (cv >= '0' && cv <= '9'){
                ans = cv - '0';
                flag = 1;
            }
            else { break; }
        }
        else{
            if (cv >= '0' && cv <= '9'){
                ans = ans * 10 + (cv - '0');
                
                if(ans * flag < INT_MIN) return INT_MIN;
                if(ans * flag > INT_MAX) return INT_MAX;
            }
            else{ break; }
        }
    }
    
    return ans * flag;
}

/// 盛最多水的容器
long _11_maxArea(vector<int>& height) {
    long l = 0;
    long r = height.size() - 1;
    
    long maxVolume = 0;
    
    while (l < r){
        maxVolume = max(maxVolume, min(height[l], height[r]) * (r - l));
        
        if (height[l] < height[r]){
            l++;
        }
        else{
            r--;
        }
    }
    
    return maxVolume;
}

bool _20_1_(stack<char>& myStack, char c){
    if (myStack.empty()) {
        return false;
    }
    
    if (myStack.top() != c) {
        return false;
    }
    
    myStack.pop();
    return true;
}

/// 有效的括号
bool _20_isValid(string s) {
    stack<char> myStack;
    
    int c = int(s.length());
    
    for (int i = 0; i < c; i++) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{':
                myStack.push(s[i]);
                break;
                
            case ')':
                if (!_20_1_(myStack, '(')){
                    return false;
                }
                break;
                
            case '}':
                if (!_20_1_(myStack, '{')){
                    return false;
                }
                break;
                
            case ']':
                if (!_20_1_(myStack, '[')){
                    return false;
                }
                break;
                
            default:
                break;
        }
    }
    
    return myStack.empty();
}

/// 删除排序数组中的重复项
int _26_removeDuplicates(vector<int>& nums) {
    int c = int(nums.size());
    if (c == 0) {
        return 0;
    }
    
    int n = 0;
    
    for (int i = 0; i < c; i++) {
        if (nums[n] != nums[i]) {
            n++;
            nums[n] = nums[i];
        }
    }
    
    return n + 1;
}

/// 移除元素
int _27_removeElement(vector<int>& nums, int val) {
    int r = int(nums.size() - 1);
    
    int curosr = 0;
    
    for (int i = 0; i <= r; i++) {
        if (nums[i] != val) {
            nums[curosr] = nums[i];
            curosr++;
        }
    }
    
    return curosr;
}

/// 颠倒二进制位
uint32_t _190_reverseBits(uint32_t n) {
    uint32_t rv = 0;
    for (int i = 0; i < 32; i++) {
        rv <<= 1;
        if (n >> i & 1) rv += 1;
    }
    
    return rv;
    
}

/// 位1的个数
uint32_t _191_hammingWeight(uint32_t n) {
    
    int c = 0;
    while (n) {
        if (n & 1) c += 1;
        n >>= 1;
    }
    return c;
}

/// 第一个错误的版本
bool isBadVersion(int version){
    return version >= 2126753289;
}
int _278_firstBadVersion(int n) {
    int l = 1, r = n, m = 0;
    
    while (l < r) {
        m = l + (r - l) / 2;
        
        if (isBadVersion(m)){
            r = m;
        }
        else{
            l = m + 1;
        }
    }
    
    return l;
}

int maxSubArray(vector<int>& nums) {
    
    vector<int>::iterator it  = nums.begin();
    int maxSum = *it;
    int theSum = *it;
    
    for(it = it+1 ; it != nums.end(); it++){
        theSum = max(theSum + *it, *it);
        
        if(theSum > maxSum)
            maxSum = theSum;
    }
    
    return maxSum;
}

/// 环形链表
bool _141(ListNode *head) {
    ListNode *f = head;
    ListNode *s = head;
    
    while (f && f->next) {
        f = f->next->next;
        s = s->next;
        
        if (f == s)  return true;
    };
    
    return false;
}

/// 环形链表
ListNode * _142(ListNode *head) {
    ListNode *f = head;
    ListNode *s = head;
    
    while (f && f->next) {
        f = f->next->next;
        s = s->next;
        
        if (f == s) { // 存在环
            f = head;
            
            while (f != s) {
                f = f->next;
                s = s->next;
            }
            
            return f;
        }
    };
    
    return NULL;
}

//Line 10: Char 20: runtime error: signed integer overflow: 1063376694 + 2126753389 cannot be represented in type 'int' (solution.cpp)
int main(int argc, const char * argv[]) {
//    vector<int> p = vector<int>(4, 0);
//    p[0] = -1;
//    p[1] = 1;
//    p[2] = 2;
//    p[3] = 3;
    
//    p[0] = 0;
//    p[1] = 1;
//    p[2] = 2;
//    p[3] = 2;
//    p[4] = 3;
//    p[5] = 0;
//    p[6] = 4;
//    p[7] = 2;
    
    cout << _190_reverseBits(4294967293);
    
    cout << "   " ;
    
    return 0;
}



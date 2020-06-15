---
title: 28-实现 strStr()
date: 2019-12-12 19:26:47
comments: true #是否可评论
toc: true #是否显示文章目录
categories: 
    - LeetCode(C++) #分类
tags:   #标签
    - two-pointers
    - string
---

# 28-实现 strStr()

> @Author：CSU张扬  
> @Email：csuzhangyang@gmail.com or csuzhangyang@qq.com

Category   | Difficulty | Pass rate| Tags   | Companies
:-:        | :-:        | :-:      | :-:    | :-: |
algorithms | Easy       | 39.04%   | two-pointers / string  | apple / facebook / microsoft / pocketgems

## 1. 题目

实现 **`strStr()`** 函数。

给定一个 `haystack` 字符串和一个 `needle` 字符串，在 `haystack` 字符串中找出 `needle` 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  **-1**。

```cpp
示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1
```

**说明:**
当 `needle` 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 `needle` 是空字符串时我们应当返回 `0` 。这与C语言的 `strstr()` 以及 Java的 `indexOf()` 定义相符。
<!--more-->
来源：力扣（LeetCode）  
链接：[https://leetcode-cn.com/problems/implement-strstr/](https://leetcode-cn.com/problems/implement-strstr/)

## 2. 解法

### 2.1 解法一

> 执行用时: 1600 ms, 在所有 cpp 提交中击败了11.46%的用户  
> 内存消耗: 8.9 MB, 在所有 cpp 提交中击败了92.89%的用户

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        const int m = needle.size();
        const int n = haystack.size();
        int i = 0;
        do {
            int j = 0;
            for (j; j < m; ++ j) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == m)
                return i;
            i ++;
        } while (i < n);
        return -1;
    }
};
```
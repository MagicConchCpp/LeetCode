---
title: 8-字符串转换整数 (atoi)
date: 2019-10-24 09:08:20
comments: true #是否可评论
toc: true #是否显示文章目录
categories: 
    - LeetCode(C++) #分类
tags:   #标签
    - math
    - string
---

# 8-字符串转换整数 (atoi)

> @Author：CSU张扬  
> @Email：csuzhangyang@gmail.com or csuzhangyang@qq.com

Category   | Difficulty | Pass rate| Tags   | Companies
:-:        | :-:        | :-:      | :-:    | :-: |
algorithms | Medium     | 18.57%   | math / string | amazon / bloomberg / microsoft / uber

## 1. 题目

请你来实现一个`atoi`函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：  
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−2^31,  2^31 − 1]。如果数值超过这个范围，请返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31) 。

```c
示例 1:
输入: "42"
输出: 42

示例 2:
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。

示例 3:
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。

示例 4:
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。

示例 5:
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
     因此返回 INT_MIN (−231) 。
```
<!--more-->
来源：力扣（LeetCode）  
链接：[https://leetcode-cn.com/problems/string-to-integer-atoi](https://leetcode-cn.com/problems/string-to-integer-atoi)

## 2. 解法

### 2.1 解法一

1. 先找出第一个非空字符的下标 `noSpaceIndex`
2. 判断正负性 `negative`，找出数字开始的下标 `startIndex`
3. 计算出当前下标的数字 `curDigit`，判断是否溢出
4. horner法则求出和。

**需要注意的是溢出的处理办法：**  
`if (res > INT_MAX/10 || (res >= INT_MAX/10 && curDigit > 7))`

1. 首先我们知道 `INT_MAX = 2^31 - 1 = 2147483647，INT_MIN = -2^31 = -2147483648;`，`res`是结果的绝对值。  
2. 我们要理解为什么正负溢出对的处理方式相同。  
举四个例子即可：2147483647，2147483648，-2147483647，-2147483648。
其中只有 `2147483648` 和 `-2147483648` 会判断成溢出，实际上 `-2147483648` 是没有溢出的，但是我们最终得到的结果都是`INT_MIN = -2147483648`，所以并无大碍。

> 执行用时 :4 ms, 在所有 cpp 提交中击败了93.61%的用户  
> 内存消耗 :8.3 MB, 在所有 cpp 提交中击败了93.80%的用户

```cpp
class Solution {
public:
    int myAtoi(string str) {
        bool negative = false;
        int startIndex = 0;
        int res = 0;
        int curDigit = 0;
        while (str[startIndex] == ' ')
            startIndex ++;
        if (str[startIndex] == '-') {
            negative = true;
            startIndex ++;
        }
        else if (str[startIndex] == '+') {
            startIndex ++;
        }
        for (auto i = startIndex;i < str.size() && isdigit(str[i]); ++ i) {
            curDigit = str[i] - '0';
            if (res > INT_MAX/10 || (res >= INT_MAX/10 && curDigit > 7))
                return (negative ? INT_MIN : INT_MAX);
            res = res * 10 + curDigit;
            // res = res * 10 - 48 + static_cast<int>(str[i]);
        }
        return (negative ? -res : res);
    }
};
```

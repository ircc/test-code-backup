﻿给定一串数字 
判断是否存在这三个元素，它们将数字串分为四个子串，其中每个子串的数字之和均相同(该3个元素不纳入计算) 

要求时间复杂度和空间复杂度均不能超过O(n)

思路：
奇妙的利用了单调性，枚举第一段的和， 第一段的和确定了，那么接下来的2，3，4段的和就都确定了，什么单调性呢？ 就是i右移，j，k都要右移。这就是单调性了，第一段变大，那么234段都要变大，所以i，j，k，都只会往右移，如果有正有负就没有单调性了。。。
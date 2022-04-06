# My-Leetcode-Note

## 【数组】-简单- ---easy---

#### 题1_1 【两数之和】
使用```哈希表```，n次循环，每次从哈希表查找target-nums[index0]的数据下标，如没有，则插入当前数据，然后下一次循环：复杂度O(n)

#### 题2_53 【最大和的子数组】
```动态规划``` 遍历数组，对于每一个元素，找出以它结尾的最大子数组，从第一个元素递推，后一个元素的最大子数组于前一个元素最大子数组有关

#### 题3_121 【数组中最大元素差 股票买入卖出问题】
```动态规划``` 遍历数组，并递推记录当前元素前所有元素中最小的元素，更新最大的差值即可

#### 题4_136 【数组中成单的元素查找】
```哈希表 || 异或``` 使用哈希表减小复杂度或者使用异或特性

#### 题5_169 【数组中的多数元素】
```对拼消耗法``` 对于数组中最多的元素，遍历，相同元素加1，不同减1，最后剩下的为多数元素，若计数为0，则更新多数元素

#### 题6_283 【数组中的多数元素】
```双数组法 || 遍历替换法``` 数组双索引，一个索引用于遍历，另一个索引用于存储，对于非零元素依次存储，其它元素赋值0 || 依次遍历，零替换第一个非零元素，然后进入下一次循环

#### 题7_448 【消失的元素(未出现)】
```消数法``` 遍历数组，以元素值为索引，置负该索引处元素，说明以这个索引为值的元素出现，最后找出为正的元素的索引即为未出现元素

## 【数组】-中等- ---Medium---

#### 题8_11 【最大的盛水面积】
```双指针贪心合拢``` 指针: 数组第一和最后一个元素, 选择高度小的元素向内合拢

#### 题9_15 【三数之和】
```双指针合拢``` a<b<c, 选定a，b=a+1, c=size-1, b遍历增大， 则c需要减小，直到b==c

#### 题10_31 【下一个排列】
```双指针二分法``` 指针j < i, j要最大即在最右边，i选择j元素右边的最小值，交换ij元素，j指标后快速排序

#### 题11_33 【搜索旋转排序数组】
```二分法``` 1. 一分为2，若在有序数组则直接二分，若在无需数组将无序数组再次一分为2; 或者先找出旋转的下标，分两段数组二分

#### 题12_34 【在数组中的起始和结束位置】
```二分法``` 用二分法分别找起始位置和结束位置

#### 题13_39 【组合之和】
```树DFS回溯```
![image](https://github.com/ShieldQiQi/My-Leetcode-Note/blob/main/image/13_39_1.png)
![image](https://github.com/ShieldQiQi/My-Leetcode-Note/blob/main/image/13_39_2.png)

#### 题14_46 【全排列】
```树回溯``` 使用循环队列或者数组元素交换确定下一个可选取元素

#### 题15_48 【旋转图像】
```转置后镜像 || 坐标旋转递推``` 从内到外一层层旋转

#### 题16_55 【跳跃游戏】
```贪心算法``` index+1~index+nums[index]内找到下一个能到达最远的下标

#### 题17_56 【合并区间】
```快排递推``` 左边元素排序，然后递推

#### 题18_64 【最小路径和】
```动态规划``` 遍历网格，该网格保存路径和，更新加上左边或上边较小的数

#### 题19_75 【颜色分类】
```三指针``` 向中间合拢

#### 题20_78 【子集】
```DFS迭代``` 展开成一棵树，深度优先遍历，剪枝

#### 题21_79 【单词搜索】
```DFS回溯``` 注意不能出现重复位置的元素

#### 题22_105 【前序中序重建二叉树】
```哈希表 DFS 前序遍历``` 将前序分为根节点，左子树(长度由中序中根节点下标决定)，右子树，迭代

#### 题23_128 【最长连续序列】
```哈希表去重 O(n)遍历``` 只有当一个数是连续序列的第一个数的情况下才会进入内层循环->往后查找下一个连续数，保证同一个数只会进入一次循环

#### 题24_152 【最大乘积的连续子数组】
```O(n)``` 0将数组分区，每个区域记录最后一个和第一个负数

#### 题25_198 【打家劫舍】
```动态规划``` nums[i] = max{ nums[i]+nums[i-2], nums[i-1] }

#### 题26_200 【岛屿数量】
```DFS || 并查集``` 访问过的标记为'0'

#### 题27_215 【第K个最大元素】
```快排分治 || 堆排序``` 快排中找出下标为numsSize-K的元素即可停止排序

#### 题28_281 【最大正方形】
```动态规划``` matrix[i][j] = 1 + min{ matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j] }

#### 题29_238 【除自身以外数组乘积】
```前缀和``` 每个元素保存其及其之前的元素乘积， 保存其及其之后的乘积

#### 题30_240 【搜索二维矩阵Ⅱ】
```分治 || 二分``` 横向纵向循环二分 或者从右上角开始一层层拨开，小了往左移， 大了往下移 -> 最优

#### 题31_253 【会议室Ⅱ】
```快排上下车问题``` 记录在车上的人数的最大值

#### 题32_287 【寻找重复数】
```快慢指针``` 或者二分

#### 题33_300 【最长递增子序列】
```贪心二分 || 动态规划``` 遍历数组，定义一个数组New，如当前数组元素大于该数组New最后元素，则长度++，否则替换大于该元素的第一个New数组元素，因为替换的相比于原来更小

#### 题34_309 【股票最佳买卖时机含冷冻期】
```动态规划``` 三个维度，持有，非持有冷冻期(卖出当天)，非持有非冷冻期

#### 题35_322 【零钱兑换】
```动态规划``` dp[i] = min{dp[i-c_j]} + 1 其中c_j为所有面额中的一个 dp[i]表示面额i所需要的最小零钱数

#### 题36_347 【前K个高频元素】
```哈希 & 快排分治``` 使用哈希统计各个元素出现频率， 然后排序

#### 题37_399 【除法求值】
```DFS哈希 & 查并集``` a/c == a/b * b/c dfs剪枝

#### 题38_406 【根据身高重建队列】
```排序 & 贪心 & 链表``` 按后一位排序，对每一个后一位相同的类，根据第一位排序，依次插入链表

#### 题39_416 【分割等和子集】
```背包问题 动态规划``` dp[i][j] 表示0-i下标中可以可以凑够和j，优化，可以将dp降为一维

#### 题40_494 【目标和】
```背包问题 动态规划``` dp[i][j] = (j-nums[i]>=-sum?dp[i-1][abs(j-nums[i])]:0) + (j+nums[i]<=sum?dp[i-1][j+nums[i]]:0);

#### 题41_560 【和为 K 的子数组】
```哈希表 前缀和``` k = sum(0,j) - sum(0,i), 查找是否存在相应的sum(0,i);

#### 题42_581 【最短无序连续子数组】
```双指针求左右边界 || 快排``` 左右遍历，更新nums[i]<max 的最右边界； 右左遍历...

#### 题43_621 【任务调度器】
```桶计算频率 贪心``` fmax((maxExec - 1) * (n + 1) + maxCount, tasksSize)

#### 题44_739 【每日温度】
```单调栈``` 单调递减栈， 栈顶最小，新元素大于栈顶则弹栈，否则入栈

## 【链表】-简单- ---easy---

#### 题45_21 【合并两个有序链表】
```O(m+n)遍历``` 无需申请额外空间

#### 题46_141 【环形链表】
```快慢指针``` fast = fast->next->next; slow = slow->next;

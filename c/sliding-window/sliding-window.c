/*
 *
 *
在这个例子中，我们有一个整数数组`nums`和一个整数`k`。我们想找到`nums`中和至少为`k`的最小子数组长度。这个问题可以用滑动窗口算法解决。

我们使用两个指针`start`和`end`表示窗口的起始和结束位置。我们不断地向右移动`end`指针来扩大窗口，直到窗口内的元素和大于等于`k`。
然后，我们开始移动`start`指针来缩小窗口，直到窗口内的元素和小于`k`。每次我们找到一个合适的窗口时，我们就更新最小长度。

如果在整个过程中都没有找到一个和至少为`k`的子数组，我们就返回`0`。如果找到了，我们就返回最小长度。

请注意，这个例子假设数组中的数字都是正数。如果数组中有负数，算法将需要进行修改，因为负数的加入可能会使和减小。
 *
 *
 */


#include <stdio.h>

// 返回和至少为 k 的最小子数组长度
int minSubArrayLen(int k, int* nums, int numsSize) {
    int start = 0, end = 0; // 定义滑动窗口的起始和结束位置
    int sum = 0; // 窗口内数字的总和
    int minLength = numsSize + 1; // 初始化为最大长度+1，用于比较

    while (end < numsSize) {
        // 扩大窗口，直到窗口内的和大于等于k
        sum += nums[end++];

        // 当窗口内的和大于等于k时，缩小窗口，直到窗口内的和小于k
        while (sum >= k) {
            int currentLength = end - start; // 当前窗口的长度
            if (currentLength < minLength) { // 更新最小长度
                minLength = currentLength;
            }
            sum -= nums[start++]; // 缩小窗口
        }
    }

    // 如果minLength没有被更新过，说明没有满足条件的子数组
    return minLength == numsSize + 1 ? 0 : minLength;
}

int main() {
    int nums[] = {2, 3, 1, 2, 4, 3};
    int k = 7;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Minimum size subarray length is: %d\n", minSubArrayLen(k, nums, numsSize));
    return 0;
}






//lower_bound 是 C++ 标准库中用于在有序序列中快速查找第一个大于等于目标值的元素的函数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 必须是升序有序序列！
    vector<int> nums = {1, 3, 5, 7, 9};
    
    // 情况1：目标值存在
    int target1 = 5;
    auto it1 = lower_bound(nums.begin(), nums.end(), target1);
    cout << "目标值5的位置：" << it1 - nums.begin() << endl; // 输出：2
    
    // 情况2：目标值不存在，找第一个更大的
    int target2 = 6;
    auto it2 = lower_bound(nums.begin(), nums.end(), target2);
    cout << "目标值6的插入位置：" << it2 - nums.begin() << endl; // 输出：3（7的位置）
    
    // 情况3：目标值小于所有元素
    int target3 = 0;
    auto it3 = lower_bound(nums.begin(), nums.end(), target3);
    cout << "目标值0的插入位置：" << it3 - nums.begin() << endl; // 输出：0
    
    // 情况4：目标值大于所有元素
    int target4 = 10;
    auto it4 = lower_bound(nums.begin(), nums.end(), target4);
    cout << "目标值10的插入位置：" << it4 - nums.begin() << endl; // 输出：5（尾后位置）
    return 0;
}
//如果是第一个大于的位置 upper_bound
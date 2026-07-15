#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
//做法一： 两个数组的长度已知 所以中位数的下标也知道 维护两个指针 小的移动
//直到两个指针下标和达到要求
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n  = nums1.size();
        int m  = nums2.size();
        int i1  =0;
        int i2 = 0;
        int len = m+n;
        //left 要来保存前一个数 处理长度偶数的情况
        int left = 0;
        int right = 0;
        //无论长度是奇数还是偶数 指针总共都要走len/2+1步
        for(int i = 0;i<=len/2;i++){
            //先把上一次循环的right给left
            left = right;
            if(i1<n&&(i2>=m||nums1[i1]<nums2[i2])){
                //要先赋值再加加 避免越界
                right =nums1[i1];
                i1++;
                
            }
            else{
                right = nums2[i2];
                i2++;
                
            }
        }
        if(len%2==0){
            return (left+right)/2.0;
        }
        else{
            return right;
        }
    }
};

//二分查找
/*中位数的本质是什么？它是把一个集合划分成长度相等的两个部分，
并且左半部分的最大值 <= 右半部分的最小值。
假设我们在 nums1 和 nums2 中各砍一刀，
它们都分成左右两半：nums1 左半边 + nums2 左半边 = 总左半边 nums1 右半边 + nums2 右半边 = 总右半边
我们只需要满足两个条件，这一刀就是完美的：
长度相等：总左半边的元素个数，等于总右半边的元素个数（如果是奇数，让左边多 1 个）。
交叉小于等于：nums1 左边最大值 <= nums2 右边最小值，
且 nums2 左边最大值 <= nums1 右边最小值。*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m  = nums1.size();
        int n  = nums2.size();
        if(m>n){
            //保证num1永远是短的那个  这样i就不会太大 防止后面totallen-i=j j变为负数
            return findMedianSortedArrays(nums2, nums1);
        }
        //totallen表示切到左半边的个数 奇数的话就多一个
        int totallen = (m+n+1)/2;
        int left  =0;
        int right = m;
        while(left<=right){
            //i表示第一段我们要切到左半边的个数
            int i  = left + (right-left)/2;
            //j就表示第二段要去的
            int  j = totallen - i;
            //要i个下标取到i-1即可 如果i=0 那么直接给个极小值 便于后面判断交叉小于等于
            //num1max 表示第一段中被切到左半部分的最大值 其他同理
            int num1max = (i==0)?INT_MIN:nums1[i-1];
            int num1min = (i==m)?INT_MAX:nums1[i];
            int num2max = (j==0)?INT_MIN:nums2[j-1];
            int num2min = (j==n)?INT_MAX:nums2[j];
            //满足交叉小于等于
            if(num1max <= num2min&&num2max<=num1min){
                if((m+n)%2==1){
                    //奇数的话放回左半边最大值即可
                    return max(num1max,num2max);
                }
                else{
                    //返回左半边最大值和右半边最小值的中间值
                    return (max(num1max,num2max)+min(num1min,num2min))/2.0;
                }
            }
            //切太左了
            else if(num2max>num1min){
                left = i+1;
            }
            else{
                right = i-1;
            }
        }
        return 0.0;
    }
};

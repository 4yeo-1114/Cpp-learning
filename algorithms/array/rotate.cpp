/* C++ | array: rotate. */
//开辟一个新数组
#include <vector>         
#include <unordered_map>  
#include <unordered_set>
#include <algorithm>    
#include <string>
#include <numeric>
using namespace std; 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> buf(len);
        //要分配空间!!!
        buf.reserve(len);
        for(int i = 0;i<len;i++){
            buf[(i+k)%len] = nums[i];
        }
        for(int i = 0;i<len;i++){
            nums[i] = buf[i];
        }
    }
};

//三次反转实现轮转
class Solution {
public:
    void swap(int&a,int&b){
        int temp = a;
        a = b;
        b = temp;
    }
    void reverse1(vector<int>&nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size()-1;
        k = k%(nums.size());
        reverse1(nums,start,end);
        reverse1(nums,0,k-1);
        reverse1(nums,k,nums.size()-1);
    }
};

//环状替换
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
        k = k%n;
        //要引入numeric
       int count = gcd(n,k);
       int start = 0;
       for(;start<count;start++){
        int current = start;
        int prev = nums[start];
        do{
            int next  = (current+k)%n;
            swap(nums[next], prev);
            current = next;

        }while(start!=current);
       }
    }
};

#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
#include <vector>
using namespace std;  

//超时做法 遍历
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        for(int  i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(prices[j]>prices[i]){
                    profit = max(profit,prices[j]-prices[i]);
                }
            }
        }
        return profit;
    }
};

//双指针做法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       if(n<=1){
            return 0;
       }
       int left = 0;
       int right =  left +1;
       int profit = 0;
       while(right<n){
            if(prices[right]>prices[left]){
                profit = max(profit,prices[right]-prices[left]);
            }
            else {
                left  =right; //遇到更低的买入点就移动
            }
            right ++;
       }
       return profit;
    }
};

//贪心做法
//维护一个历史最低及格 从左往右遍历就能满足先买入再卖出的条件
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       if(n<=1){
            return 0;
       }
       int min_price = prices[0];
       int profit = 0;
       for(int price : prices){
            min_price = min(min_price,price);
            profit = max(profit,price-min_price); //当前价格减去历史最低价格
       }
    }
};
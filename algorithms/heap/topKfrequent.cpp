#include <vector>         
#include <unordered_map>  
#include <unordered_set>
#include <algorithm>    
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std; 


//用小根堆
//不能只用map map 只能根据键排序 所以得用个小根堆才能把数字和次数反过来
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }

        //pair<频次，数字> 定义小根堆 堆顶是当前频次最小的
        //using 给pair<int,int>起个别名
        using PII = pair<int,int>;
        priority_queue<PII,vector<PII>,greater<PII>> minHeap;
        
        for(auto& [val,count] : countMap){
            minHeap.push({count,val});
            if(minHeap.size()>k){
                minHeap.pop(); //淘汰频次小的
            }
        }
        vector<int> result;
        while (!minHeap.empty()) {
            //注意是.second
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
        
    }
};


//另一种写法还是一样先统计次数 然后反过来反在桶里面再倒序遍历桶就好了
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 第一步：统计每个元素的出现次数
        unordered_map<int, int> cnt;
        int max_cnt = 0;
        for (int x : nums) {
            cnt[x]++;
            max_cnt = max(max_cnt, cnt[x]);
        }

        // 第二步：把出现次数相同的元素，放到同一个桶中
        vector<vector<int>> buckets(max_cnt + 1);
        for (auto& [x, c] : cnt) {
            buckets[c].push_back(x);
        }

        // 第三步：倒序遍历 buckets，把出现次数前 k 大的元素加入答案
        vector<int> ans;
        // 注意题目保证答案唯一，一定会出现某次 insert 后 ans.size() 恰好等于 k 的情况
        for (int i = max_cnt; ans.size() < k; i--) {
            ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        }
        return ans;
    }
};


#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> sum_of_twonums(vector<int>&nums,int target){
    unordered_map<int,int> idx;
    for(int i = 0;i < nums.size();i++){
        auto it = idx.find(target-nums[i]);
        //没找到 it的值就是idx.end()
        if(it!=idx.end()){//找到了
            return {it->second,i};
            //it->secend就是value 即下标

        }
        //没找到就更新哈希表
        idx[nums[i]] = i;
    }
}


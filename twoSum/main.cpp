#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

void hash_table(vector<int> nums){
    unordered_map<int,int> hash_table;

    for(int i=0;i< nums.size();i++){
        printf("%d\n",nums[i]);
        hash_table.emplace(nums[i],i);
        auto find_ = hash_table.find(nums[i]);
        printf("%d\n",find_->second);


    }
}
vector<int> twoSum(vector<int> nums, int target){
                   vector<int> solution;
                   unordered_map<int,int> hash_;
                   for(int i=0;i< nums.size();i++){
                        auto find_ = hash_.find(target - nums[i]);
                        if(find_ == hash_.end()) {
                                hash_.emplace(nums[i],i);

                        }
                        else{
                            printf("%d\t%d\n",find_->second,i);
                            return solution = {find_->second,i};
                        }

                   }
            }
int main()
{
    vector<int> nums = {1,3,2,5};
    //hash_table(nums);
    //twoSum(nums,5);
    //twoSum(nums,7);
    //twoSum(nums,8);
    //twoSum(nums,9);

    cout << "Hello world!" << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;
void my_swap(vector<int>& nums,int i,int j){//引用没有会报错！！
    int t;
    t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;

}
bool repeat_num(vector<int> nums,int len){//len elem ,0,1,,,,,len-1 in nums
    bool repeat = false;
    for(int i = 0;i<nums.size();i++){
        while(nums[i]!=i){
            if(nums[nums[i]]!=nums[i])
            my_swap(nums,i,nums[i]);
            else{
                printf("repeate");
                return true;
            }
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    //vector<int> nums = {1,2,2};
    vector<int> nums = {1,3,2,0};
    repeat_num(nums,2);
    return 0;
}

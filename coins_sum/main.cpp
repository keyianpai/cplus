#include <iostream>
#include <vector>
using namespace std;
int coins_sum(int* coins,int n,int amount){
        int sum[amount+1];//=0
        sum[0] = 0;
        for(int i =1;i<=amount;i++){
                sum[i] = -1;
                for(int j=0;j<n;j++){
                    if(coins[j]<=i&&sum[i-coins[j]]!=-1)
                        if(sum[i]==-1||sum[i-coins[j]]+1<sum[i])
                                 sum[i] = sum[i-coins[j]]+1;
                }

        }
        return sum[amount];


}
int knapsack(vector<int> weights,vector<int> values,int space){
    auto weights_s = weights.size() ;//item 0,1,,,,weight_s -1
    int dp[weights_s+1][space+1];//dp[i][j] j space full with 0,1,,,,i-1
    for(int i =0;i<=weights_s;i++){
        for(int j=0;j<=space;j++){
                if(i==0||j==0)
                    dp[i][j] = 0;
                if(weights[i-1]<j){
                    dp[i][j] = min(dp[i-1][j-weights[i-1]] + values[i-1],dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j]
                }

        }
    }


}

int main()
{   //int coins[2]={2,2} ;
    //coins[0]=2,coins[1]=3;
    //printf("%d%d",coins[0],coins[1]);
    //int ans = coins_sum(coins,2,3); //-1,coins[2]={2,2}
    //int ans = coins_sum(coins,2,100);//50
    int coins[3]={5,1,2} ;
    int ans = coins_sum(coins,3,11);//3
    //ans = min(4,2);//only two
    printf("%d",ans);
    cout << "Hello world!" << endl;
    return 0;
}

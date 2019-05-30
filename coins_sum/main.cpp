#include <iostream>
#include <vector>
using namespace std;
int coins_sum(int* coins,int n,int amount){
        int sum[amount+1];//=0
        sum[0] = 0;
        for(int i =1;i<=amount;i++){
                sum[i] = -1;
                for(int j=0;j<n;j++){// coin 0,1,,,,n-1
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
                else if(weights[i-1]<=j){//<=,,,else if
                    dp[i][j] = max(dp[i-1][j-weights[i-1]] + values[i-1],dp[i-1][j]);//max£¡£¡£¡
                }else{
                    dp[i][j] = dp[i-1][j];
                }

        }
    }
    return dp[weights_s][space];


}
void cinhexoct1(){
    int a , b,c;
    //cout<<"a,b before input:"<<endl;
    cout<<a<<'	'<<b<<' '<<c<<endl;
//cin>>oct>>a;//>>hex>>b;
    cin>>oct>>a;
    cin>>dec>>b;
    cin>>hex>>c;
    cout<<a<<'	'<<b<<' '<<c<<endl;
    //cout<<a<<'	'<<b<<endl;


}
void cin2i(){
int a , b;
cout<<"a,b before input:"<<endl;
cout<<a<<'	'<<b<<endl;
cin>>a>>b;
cout<<a<<'	'<<b<<endl;
}
void cin2iignore(){
int a , b;
cout<<"a,b before input:"<<endl;
cout<<a<<'	'<<b<<endl;
cin>>a;
cin.ignore(10,',');
cin>>b;
cout<<a<<'	'<<b<<endl;
}
void scanf2i(){
int a , b;
cout<<"a,b before input:"<<endl;
cout<<a<<'	'<<b<<endl;
scanf("%d%d",&a,&b);//扫描屏幕输入，以十进制（%d）读入两个变量a,b中
cout<<a<<'	'<<b<<endl;
}
void scanfcomma2i(){//first must comma,then 0to several spaces
int a , b;
cout<<"a,b before input:"<<endl;
cout<<a<<'	'<<b<<endl;
scanf(",%d%d",&a,&b);//扫描屏幕输入，以十进制（%d）读入两个变量a,b中
cout<<a<<'	'<<b<<endl;
}
void scanfspacecomma2i(){//first must comma,then 0to several spaces
int a , b;
cout<<"a,b before input:"<<endl;
cout<<a<<'	'<<b<<endl;
scanf(" ,%d%d",&a,&b);//扫描屏幕输入，以十进制（%d）读入两个变量a,b中
cout<<a<<'	'<<b<<endl;
}
void scanf2ispace(){//可以分割中间任意空白字符
int a , b;
cout<<"a,b before input:"<<endl;
cout<<a<<'	'<<b<<endl;
scanf("%d %d",&a,&b);//扫描屏幕输入，以十进制（%d）读入两个变量a,b中
cout<<a<<'	'<<b<<endl;
}
void scanf2icomma(){//中间不能有空白，前面可以
int a , b;
cout<<"a,b before input:"<<endl;
cout<<a<<'	'<<b<<endl;
scanf("%d,%d",&a,&b);//扫描屏幕输入，以十进制（%d）读入两个变量a,b中
cout<<a<<'	'<<b<<endl;
}
void scanf2ispacecomma(){//可以分割中间任意空白字符,逗号之前与之后的空白
int a , b;
cout<<"a,b before input:"<<endl;
cout<<a<<'	'<<b<<endl;
scanf("%d ,%d",&a,&b);//扫描屏幕输入，以十进制（%d）读入两个变量a,b中
cout<<a<<'	'<<b<<endl;
}
void scanf2icommaspace(){////第一个数字紧跟comma
int a , b;
cout<<"a,b before input:"<<endl;
cout<<a<<'	'<<b<<endl;
scanf("%d, %d",&a,&b);//扫描屏幕输入，以十进制（%d）读入两个变量a,b中
cout<<a<<'	'<<b<<endl;
}
void cin2ch(){
char c,a , b;
cin>>a>>b;
cout<<a<<'	'<<b<<endl;
printf("%d%d",a,b);//crlf cr 13 lf 10 out lf tab 9 space 32
}
void scanf2ch(){
char a , b;
cout<<"a,b before input:"<<endl;
cout<<a<<'	'<<b<<endl;
scanf("%c%c",&a,&b);//%d 'a' exit eat space
cout<<a<<'	'<<b<<endl;
printf("%d%d",a,b);//crlf cr 13 lf 10 out lf tab 9 space 32
}
void scanf2chspace(){
char a , b;
cout<<"a,b before input:"<<endl;
cout<<a<<'	'<<b<<endl;
scanf(" %c %c",&a,&b);//%d 'a' exit eat space must add two space to same cin char
cout<<a<<'	'<<b<<endl;
printf("%d%d",a,b);//crlf cr 13 lf 10 out lf tab 9 space 32
}
void cin2f(){
float a , b;
cin>>a>>b;
cout<<a<<'	'<<b<<endl;
}
void cin2str(){
char a[1000] , b[1000];
cin>>a>>b;
cout<<a<<'	'<<b<<endl;
}
void cin2str1(){
char* a , b;
cin>>a>>b;
cout<<a<<'	'<<b<<endl;
}
void cin2str2(){
string a , b;
cin>>a>>b;
cout<<a<<'	'<<b<<endl;
}


int main()
{   //int coins[2]={2,2} ;
    //coins[0]=2,coins[1]=3;
    //printf("%d%d",coins[0],coins[1]);
    //int ans = coins_sum(coins,2,3); //-1,coins[2]={2,2}
    //int ans = coins_sum(coins,2,100);//50
    //int coins[3]={5,1,2} ;
    //int ans = coins_sum(coins,3,11);//3
    //ans = min(4,2);//only two
    //printf("%d",ans);
    //int i=1,j=2;//444.4 ->444 345.7 ->345
    //char c='a';//1->1, space1 ->1
    //char str[6];
    //char* str;
    //cin>>i>>j;
    //cin>>i>>c>>j;
    //scanf("%d,%d",&i,&j);
    //printf("%d%d\n",i,j);
    //scanf(" %c",&c);
    //printf("%c",c);


    //cin>>str;
    //cout<<i<<endl;

    //cout << "Hello world!" << endl;
    //cin2i();
    //scanf2i();
    //scanf2ispace();
    //cin2ch();
    //scanf2ch();
    //scanf2chspace();
    //cin2f();
    //cin2str1();//wrong
    //void cinhexoct();
    //cinhexoct1();
    //cin2iignore();
    //scanf2icomma();//第一个数字紧跟comma
    //scanf2ispacecomma();
    //scanf2icommaspace();//第一个数字紧跟comma
    //scanfcomma2i();
    cinhexoct1();
    //scanfspacecomma2i();
    return 0;
    //good  teamviewer
}

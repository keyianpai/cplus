#include <iostream>
#include <vector>
#include <string>
#include <memory>//auto_ptr
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
    /** \brief
     *
     * \param
     * \param
     * \return
     *
     float f;
	printf("**************************\n");
	printf("dotcpp.com\n");
	printf("**************************\n");
	scanf("%4f",&f);
	printf("%f",f);
	int d=-12;
    float b=-3.1415;
    char c='A';
    printf("%d\n",a);
    printf("o%o\n",a);
    cout<<a<<endl;
    printf("0x%x\n",a);
    cout<<a<<endl;
    printf("%3.2f\n",b);
    printf("%c\n",c);

     */



}
void cin2i(){
int a , b;
cout<<"a,b before input:"<<endl;
cout<<a<<'	'<<b<<endl;
cin>>a>>b;
cout<<"a,b after input:"<<endl;
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
void staticlocal(){
static int a;
int b;
cout<<"static int a:  "<<a<<"int b:  "<<b<<endl;
}

void autoptr(){
auto_ptr<string> p1 (new string("hello."));
//unique_ptr<string> p1 (new string("hello."));
cout<<*p1<<endl;
auto_ptr<string> p2 = p1;
cout<<*p2<<endl;
//cout<<*p1<<endl;//wrong when run
}

void uniqueptr(){
unique_ptr<string> p1 (new string("hello."));
cout<<*p1<<endl;
//unique_ptr<string> p2 = p1; // wrong compile
//cout<<*p2<<endl;
//cout<<*p1<<endl;//wrong when run
}

void sharedptr(){
shared_ptr<string> p1 (new string("hello."));
cout<<"p1.unique():  "<<p1.unique()<<endl;
cout<<"p1.use_count():  "<<p1.use_count()<<endl;
cout<<*p1<<endl;
shared_ptr<string> p2 = p1; // wrong compile
cout<<"p1.unique():  "<<p1.unique()<<endl;
cout<<"p1.use_count():  "<<p1.use_count()<<endl;
cout<<"p2.use_count():  "<<p2.use_count()<<endl;
p1.reset();
cout<<"p1 reset, p2.use_count():  "<<p2.use_count()<<endl;//1
cout<<"p1 reset, p1.use_count():  "<<p1.use_count()<<endl;//0

cout<<*p2<<endl;
//cout<<*p1<<endl;//wrong after p1 reset
}
class A{
int a;
public:
A(){
cout<<"A constructing..."<<endl;
  }
  void fun(int a){// non const obj a use nonconst or const
      cout<<"A's fun..."<<endl;
  };
  /** \brief
   *
   * \param a int
   * \return int
   *
   int fun(int a){
  return 1;};// wrong with different return
   */
   //void fun(const int a){ const int can't
  //};
  void fun(const int a)const{ //const obj a only use const
     cout<<"A's const fun..."<<endl;
  };
   void fun(const int a,int b){
  };
   void fun(const int a,int b)const{//without const can't reload
  };


};

void constfun(){
    A a;
    a.fun(1);
    const A b;
    b.fun(1);
    }
//A a;// exe before main
//a.fun(1); //wrong outside

void constcast(){
const int constant = 26;//without const, will change to 3 later
    const int* const_p = &constant;
    //*const_p = 4; // wrong
    //int mod = const_cast<int>(constant);//invalid use of const_cast with type 'int', which is not a pointer, reference, nor a pointer-to-data-member type
    int* modifier = const_cast<int*>(const_p);
    *modifier = 3;
    cout<< "constant:  "<<constant<<endl;
    cout<<"*modifier:  "<<*modifier<<endl;
    //system("pause");
}
void InputInt(int * num)
{
    cout<<*num<<endl;
}
void removeconst(){
    const int constant = 21;
    //InputInt(&constant); //error C2664: “InputInt”: 不能将参数 1 从“const int*”转换为“int *”
    int* a =const_cast<int*>(&constant);
    cout<< "int* a =const_cast<int*>(&constant),*a: "<<*a<<endl;
    InputInt(a);
    system("pause");
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
    //cinhexoct1();
    //scanfspacecomma2i();

    //staticlocal();
    //autoptr();
    //uniqueptr();
    //sharedptr();
    //for(int i = 0; i < 20; i--) cout << "hello" << endl;//< to +
    //constfun();
    constcast();
    //removeconst();
return 0;
    //good  teamviewer
}

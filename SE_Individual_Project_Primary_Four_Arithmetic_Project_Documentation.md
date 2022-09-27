# SE Individual Project 

2106050130 徐圣翔

[TOC]

## 四则运算——初级

### 题目

编写一个四则运算程序，满足如下要求

1. 题目要求：100以内加减法，满足小学二年级数学口算需求
2. 使用参数控制生成题目的个数
3. 每道题目中出现的运算符个数不超过两个
4. 程序一次运行生成的题目不能重复，请思考关于重复的定义。生成的题目存入执行程序的当前目录下的Exercises.txt文件，格式如下：
   1. 四则运算题目1
   2. 四则运算题目2
5. 再生成题目的同时，计算出所有题目的答案，并存入执行程序的当前目录下的Answers.txt文件，格式如下：
   1. 答案1
   2. 答案2
6. 估计需求分析、设计、编码、测试各阶段时间，记录实际工作中各项工作时间花费，并列表进行对比

### 需求分析

start at 20:30

1. 首先，100以内加减法，100以内加减法是指参与运算的数不超过100，还是运算结果不超过100？

   通过对市面上的100以内加减法的习题的分析研究，以及对于小学二年级家长与老师的采访调研，得出100以内加减法，100以内加减法是指参与运算的数和运算结果都不超过100的含义。

2. 使用参数控制生成题目的个数就是需要用户输入数量
3. 每道题目中出现的运算符个数不超过两个即为，运算符只能是一个或者两个
4. 一次运行生成的题目不能重复，那么对于一个运算符的情况，不能出现1+2和2+1或1+2和1+2的情况，对于两个运算符情况，不能出现1+1+2与1+2+1的情况
5. 生成的题目及其答案需要对应的存入相应的文件里面

end at 20:42

cost time 12min

### 设计

start at 22:35

1. 用num存储生成题目的个数。
2. 用随机数ra的0和1表示运算符的个数，0代表1个运算符，1代表2个运算符。
3. 再用随机数opt的0和1代表+-运算符，0代表+，1代表-。
4. 随机生成参与运算的0-100之间数字，首先计算结果，如果大于100就不记入已产生的四则运算式子。
5. 对于重复的，我们可以采用数据结构来存储，将加减号转换为正负号，存入[-100,+100]的两个或者三个数组内。
6. 使用文件流操作，将数据读入txt其中。

end at 22:48 

cost time 13min

### 编码

begin at 0:07

```cpp
#include <bits/stdc++.h>
//#define LOCAL
using namespace std;
typedef long long ll;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const double pi=acos(-1.0);
const int INF=1000000000;
const int maxn=1000005;
int num,ans=0;
int plustwo[110][110],minutwo[110][110],operatthree[500][500][500];
int main()
{
	IOS;
    #ifdef LOCAL
    	freopen("input.txt","r",stdin);
    	freopen("output.txt","w",stdout);
    #endif
    srand(time(NULL));
	memset(plustwo,0,sizeof(plustwo));
	memset(minutwo,0,sizeof(minutwo));
	memset(operatthree,0,sizeof(operatthree));
	cout<<"please input the number of the questions that you need:"<<endl;
	cin>>num;
	fstream f;
	f.open("Exercises.txt",ios::out);
	f.close();
	f.open("Answers.txt",ios::out);
	f.close();
	while(ans<num){
		int ra=rand()%2+1;
		if(ra==1){
			int a1=rand()%100+1,a2=rand()%100+1,opt=rand()%2+1,res;
			if(opt==1){
				res=a1+a2;
				if(res<0||res>100)	continue;
				if(plustwo[a1][a2]==1)	continue;
				plustwo[a1][a2]=1;
				//cout<<ans+1<<":"<<a1<<"+"<<a2<<"="<<res<<endl;
				f.open("Exercises.txt",ios::out|ios::app);     
				f<<ans+1<<":"<<a1<<"+"<<a2<<"="<<endl;	
				f.close();   
				f.open("Answers.txt",ios::out|ios::app);    
				f<<ans+1<<":"<<res<<endl;	
				f.close();                
			}	
			else{
				res=a1-a2;
				if(res<0||res>100)	continue;
				if(minutwo[a1][a2]==1)	continue;
				minutwo[a1][a2]=1;
				//cout<<ans+1<<":"<<a1<<"-"<<a2<<"="<<res<<endl;
				f.open("Exercises.txt",ios::out|ios::app);     
				f<<ans+1<<":"<<a1<<"-"<<a2<<"="<<endl;	
				f.close();   
				f.open("Answers.txt",ios::out|ios::app);    
				f<<ans+1<<":"<<res<<endl;	
				f.close();       
			} 
			ans++;
		}
		else {
			int a1=rand()%100+1,a2=rand()%100+1,a3=rand()%100+1,res,opt1=rand()%2+1,opt2=rand()%2+1;
			int b1=a1,b2=a2,b3=a3;
			if(opt1==2)		b2=-b2;
			if(opt2==2)		b3=-b3;
			res=b1+b2+b3;
			if(res<0||res>100)	continue;
			if(operatthree[b1][200+b2][200+b3]==1)	continue;
			operatthree[b1][200+b2][200+b3]=1;
			/*cout<<ans+1<<":"<<a1;
			if(opt1==1)		cout<<"+";
			else 	cout<<"-";
			cout<<a2;
			if(opt2==1)		cout<<"+";
			else 	cout<<"-";
			cout<<a3<<"="<<res<<endl;*/
			f.open("Exercises.txt",ios::out|ios::app);     
			f<<ans+1<<":"<<a1;
			if(opt1==1)		f<<"+";
			else 	f<<"-";
			f<<a2;
			if(opt2==1)		f<<"+";
			else 	f<<"-";
			f<<a3<<"="<<endl;	
			f.close();   
			f.open("Answers.txt",ios::out|ios::app);    
			f<<ans+1<<":"<<res<<endl;	
			f.close();  
			ans++; 
		}
	}
    return 0;
}
```

end at 0:33

cost time 26min

### 重构代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int num,ans=0;
int plustwo[110][110],minutwo[110][110],operatthree[500][500][500];
fstream f;

void gentxt();		//创建Exercises和Answers文件
void outtwoex(int a1,int a2,int opt);	//单符号加减法输出到Exercises
void outans(int res);	//输出到Answers
void outthreex(int a1,int a2,int a3,int opt1,int opt2);	//双符号加减法输出到Exercises

int main()
{
    srand(time(NULL));

	cout<<"please input the number of the questions that you need:"<<endl;
	cin>>num;
	
	gentxt();
	while(ans<num){
		int ra=rand()%2+1;		//判断单双符号
		if(ra==1){
			int a1=rand()%100+1,a2=rand()%100+1,opt=rand()%2+1,res;
			if(opt==1){		//单符号为+
				res=a1+a2;
				if(res<0||res>100)	continue;
				if(plustwo[a1][a2]==1)	continue;		//判断重复
				plustwo[a1][a2]=1;
				
				outtwoex(a1,a2,opt);
				outans(res);            
			}	
			else{			//单符号为-
				res=a1-a2;
				if(res<0||res>100)	continue;
				if(minutwo[a1][a2]==1)	continue;		//判断重复
				minutwo[a1][a2]=1;
				
				outtwoex(a1,a2,opt);
				outans(res);     
			} 
			ans++;
		}
		else {				//双符号
			int a1=rand()%100+1,a2=rand()%100+1,a3=rand()%100+1,res,opt1=rand()%2+1,opt2=rand()%2+1;
			int b1=a1,b2=a2,b3=a3;
			if(opt1==2)		b2=-b2;
			if(opt2==2)		b3=-b3;
			
			res=b1+b2+b3;
			if(res<0||res>100)	continue;
			if(operatthree[b1][200+b2][200+b3]==1)	continue;
			operatthree[b1][200+b2][200+b3]=1;
			
			outthreex(a1,a2,a3,opt1,opt2);
			outans(res); 
			ans++; 
		}
	}
    return 0;
}
void gentxt(){
	f.open("Exercises.txt",ios::out);
	f.close();
	f.open("Answers.txt",ios::out);
	f.close();
}
void outtwoex(int a1,int a2,int opt){
	f.open("Exercises.txt",ios::out|ios::app);
	if(opt==1)     f<<ans+1<<":"<<a1<<"+"<<a2<<"="<<endl;	
	else	f<<ans+1<<":"<<a1<<"-"<<a2<<"="<<endl;	
	f.close();  
}
void outans(int res){
	f.open("Answers.txt",ios::out|ios::app);    
	f<<ans+1<<":"<<res<<endl;	
	f.close(); 
}
void outthreex(int a1,int a2,int a3,int opt1,int opt2){
	f.open("Exercises.txt",ios::out|ios::app);     
	f<<ans+1<<":"<<a1;
	if(opt1==1)		f<<"+";
	else 	f<<"-";
	f<<a2;
	if(opt2==1)		f<<"+";
	else 	f<<"-";
	f<<a3<<"="<<endl;	
	f.close();    
}
```

### 测试

start at 0:37

无bug

输入：20

```cpp
//Exercises.txt
1:81-50=
2:10+48-1=
3:45+35=
4:43-2=
5:72+7=
6:99-37=
7:59-55=
8:38-7=
9:66-25=
10:79-21=
11:8+35=
12:74-15=
13:8-54+73=
14:78+22-71=
15:37+39=
16:85-41=
17:24+6=
18:96-12=
19:22+8=
20:5+67-40=
```

```cpp
//Answers.txt
1:31
2:57
3:80
4:41
5:79
6:62
7:4
8:31
9:41
10:58
11:43
12:59
13:27
14:29
15:76
16:44
17:30
18:84
19:30
20:32
```

end at 0:43

cost time 6min

### 思路说明

首先输入要生成多少条四则运算题目。

然后对于每一条题目我们来随机生成是一个运算符还是两个运算符。

如果是一个运算符，随机生成a+b或者a-b的形式。

如果是两个运算符，就随机生成a+b+c或a+b-c或a-b+c或a-b-b的形式。

然后我们来考虑如何避免重复的情况发生。

对于一个运算符+的情况，我们用二维数组来存储a和b是否出现过。

对于一个运算符-的情况，我们再用另一个二维数组来存储a和b是否出现过。

对于两个运算符，我们将减100变成加-100，从而全部转换到+域上来。

简而言之就是当运算符为-的时候，将后面的一个数字变为相反数。

然后我们只需要用一个三维数组来存储a、b、c是否出现过即可。

最后将运算式及其答案分别存入文件即可。

### 时间花费比较

| 需求分析 | 12minutes |
| -------- | --------- |
| 设计     | 13minutes |
| 编码     | 26minutes |
| 测试     | 6minutes  |


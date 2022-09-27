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
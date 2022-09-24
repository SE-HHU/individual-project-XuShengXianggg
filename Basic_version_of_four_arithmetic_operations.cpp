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
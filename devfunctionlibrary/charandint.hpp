//字符，字符串等
#ifndef __cplusplus
	#error This library is only for C++
#endif 
#define int2char(a)  ((char)(a)+'0')//数字转字符 
#define char2int(a)  ((int)(a)-'0')//字符转数字 
#define Achar2int(a) ((int)(a))  //计算该字符对应的ascii码 
#define Aint2char(a) ((char)(a))//该ascii码对应的字符 
#define digit(a) ((a)>='0'&&(a)<='9')//判断该字符是不是数字 
#define alpha(a) ((a)>='A'&&a<='Z'||(a)>='a'&&(a)<='z' )//判断该字符是不是字母 
#define ctnstring2charstring(str) ((str).c_str())//string转char 
#define stringcmp(a,b) (((a)==(b))?0:(a)>(b)?1:-1)//string串比较 
#define ischinese(ch) (((ch)&0x8000)&&((ch)&0x0080)) 
#define arechinese(ch) (((ch[0])&0x80)&&((ch[1])&0x80)) 
#define cansee(a) ((a)>31&&(a)<127)//可见字符 
#define UP        72
#define DOWN      80
#define LEFT      75
#define RIGHT     77
#define ENTER     13
#define ESC       27
#define TAB       9
#define DEL       83
#define BACKSPACE 8
using namespace std;
long long string2int(string a)
{
	long long ans=0;
	for(int i=0;i<a.size();i++)
	  if(digit(a[i]))
	    ans=ans*10+a[i]-'0';
	return a[0]=='-'?-ans:ans;
}
string int2string(long long a)
{
	if(a==0)
	  return "0";
	string ans="";
	if(a<0)
	{
		ans+='-';
		a=absolute(a);
	}
	while(a>0)
	{
		ans+=(a%10)+'0';
		a/=10;
	} 
	reverse(ans.begin(),ans.end());
	return ans;
}
void initcharmap(char *s,char *e,char init)//初始化字符地图 
{
	for(;s<=e;s++)
	  *s=init;
}
ull Hstring2int(string change)//计算字符串hash值 
{
	ull ret=0;
	for(int i=0;i<change.size();i++)
	  ret+=change[i]*(i+1);
	return ret;
}
ull charlen(char *a)//char串获取大小 
{
	ull i;
	for(i=0;a[i]!='\0';i++);
	return i;
}
short fastcharcmp(char *a,char *b)//快速比较char串大小 
{
	int al=charlen(a),bl=charlen(b);
	if(al!=bl)
	  return (al<bl)? -1:1;
	else
	  for(int i=0;i<al;i++)
	  	if(a[i]!=b[i])
	  	  return a[i]<b[i]?-1:1;
	return 0;
}
bool passwordcmp(char *input,char *password)//安全比较char串大小 
{
	bool ret=true;
	int al=charlen(password),bl=charlen(password);
	for(int i=0;i<min(al,bl);i++)
	  if(input[i]!=password[i])
	    ret=false;	
	if(al!=bl)
  	  ret=false; 
	return ret;  
}
string charstring2ctnstring(char *str)//将char串改为string串 
{
	string ret="";
	for(ull i=0;i<charlen(str);i++)
	  ret+=str[i];
	return ret;
}
char *splicingstrings(char *fst,char *scd)//拼接两串 
{
	string ret="";
	for(int i=0;i<charlen(fst);i++)
	  ret+=fst[i];
	for(int i=0;i<=charlen(scd);i++)
	  ret+=scd[i];
	return (char*)ret.c_str();
}
string strmov(string a,int mov)
{
	string movs="";
	for(int i=mov;i<a.size();i++)
	  movs+=a[i];
	for(int i=0;i<mov;i++)
	  movs+=a[i];
	return movs;
}
long long match(char *m1,long long m1sz,char *m2,long long m2sz)
{
	if(m1sz<m2sz)
	  return -1;
	for(int i=0;i<m1sz;i++)
	{
		bool flag=true;
		for(int j=0;j<m2sz;j++)
		  if(m1[i+j]!=m2[j]||i+j>=m1sz)
		  {
		      flag=false;
		  	  break;
		  }
		if(flag)
		  return i;
	}
	return -1;
}
void getnext(char *str,ull size,ll *next)
{
	ll j=-1;
	next[0]=-1;
	for(ull i=1;i<size;i++)
	{
		while(str[i]!=str[j+1]&&j!=-1)
		  j=next[j];
		if(str[i]==str[j+1])
		  j++;
		next[i]=j;
	}
}
ull KMPmatch(char *str1,ull size1,char *str2,ull size2)
{
	if(size1<size2)
	  return -1;
	if(size2>size1)
	  return 1;
	ll *next=new ll[size1],j=-1,ans=-1;
	getnext(str1,size1,next);
	for(int i=0;i<size1;i++)
	{
		while(str1[i]!=str2[j+1]&&j!=-1)
		  j=next[j];
		if(str1[i]==str2[j+1])
		  j++;
		if(j==size2-1)
		{
			ans=i-size2+1;
			break;
		}
	}
	delete[] next;
 	return ans;
}
string double2string(long double a)
{
	std::ostringstream strs; 
	strs << a; 
	return strs.str();
} 
wchar_t *char2wchart(char *infile) 
{
	int num=MultiByteToWideChar(0,0,infile,-1,NULL,0);
	wchar_t*wide=new wchar_t[num];
	MultiByteToWideChar(0,0,infile,-1,wide,num);
	return wide;
}
short withoutclmatch(string a,string b)
{
	for(int i=0;i<min(a.size(),b.size());i++)
	{
		if(a[i]>='a'&&a[i]<='z')
		{
			a[i]-='a';
			a[i]+='A';
		}
		if(b[i]>='a'&&b[i]<='z')
		{
			b[i]-='a';
			b[i]+='A';
		}
	}
	if(a<b)
	  return -1;
	if(a>b)
	  return 1;
	return 0;
}
void skipspace(string a,U I &i)
{
	for(;i<a.size()&&!cansee(a[i])||a[i]==' ';i++);
}
void skipspace(char *a,long long size,U I &i)
{
	for(;i<size&&!cansee(a[i])||a[i]==' ';i++);
}
void erasespace(string &line)
{
	for(int k=0;k<line.size();k++)
	  if(line[k]==' '||!cansee(line[k]))
	  {
	  	  line.erase(k,1);
	  	  k--;
	  }
	return;
}

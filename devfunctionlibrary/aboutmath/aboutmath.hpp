//数学相关函数 
//比大小类宏定义
#ifndef __cplusplus
	#error This library is only for C++
#endif 
#define eps 1e-8
#define maxv(a,b) ((a)>(b)?(a):(b)) 
#define minv(a,b) ((a)<(b)?(a):(b) )
#define dequ(a,b)  ((fabs((a)-(b)))<(eps))
#define dmore(a,b) (((a)-(b))>(eps))
#define dless(a,b) (((a)-(b))<(-eps))
#define dme(a,b)   (((a)-(b))>(-eps))
#define dle(a,b)   (((a)-(b))<(eps))
#define PI (3.1415926535898)
#define absolute(a) ((a)>0?(a):-(a) )
#define Ceil(a) (((a)!=(ll)(a))?(ll)(a+1):(ll)(a))
#define Floor(a) ((ll)(a))
#define rounding(a) ((ll)((a)+0.5)) 
#define getdecimal(a) ((long double)(a)-Floor((a)))    
#define lcm(a,b) ((a)*(b)/(gcd((a),(b)))*2) 
#define opposite(a) (-(a))
#define complementary(a,b) ((bool)(a)+(b)==90)
#define supplementary(a,b) ((bool)(a)+(b)==180)  
#define TPC(x,y,x1,y1,x2,y2) ((bool)((((x1)-(x))*((y2)-(y)))==(((x2)-(x))*((y1)-(y)))))//三点共线 
#define Hsplchar2int(o,t,th,f) ((o)*0x1000000+(t)*0x10000+(th)*0x100+(f)*0x01)
#define Hsplchar2ll(o,t,th,f,fi,s,se,e) ((o)*0x100000000000000000000000+(f)*0x100000000+(fi)*0x1000000+(s)*0x10000+(se)*0x100+(e)*0x01)
#define slope(x,y,x1,y1) (((y)-(y1))/(double)((x)-(x1)))//斜率 
#define TAS(s,n,a,x) (((x)*(n)*(n)-3*(x)*(n))/2+(x)+(a)*(n)-(a)+(s))//双等数列求N 
#define sumofOAS(s,m,xs) ((((s)+(m))*(xs))/2)//单等差求和 
#define OAS(s,gc,n) (((n)-1)*(gc)+(s))//单等差第N项 
#define TSD(a,b) (((a)-(b))*((a)+(b))) //平方差 
#define SOM(n) (((n)*((n)-1)*(2*(n)+1))/6) //平方和
#define CS(n) (((n)*(n)*((n)+1)*((n)+1))/4)//立方和 
#include "aboutpav.hpp"
#include "aboutarrays.hpp" 
inline long double power(long double a,long long b)//求a的b次方 
{
	return (b==0)?1:(a==1)?1.00:(a==-1)?(b%2==0LL)?1:-1:(a==0)?0.00:(b<0)?1.00/power(a,-b):(b>0)?a*1.00*power(a,b-1):1.00;
} 
inline double Sqrt(long long a)
{
	ull less=0;
	for(;less*less<=a;less++);
	less--;
	return less+(a-less*less)/(less*2.0);
}
long double DS(long double a,long long b)//a的圈b次方 
{
	return 1.0/power(a,b-1); 
}
bool isprime(ll prime)
{
	prime=fabs(prime);
	if((prime>10&&prime%10!=1&&prime%10!=3&&prime%10!=7&&prime%10!=9)||(prime==0||prime==1))
	  return false;
	for(ll i=3;i<=sqrt(prime);i+=2)
	  if(prime%i==0)
	    return false;
	return true;
}
ll fibonacci(ll a)//求斐波那契数列 
{
	int b=1,c=1,d;
	if(a==1||a==2)
	  return 1;
	if(a==3)
	  return 2;
	for(int i=3;i<=a;i++)
	{
		d=b+c;
		b=c;
		c=d;
	}
	return d;
}
ull factorial(U I a)//阶乘 
{
	return a>1?a*factorial(a-1):1;
}
ll gcd(ll a,ll b)
{
	ll mod=2;
	for(;(a%mod||b%mod)&&mod<=min(a,b);mod++);
	return (mod>min(a,b))?1:mod*gcd(a/mod,b/mod);
} 
string ull2H(ull to)
{
	string ret="";
	while(to!=0)
	{
		ret+="0123456789ABCDEF"[to%16];
		to/=16;
	}
	reverse(ret.begin(),ret.end());
	return ret; 
} 
template<typename tp>
inline tp manyminv(tp *start,tp *end)
{
	tp *ts=start;
	tp ret=0x3fffff;
	while(ts<=end)
	{
		ret=minv(ret,*ts);
		ts++;
	}  
	return ret;
}
template<typename tp>
inline tp manymaxv(tp *start,tp *end)
{
	tp *ts=start;
	tp ret=0;
	while(ts<=end)
	{
		ret=maxv(ret,*ts);
		ts++;
	}  
	return ret;
}  
float cubic_w_f(float x,float a)//双三次差值基函数  
{
    return (x<=1)?1-(a+3)*x*x+(a+2)*x*x*x:(x<2)?-4*a+8*a*x-5*a*x*x+a*x*x*x:0.0;
}
void cal_cubic_coeff(float x,float y,float*coeff)
{
    float u=x-floor(x)+1,v=y-floor(y)+1,a=0,A[4];
    A[0]=cubic_w_f(abs(u),a);
    A[1]=cubic_w_f(abs(u-1),a);
    A[2]=cubic_w_f(abs(u-2),a);
    A[3]=cubic_w_f(abs(u-3),a);
    for(int s=0;s<4;s++)
    {
        float C=cubic_w_f(abs(v-s),a);
        coeff[s*4]=A[0]*C;
        coeff[s*4+1]=A[1]*C;
        coeff[s*4+2]=A[2]*C;
        coeff[s*4+3]=A[3]*C;
    }
} 
uchar cubic_inner(U I *src,float x_float,float y_float,int b)
{
    float coeff[16];
    cal_cubic_coeff(x_float,y_float,coeff);//计算权重系数
    float sum=0.0;
    int x0=floor(x_float)-1,y0=floor(y_float)-1;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            sum+=coeff[i*4+j]*src[(y0+i)*b+x0+j];
    return ((uchar)sum);
}

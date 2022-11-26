//有关数组的 
#define lowbit(x) ((x)&(-x)) 
#define sethighest(a,set) ((a)=(((a)&0x7f)|(set)<<7)) 
#define gethighest(a) (((a)&0x80)>>7)
template<typename rvs>
void arraysreverse(rvs rvers[])
{
	ull sizes=sizeof(rvers)/sizeof(rvs);
	for(ull i=0;i<sizes/2;i++)
	  exchange(rvers[i],rvers[sizes-i-1]);
	return;
}
template<typename sm>
sm sumofarray(sm sum[])
{
	sm ret=0;
	for(ull i=0;i<sizeof(sum)/sizeof(sm);i++)
	  ret+=sum[i];
}
template<typename avg>
avg average(avg avs[])
{
	return sum(avs)/(sizeof(avs)/sizeof(avg)); 
}
const ull r7=pow(2,7),r14=pow(2,14),r21=pow(2,21),r28=pow(2,28),r35=pow(2,35),r42=pow(2,42);
const ull R7=r7,R14=r7+r14,R21=r7+r14+r21,R28=r7+r14+r21+r28,R35=r7+r14+r21+r28+r35,R42=r7+r14+r21+r28+r35+r42;
const ull r[7]={1,r7,r14,r21,r28,r35,r42};
const ull R[7]={0,R7,R14,R21,R28,R35,R42};	
int int2vlq(ull num,unsigned char *vlq)//返回vlq的size 
{
	ull facevl,sz=0;
	for(int i=0;i<7;i++)
	  if(num<R[i])
	  {
	  	  facevl=num-R[i-1];
	  	  sz=i;
	  	  break;
	  }
	memset(vlq,0,sz);
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<7;j++)
		{
			vlq[i]+=(facevl%2)<<j;
			facevl/=2;
		}
		sethighest(vlq[i],1);//全部置一 
	}
	sethighest(vlq[sz-1],0);//最后一位置零
	return sz; 
}
ull vlq2int(unsigned char *vlq)
{
	ull size=0,facevl=0;
	for(;gethighest(vlq[size]);size++);
	for(int i=size;i>=0;i--)
	  facevl+=(vlq[i]&0x7f)<<(i*7);
	return facevl+R[size];
}

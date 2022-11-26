//时间函数 
#ifndef __cplusplus
	#error This library is only for C++
#endif 
#define leapyear(a) ((a)%4==0&&(a)%100!=0||(a)%400==0)//平闰年 
#define sectominu(sec) ((sec)/60)
#define minutohour(minu) ((minu)/60)
#define sectohour(sec) ((sec)/3600)
SYSTEMTIME gettime(void)//获取时间 
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	return sys;
}
ull rander(ull a)//随机数 
{
	SYSTEMTIME sys=gettime();
	return (sys.wMilliseconds*sys.wSecond*sys.wYear+sys.wMinute*sys.wHour)%a;
}
void waitforstringdate(string command)//等待到时间（2021-11-12-22-00-00,年月日时分秒） 
{
	string a=command;
	if(a.substr(0,2)=="-t"||a.substr(0,2)=="-T")
	  a.erase(0,2);
	long long string2int(string a);
	int year=string2int(a.substr(0,4)),mon=string2int(a.substr(5,2)),day=string2int(a.substr(8,2)),h=string2int(a.substr(11,2)),m=string2int(a.substr(14,2)),s=string2int(a.substr(17,2));
	while(1)
	{
		Sleep(1000);
		SYSTEMTIME nowtime=gettime();
		if(nowtime.wYear==year&&nowtime.wMonth==mon&&nowtime.wDay==day&&nowtime.wHour==h&&nowtime.wMinute==m&&nowtime.wSecond==s)
		  return;
	}
} 
void waitfordate(int year,int mon,int day,int h,int m,int s)//等待到时间（2021-11-12-22-00-00,年月日时分秒） 
{
	while(1)
	{
		Sleep(1000);
		SYSTEMTIME nowtime=gettime();
		if(nowtime.wYear==year&&nowtime.wMonth==mon&&nowtime.wDay==day&&nowtime.wHour==h&&nowtime.wMinute==m&&nowtime.wSecond==s)
		  return;
	}
} 

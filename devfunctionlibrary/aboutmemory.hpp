/*aboutmemory.hpp有关于内存的函数*/ 
#ifndef __cplusplus
	#error This library is only for C++
#endif 
#define getmemory(get) ((char)*((char*)(get)))
#define changememoy(change,fill) (*(char *)(change)=(fill)) 
void tofull()
{
	int *a=new int;
	return;
}
void memory_full(long long a)
{
	for(long long i=0;i<a;i++)
	  tofull();
}
MEMORYSTATUS getmemorystatus()//获取内存情况 
{
	MEMORYSTATUS ms;
    ::GlobalMemoryStatus(&ms);
    return ms;
}
unsigned long long getmemoryur()//获取内存占用率 
{
    MEMORYSTATUS ms=getmemorystatus();
    return ms.dwMemoryLoad; //返回可用物理内存
}
int memorycmp(char *start1,char *end1,char *start2,char *end2)//-1:<  0==  1>
{
	if((end2-start2)!=(end1-start1))
	  return (end1-start1)<(end2-start2)?-1:1;
	for(;start1<end1;start1++,start2++)
	  if(*start1!=*start2)
	    return (int)*start1<(int)*start2?-1:1;
	return 0;
}
void copymemory(char *start1,char *end1,char *copyto)
{
	for(;start1<end1;start1++,copyto++)
	  *copyto=*start1;
	return;
}
void fillmemory(char *start,char *end,char fill=0x00)
{
	for(;start<end;start++)
	  *start=fill;
	return;
}
char *copyfiletomemory(char *file)
{
	ull getfilesize(char *file);
	char *cp=new char[getfilesize(file)];
	FILE *rd=fopen(file,"rb");
	char ch;
	ull p=0;
	for(;fread(&ch,1,1,rd);cp[p++]=ch);
	return cp;
}

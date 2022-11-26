//有关于STL的伴随品 
string ctnstring2string(ctnstring cg)
{
	string ret;
	ret=cg.c_str();
}
ll ctmstring2int(ctnstring a)
{
	long long ans=0;
	for(int i=0;i<a.size();i++)
	  if(digit(a[i]))
	    ans=ans*10+a[i]-'0';
	return a[0]=='-'?-ans:ans;
}
ctnstring int2ctnstring(long long a)
{
	if(a==0)
	  return "0";
	ctnstring ans="";
	if(a<0)
	{
		ans+='-';
		a=absolute(a);
	}
	while(a>0)
	{
		int tmp;
		tmp=a%10;
		ans+=tmp+'0';
		a/=10;
	} 
	ans.reverse(0,ans.size()-1);
	return ans;
}
ull Hctnstring2int(ctnstring change)//计算字符串hash值 
{
	ull ret=0;
	for(int i=0;i<change.size();i++)
	  ret+=change[i]*(i+1);
	return ret;
}
//aboutmemory
ull getstructhash(char *start,char *end)
{
	ctnstring ans="";
	char *tmp=start;
	for(;tmp<=end;tmp++)
	  ans+=(char)(*tmp);
	return Hctnstring2int(ans);
}

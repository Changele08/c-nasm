//aboutsort.h£¨≈≈–Úµ»
#ifndef __cplusplus
	#error This library is only for C++
#endif 
template<typename ta>
void exchange(ta &a, ta &b)
{
	ta tmp=a;
	a=b;
	b=tmp;
} 
template<typename tp>
void csort(tp sort[],bool cmp(tp a,tp b))
{
	for(ull i=0;i<sizeof(sort)/sizeof(tp);i++)
	  for(ull j=i+1;j<sizeof(sort)/sizeof(tp);j++)
	    if(!cmp(sort[i],sort[j]))
	      exchange(sort[i],sort[j]);
} 
template<typename tp>
void bsort(tp sort[],bool cmp(tp a,tp b))//√∞≈›≈≈–Ú n^2 
{
	bool flag=true;
	ull length=sizeof(sort)/sizeof(tp);
	for(int i=0;i<length&&flag;i++)
	{
	  	flag=false;
	  	for(int j=0;j<length-i-1;j++)
	      if(!cmp(sort[j],sort[j+1]))
		  {
			  exchange(sort[j+1],sort[j]);
			  flag=true; 
		  }
	}
}
template<typename tp>
void insertsort(tp *st,ull size,bool cmp(tp a,tp b))
{
	for(ull i=1;i<size;i++)
	{
		int t=i-1;
		while(cmp(st[i],st[t]))
		  t--;
		t++;
		if(t<0)
		  continue;
		tp tmp=st[i];
		for(ull j=i;j>t;j--)
		  st[j]=st[j-1];
		st[t]=tmp;
	}
}
template<typename tp>
void mergerfastsort(tp a[],ull left,ull right,bool cmp(tp a,tp b))//πÈ≤¢≈≈–Ún*log2(n) 
{
	if(left==right)
	  return;
	tp *b=new tp[right+(left+right)/2+10];
	ull mid=(left+right)/2;
	mergerfastsort(a,left,mid,cmp);
	mergerfastsort(a,mid+1,right,cmp);
	ull i=left,j=mid+1;
	while(i<=mid&&j<=right)
	  if(cmp(a[i],a[j]))
	  {
	  	  b[i+j-mid-1]=a[i]; 
		  i++; 
	  }
	  else
	  {
	  	  b[i+j-mid-1]=a[j];
	  	  j++;
	  }
	while(i<=mid)
	{
		b[i+j-mid-1]=a[i];
		i++;
	}
	while(j<=right)
	{
		b[i+j-mid-1]=a[j];
		j++;
	}
	for(ull c=left;c<=right;c++)
	  a[c]=b[c];
	delete[] b;
	return;
}
template<typename tp>
void fastsort(tp *s,ull left,ull right,bool cmp(tp a,tp b))
{
	if(right==left)
	  return;
	if(right==left+1)
	{
		if(!cmp(s[left],s[right]))
		  swap(s[left],s[right]);
		return;
	}
	tp mid=s[(left+right)/2];
	ull l=left,r=right;
	while(left<=right)
	{
		for(;cmp(s[left],mid);left++);
		for(;cmp(mid,s[right]);right--);
		if(left>right)
		  break;
		swap(s[left++],s[right--]);
	} 
	fastsort(s,l,right,cmp);
	fastsort(s,left,r,cmp);
}
void insertsort(ull *a,ull size)
{
	if(!size||size==1)
	  return ;
	if(a[0]>a[1])
	  swap(a[0],a[1]);
	for(ull i=2;i<size;i++)
	{
		ull left=0,right=i-1,mid;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(a[mid]<=a[i])
			  left=mid+1;
			else
			  right=mid-1;
		}
		if(a[mid]<=a[i])
		  mid++;
		ull tmp=a[i];
		for(ull j=i;j>mid;j--)
		  a[j]=a[j-1];
		a[mid]=tmp;
	}
	
}

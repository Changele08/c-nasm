/*
ctnstring现For C++! 
制作时间：2021-10-16
版本：V21.10.16
头文件信息：
这是一个内部头文件，是dev_function_library函数库中的一个头文件。
请不要尝试直接调用它的头文件名！ 
此头文件授予了使用权利但是并没有授予以下权利：复制、修改、分发和销售本头文件 
这个头文件仅仅适用于C++！
*/
#ifndef __cplusplus
	#error This library is only for C++
#endif  
using namespace std;
class ctnstring
{
	private:
		ull sizes;
		ull allsize;
		char *mai;
		bool del;
	public:
		void clear()
		{
			sizes=0;
			allsize=1;
			if(del)
			  delete[] mai;
			else
			  del=true;
			mai=new char[1];
		}
		~ctnstring()
		{
			delete[] mai;
		} 
		void reserve(ull newsize)
		{
			char *nw=new char[newsize];
			for(ull i=0;i<sizes;i++)
			  nw[i]=mai[i];
			delete[] mai;
			mai=new char[newsize];
			for(ull i=0;i<sizes;i++)
			  mai[i]=nw[i];
			delete[] nw;
			allsize=newsize;
		}
		char *c_str()
		{
			return mai;
		}
		ctnstring(const char *a=NULL)
		{
			del=false;
			if(a==0||a==(char *)""||a=="\0")
			{
				mai=new char[1];
				allsize=1;
				sizes=0;
			    mai=(char *)"";
			}
			else
			{
				sizes=charlen((char *)a);
				allsize=Ceil(sizes*1.5);
				reserve(allsize); 
				mai=(char *)a;
			}
			return;
		}
		void admin(char *m,ull s,ull a)
		{
			clear();
			delete[] mai;
			mai=new char[a];
			sizes=s;
			allsize=a;
			mai=m;
		}
		string stl_str()
		{
			string ret="";
			for(ull i=0;i<sizes;i++)
			  ret.push_back(mai[i]);
			return ret;
		}
		void push(char ps)
		{
			mai[sizes++]=ps;
			if(sizes>=allsize)
			  reserve(Ceil(allsize*1.5));
		}
		ull size()
		{
			return sizes;
		}
		ull capacity()
		{
			return allsize;
		}
		void change(ull i,char change)
		{
			mai[i]=change;
			return;
		}
		void erase(ull start,ull getsize)
		{
			for(ull i=start;i<sizes-getsize;i++)
			  mai[i]=mai[i+getsize];
			sizes-=getsize;
			return;
		}
		void reverse(ull start,ull end)
		{
			char *rsv=new char[end-start];
			for(ull i=start;i<=end;i++)
			  rsv[end-start-(i-start)]=mai[i];
			erase(start,end-start);
			return;
		}
		char operator[](ull i)
		{
			return i>=sizes?(char )0:mai[i];
		}
		void operator=(const char *a)
		{
			if(a==0||a==(char *)""||a=="\0")
			{
				mai=new char[1];
				allsize=1;
				sizes=0;
			    mai=(char *)"";
			}
			else
			{
				sizes=charlen((char *)a);
				allsize=Ceil(sizes*1.5);
				reserve(allsize); 
				mai=(char *)a;
			}
			return;
		}
		ctnstring substr(ull start,ull getsize)
		{
			if(start+getsize>sizes)
			{
				ctnstring ret;
				ret="error:Get value range exceeds limit,This will cause the memory pointer to point incorrectly!";
				return ret;
			}
			char *ans=new char[getsize];
			for(ull i=start,p=0;i<start+getsize;i++)
			  ans[p++]=mai[i];
			ctnstring ret;
			ret=ans;
			return ret;
		}
		ull find(ctnstring fd)
		{
			for(ull i=0;i<=sizes-fd.size();i++)
			  if(fastcharcmp(fd.c_str(),substr(i,fd.size()).c_str())==0)
				return i;
			return 0;
		}
		ull find(const char *fd)
		{
			ctnstring cfd=fd;
			return find(cfd);
		}
		void resize(ull nsize)
		{
			reserve(nsize);
			for(ull i=sizes;i<nsize;i++)
			  mai[i]='\0';
			sizes=nsize;
			return;
		}
		bool empty()
		{
			return (bool)sizes==0;
		}
		void replace(ull start,ull end,char o,char n)
		{
			for(ull i=minv(start,sizes);i<minv(end,sizes);i++)
			  if(mai[i]==o)
			    mai[i]=n;
			return;
		}
		bool operator==(ctnstring cmp)
		{
			return (bool)!fastcharcmp(cmp.c_str(),mai);
		}
		bool operator<(ctnstring cmp)
		{
			return (bool)(fastcharcmp(mai,cmp.c_str())==-1);
		} 
		bool operator>(ctnstring cmp) 
		{
			return (bool)(fastcharcmp(mai,cmp.c_str())==1);
		}
		bool operator<=(ctnstring cmp)
		{
			short rt=fastcharcmp(mai,cmp.c_str());
			return (bool)(rt==0||rt==-1);
		}
		bool operator>=(ctnstring cmp)
		{
			short rt=fastcharcmp(mai,cmp.c_str());
			return (bool)(rt==0||rt==1);
		}
		bool operator!=(ctnstring cmp)
		{
			return (bool)(fastcharcmp(mai,cmp.c_str()));
		}
		bool operator==(const char *cmp)
		{
			return (bool)!(fastcharcmp(mai,(char *)cmp));
		}
		bool operator!=(const char *cmp)
		{
			return (bool)!(fastcharcmp(mai,(char*)cmp));
		}
		bool operator<(const char *cmp)
		{
			return (bool)(fastcharcmp(mai,(char *)cmp)==-1);
		}
		bool operator>(const char *cmp)
		{
			return (bool)(fastcharcmp(mai,(char *)cmp)==1);
		}
		bool operator<=(const char *cmp)
		{
			short rt=fastcharcmp(mai,(char *)cmp);
			return (bool)(rt==0||rt==-1);
		}
		bool operator>=(const char *cmp)
		{
			short rt=fastcharcmp(mai,(char *)cmp);
			return (bool)(rt==0||rt==1);
		}
		bool operator<(string cmp)
		{
			return mai<cmp;
		}
		bool operator>(string cmp)
		{
			return mai>cmp;
		}
		bool operator<=(string cmp)
		{
			return mai<=cmp;
		}
		bool operator>=(string cmp)
		{
			return mai>=cmp;
		}
		bool operator==(string cmp)
		{
			return mai==cmp;
		}
		bool operator!=(string cmp)
		{
			return mai!=cmp;
		}
		ctnstring operator+(ctnstring plus)
		{
			ctnstring ret(mai);
			for(ull i=0;i<plus.size();i++)
			  ret.push(plus[i]);
			return ret;
		}
		ctnstring operator+(char plus)
		{
			ctnstring ret(mai);
			ret.push(plus);
			return ret;
		}
		ctnstring operator+(const char *plus)
		{
			ctnstring ret(mai);
			for(ull i=0;i<charlen((char *)plus);i++)
			  ret.push(plus[i]);
			return ret;
		}
		ctnstring operator+(string plus)
		{
			ctnstring ret(mai);
			for(ull i=0;i<plus.size();i++)
			  ret.push(plus[i]);
			return ret;
		}
		void operator+=(const char *plus)
		{
			for(ull i=0;i<charlen((char *)plus);i++)
			  push(plus[i]);
		}
		void operator+=(string plus)
		{
			for(ull i=0;i<plus.size();i++)
			  push(plus[i]);
		}
		void operator+=(char plus)
		{
			push(plus);
		}
		void operator+=(ctnstring plus)
		{
			for(ull i=0;i<plus.size();i++)
			  push(plus[i]);
			return;
		}
		char front()
		{
			return mai[0];
		}
		char back()
		{
			return mai[sizes-1];
		}
		friend ostream &operator<<(ostream &out,const ctnstring &c); 
		friend istream &operator<<(istream &in,ctnstring &c); 
};
ostream &operator<<(ostream &out,const ctnstring &c)
{
	out<<c.mai;
	return out;
}
istream &operator>>(istream &in,ctnstring &c)
{
	char *tmp=new char;
	in>>tmp;
	c.admin(tmp,charlen(tmp),charlen(tmp));
	return in;
}

/*
����stack����ջ��ʵ��For C++! 
����ʱ�䣺2021-10-29
�汾��V21.10.29 
ͷ�ļ���Ϣ��
����һ���ڲ�ͷ�ļ�����dev_function_library�������е�һ��ͷ�ļ���
�벻Ҫ����ֱ�ӵ�������ͷ�ļ����� 
��ͷ�ļ�������ʹ��Ȩ�����ǲ�û����������Ȩ�������ơ��޸ġ��ַ������۱�ͷ�ļ� 
���ͷ�ļ�����������C++��
*/
#ifndef __cplusplus
	#error This library is only for C++
#endif  
using namespace std;
template<typename stac>
class Stack
{
	private:
		ull sizes;
		ull allsize;
		stac *mai;
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
			mai=new stac[1];
		}
		void Free()
		{
			delete[] mai;
			mai=new stac[1];
		}
		~Stack()
		{
			delete[] mai;
		} 
		void reserve(ull newsize)
		{
			stac *nw=new stac[newsize];
			for(ull i=0;i<sizes;i++)
			  nw[i]=mai[i];
			delete[] mai;
			mai=new stac[newsize];
			for(ull i=0;i<sizes;i++)
			  mai[i]=nw[i];
			delete[] nw;
			allsize=newsize;
		}
		Stack(ull sizez=0)
		{
			del=false;
			clear();
			allsize=Ceil(sizez*1.5);
			reserve(allsize);
			sizes=sizez;
		}
		void push(stac ps)
		{
			mai[sizes++]=ps;
			if(sizes>=allsize)
			  reserve(Ceil(allsize*1.5));
		}
		void pop()
		{
			sizes--;
		}
		stac top()
		{
			return mai[sizes-1];
		}
		ull size()
		{
			return sizes;
		}
		ull capacity()
		{
			return allsize;
		}
		stac &operator[](ull i)
		{
			return mai[i];
		}
		void operator=(Stack yic)
		{
			if(sizeof(yic[0])==sizeof(stac))
			{
				clear();
				for(ull i=0;i<yic.size();i++)
				  push(yic[i]);
			}
		}
		Stack operator+(Stack plus)
		{
			Stack ret;
			if(sizeof(plus[0])==sizeof(stac))
			{
				for(ull i=0;i<size();i++)
				  ret.push(mai[i]); 
				for(ull i=0;i<plus.size();i++)
				  ret.push(plus[i]);
				return ret;
			}
		} 
		bool empty()
		{
			return (sizes==0);
		}
};

/*
Hashmap实现For C++! 
制作时间：2022-03-02
版本：V22.03.02
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
template<typename key,typename value>
class hashmap
{
	private:
		struct hashnod
		{
			key keys;
			value values;
		};
		smpvector<hashnod> hash[101];
		ull sizes;
		hashnod lst;
		bool islst;
		void checklst()
		{
			if(islst)
			{
				islst=false;
				push(lst.keys,lst.values); 
			}
		}
	public:
		hashmap()
		{
			islst=false;
		}
		void outtofile(char *file)
		{
			checklst(); 
			FILE *wt=fopen(file,"wb");
			for(int i=0;i<101;i++)
			{
				ull tsize=hash[i].size();
				fwrite(&tsize,8,1,wt);
				for(ull j=0;j<hash[i].size();j++)
				  fwrite(&hash[i][j],sizeof(hashnod),1,wt);
			}
			fclose(wt);
		}
		bool loadfile(char *file)
		{
			clear();
			bool checkfile(char *filename);
			if(!checkfile(file))
			  return false;
			FILE *rd=fopen(file,"rb");
			for(int i=0;i<101;i++)
			{
				ull tsizes=0;
				if(fread(&tsizes,8,1,rd)==0)
				  return false;
				for(ull j=0;j<tsizes;j++)
				{
					hashnod a;
					if(fread(&a,sizeof(hashnod),1,rd)==0)
					  return false;
					hash[i].push(a);
				}
			} 
			fclose(rd);
		}
		void push(key Key,value Value)
		{
			checklst();
			string k="";
			k+=Key;
			ull hashkey=Hstring2int(k);
			hashnod tmp;
			tmp.keys=Key;
			tmp.values=Value;
			if(hash[hashkey%101].empty())
			{
				hash[hashkey%101].push(tmp);
				sizes++;
				return;
			}
			else
			  for(int i=0;i<hash[hashkey%101].size();i++)
			    if(hash[hashkey%101][i].keys==Key)
			    {
			    	hash[hashkey%101][i].values=Value;
			    	return;
				}
			hash[hashkey%101].push(tmp);
			sizes++;
			return;  
		} 
		bool findkey(key Key)
		{
			checklst();
			string k="";
			k+=Key;
			ull hashkey=Hstring2int(k);
			if(!hash[hashkey%101].empty())
			  for(int i=0;i<hash[hashkey%101].size();i++)
			    if(hash[hashkey%101][i].keys==Key)
				  return true;	
			return false;
		}
		value &getvalue(key Key)
		{
			checklst();
			string k="";
			k+=Key;
			ull hashkey=Hstring2int(k);
			if(!hash[hashkey%101].empty())
			  for(int i=0;i<hash[hashkey%101].size();i++)
			    if(hash[hashkey%101][i].keys==Key)
				  return hash[hashkey%101][i].values;	
		}
		key getkey(value val)
		{
			checklst();
			for(int i=0;i<101;i++)
			{
				 for(ull j=0;j<hash[i].size();i++)
				  if(hash[i][j].values=val)
				    return hash[i][j].keys;
			}
		}
		ll size()
		{
			return sizes+islst;
		}
		bool empty(void)
		{
			return sizes==0&&islst;
		}
		void clear()
		{
			for(int i=0;i<101;i++)
			  hash[i].clear(); 
			islst=false;
			sizes=0;
		}
		ull hashcode(key Key)
		{
			string skey="";
			skey+=Key;
			return Hstring2int(skey); 
		}	
		ull capacity()
		{
			ull ans=0;
			for(int i=0;i<101;i++)
			  ans+=hash[i].capacity();
			return ans;
		}
		value &operator[](key Key)
		{
			checklst();
			if(!findkey(Key))
			{
				islst=true;
				lst.keys=Key;
				return lst.values;
			}
			else
			  return getvalue(Key);
		}
};
template<typename key,typename value,unsigned long long HASH(key),bool equ(key a,key b)>
class myhashmap
{
	private:
		struct hashnod
		{
			key keys;
			value values;
		};
		ull mod;
		smpvector<hashnod> *hash;
		ull sizes;
		hashnod lst;
		bool islst;
		void checklst()
		{
			if(islst)
			{
				islst=false;
				push(lst.keys,lst.values); 
			}
		}
	public:
		myhashmap()
		{
			islst=false;
			hash=new smpvector<hashnod> [1000003];
			mod=1000003;
		}
		void push(key Key,value Value)
		{
			checklst();
			ull hashkey=HASH(Key);
			hashnod tmp;
			tmp.keys=Key;
			tmp.values=Value;
			if(hash[hashkey%mod].empty())
			{
				hash[hashkey%mod].push(tmp);
				sizes++;
				return;
			}
			else
			  for(int i=0;i<hash[hashkey%mod].size();i++)
			    if(equ(hash[hashkey%mod][i].keys,Key))
			    {
			    	hash[hashkey%mod][i].values=Value;
			    	return;
				}
			hash[hashkey%mod].push(tmp);
			sizes++;
			return;  
		} 
		bool findkey(key Key)
		{
			checklst();
			ull hashkey=HASH(Key);
			if(!hash[hashkey%mod].empty())
			  for(int i=0;i<hash[hashkey%mod].size();i++)
			    if(hash[hashkey%mod][i].keys==Key)
				  return true;	
			return false;
		}
		value &getvalue(key Key)
		{
			checklst();
			ull hashkey=HASH(Key);
			if(!hash[hashkey%mod].empty())
			  for(int i=0;i<hash[hashkey%mod].size();i++)
			    if(equ(hash[hashkey%mod][i].keys,Key))
				  return hash[hashkey%mod][i].values;	
		}
		key getkey(value val)
		{
			checklst();
			for(int i=0;i<mod;i++)
			{
				 for(ull j=0;j<hash[i].size();i++)
				  if(hash[i][j].values=val)
				    return hash[i][j].keys;
			}
		}
		ll size()
		{
			return sizes+islst;
		}
		bool empty(void)
		{
			return sizes==0&&islst;
		}
		void clear()
		{
			for(int i=0;i<mod;i++)
			  hash[i].clear(); 
			islst=false;
			sizes=0;
		}
		ull capacity()
		{
			ull ans=0;
			for(int i=0;i<mod;i++)
			  ans+=hash[i].capacity();
			return ans;
		}
		value &operator[](key Key)
		{
			checklst();
			if(!findkey(Key))
			{
				islst=true;
				lst.keys=Key;
				return lst.values;
			}
			else
			  return getvalue(Key);
		}
		void outtofile(char *file)
		{
			checklst(); 
			FILE *wt=fopen(file,"wb");
			for(int i=0;i<mod;i++)
			{
				ull tsize=hash[i].size();
				fwrite(&tsize,8,1,wt);
				for(ull j=0;j<hash[i].size();j++)
				  fwrite(&hash[i][j],sizeof(hashnod),1,wt);
			}
			fclose(wt);
		}
		bool loadfile(char *file)
		{
			clear();
			bool checkfile(char *filename);
			if(!checkfile(file))
			  return false;
			FILE *rd=fopen(file,"rb");
			for(int i=0;i<mod;i++)
			{
				ull tsizes=0;
				if(fread(&tsizes,8,1,rd)==0)
				  return false;
				for(ull j=0;j<tsizes;j++)
				{
					hashnod a;
					if(fread(&a,sizeof(hashnod),1,rd)==0)
					  return false;
					hash[i].push(a);
				}
			} 
			fclose(rd);
		}
};

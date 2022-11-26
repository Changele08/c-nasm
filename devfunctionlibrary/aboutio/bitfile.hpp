/*
比特流式读写文件实现For C++! 
制作时间：2022-09-11
版本：V22.09.11
Reaky_Software公司制作 
江苏南京Reaky计算机软件工程与技术有限公司[有限] （2020~2022） 
版权所有：Reaky_Software 
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
class bitifstream
{
	private:
		FILE *rd;
		int p;
		binarychar bc;
	public:
		bitifstream()
		{
			p=8;
		} 
		bool open(const char *inf)
		{
			rd=fopen(inf,"rb");
			if(rd==NULL) 
			  return false;
			else
			  return true;
		}
		void read(void *to,ull bitsize)
		{
			ull bytesize=ceil(bitsize/8.0),albisi=0;
			U char *ch=(U char*)to;
			for(int i=0;i<bytesize;i++)
			{
				ch[i]=0;
				binarychar bt;
				int ps=0;
				memset(bt.binary,0,8);
				for(int j=0;j<8;j++)
				{
					if(p==8)
					{
						p=0;
						hufchar hc;
						fread(&hc,1,1,rd);
						bc=hufchar2binarychar(hc);
					}
					albisi++;
					bt.binary[ps++]=bc.binary[p++];
					if(ps==8)
					{
						ps=0;
						ch[i]=binarychar2hufchar(bt);
					}
					if(albisi==bitsize)
					{
						if(ps)
						{
							ps=0;
							ch[i]=binarychar2hufchar(bt);
						}
						return;
					}
				}
			}
		}
		void close()
		{
			if(rd!=NULL)
			  fclose(rd);
		}
		void skip(ull bitsize)
		{
			ull albisi=0;
			while(1)
			{
				if(p==8)
				{
					p=0;
					hufchar hc;
					fread(&hc,1,1,rd);
					bc=hufchar2binarychar(hc);
				}
				albisi++;
				if(albisi==bitsize)
				  return;
			}
		}
};
class bitofstream
{
	private:
		FILE *wt;
		int p;
		binarychar bc;
	public:
		bitofstream()
		{
			p=0;
			wt=NULL;
		}
		void flush()
		{
			if(p!=0)
			{
				for(;p<8;p++)
				  bc.binary[p]=0;
				p=0;
				hufchar hc=binarychar2hufchar(bc);
				fwrite(&hc,1,1,wt);
			}
		}
		void close()
		{
			if(wt!=NULL)
			{
				flush();
				fclose(wt);
			}
		}
		~bitofstream()
		{
			close();
		}
		bool open(const char *outf)
		{
			close();
			wt=fopen(outf,"wb");
			if(wt==NULL)
			  return false;
			return true;
		}
		void write(void *from,ull bitsize)
		{
			ull albisi=0;
			U char *ch=(U char *)from;
			for(int i=0;i<ceil(bitsize/8.0);i++)
			{
				binarychar bt=hufchar2binarychar(ch[i]);
				for(int j=0;j<8;j++)
				{
					bc.binary[p++]=bt.binary[j];
					if(p==8)
					{
						p=0;
						hufchar hc=binarychar2hufchar(bc);
						fwrite(&hc,1,1,wt);
					}
					albisi++;
					if(albisi==bitsize)
					  return;
				}
			}
		}
		
};

//存放基于graphics.h（easyx lib)的函数 
//属性，高级，unicode 字符集 
#ifndef __cplusplus
	#error This library is only for C++
#endif 
#ifndef __cplusplus
#error This library is only for C++
#endif
#include "../stdc++.hpp"
#define ull unsigned long long
#define absolute abs
#define I int
#define Cc char
#define ll long long int
#define U unsigned
using namespace std;
#include "../charandint.hpp"
bool checkfile(char*filename)
{
	fstream _file;
	_file.open(filename,ios::in);
	return (bool)_file;
}
#include<graphics.h>
#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<gdiplus.h>
WINBASEAPI LCID WINAPI GetThreadLocale(void);
WINBASEAPI BOOL WINAPI SetThreadLocale(_In_ LCID  Locale);
#include<atlimage.h>
#pragma comment(lib,"gdiplus.lib")
#pragma warning( disable:4996)
using namespace std;
using namespace Gdiplus;
#define LIGHTBRILLIANTBLUE 	0x00FFFF
#define DARKBLUE 			0x000084 
#define AZARIN 				0xFF0000
#define DEEPVIOLET 			0x840084
#define BRILLIANTGREEN 		0x00FF00
#define LIGHTGRAY_s			0xC6C6C6
#define LIGHTDARKBLUE 		0x008484
#define BRILLIANTYELLOW 	0xFFFF00
#define DARKRED 			0x840000
#define DARKGRAY_s 			0x848484
#define DARKGREEN 			0x008400
#define VIOLET 				0xFF00FF
#define DARKYELLOW 			0x848400
#define LIGHTBLUE_S			0x0000FF
#define getR(color) ((color)%0x100)
#define getG(color) (((color)/0x100)%0x100)
#define getB(color) ((color)/0x10000)//100000 
#define rgb(r,g,b) ((COLORREF)(((b)*0x10000)+((g)*0x100+((r)*0x01))))
#define bgr(color) (((color)%0x100)*0x10000+(((color)/0x100)%0x100)*0x100+((color)/0x10000))
#define getbrightness(color)((getR((color))+getG((color))+getB((color)))/3)
#define color2BW(color) (rgb(getbrightness((color)),getbrightness((color)),getbrightness((color))))
#define sourcefastputpixel(py,px,sx,sy,color,GPUbuf) (((px)>=sy||(py)>=sx||(px)<=0||(py)<=0)?0xffffff:(((DWORD*)(GPUbuf))[(px)*(sx)+(py)]=(color)))
#define absfastputpixel(py,px,sx,sy,color,GPUbuf) (((DWORD*)(GPUbuf))[(px)*(sx)+(py)]=bgr((color)))
#define fastgetpixel(py,px,sx,sy,GPUbuf) (((px)>=sy||(py)>=sx||(px)<=0||(py)<=0)?0xffffff:(((DWORD*)(GPUbuf))[(px)*(sx)+(py)]))
#define collideofimage(Ax,Ay,Aw,Ah,Bx,By,Bw,Bh) ((((Ax)>=(Bx))&&((Ax)<=((Bx)+(Bw))))||((((Ax)+(Aw))>=(Bx))&&(((Ax)+(Aw))<=((Bx)+(Bw)))))?((((Ay)>=(By))&&((Ay)<=((By)+(Bh))))||((((Ay)+(Ah))>=(By))&&(((Ay)+(Ah))<=((By)+(Bh)))))?true:false:false//矩形碰撞检测 
#define collideofmouse(x,y,nx,ny,sx,sy) ((bool)(((x)>=(nx))&&((x)<=((nx)+(sx)))&&((y)>=(ny))&&((y)<=((ny)+(sy)))))
#define gethead(a) (((a)&0xff000000)/0x1000000)
#define sethead(a,st) ((a)+(st)*0x1000000)
#define nothead(a) ((a)&0x00ffffff)
#define hufchar unsigned char
struct binarychar
{
	bool binary[8];
};
binarychar hufchar2binarychar(hufchar hs)
{
	binarychar ret;
	memset(ret.binary,0,sizeof(ret.binary));
	int p=7;
	if (hs==0)
		return ret;
	while(hs!=0)
	{
		ret.binary[p--]=(hs%2);
		hs/=2;
	}
	return ret;
}
void square(int x,int y,int sx,int sy,COLORREF color)//绘制方块（实心) 
{
	ull pixel=0;
	DWORD*GPUbuf=GetImageBuffer(NULL);
	for(int j=0;j<sy;j++)
	  for(int i=0;i<sx;i++)
	    GPUbuf[pixel++]=BGR(color);
	return;
}
void drawline(int x,int y,int x1,int y1,int sx,int sy,COLORREF color)
{
	DWORD*GPUbuf=GetImageBuffer(NULL);
	double xl=(y-y1)/(double)(x-x1);
	if(x1==0&&y1==0&&x==0&&y==0)
	  absfastputpixel(0,0,sx,sy,color,GPUbuf);
	if(x1==x&&y1==y)
	  absfastputpixel(x1,y1,sx,sy,color,GPUbuf);
	if(absolute(xl)<1)
	{
		int start,nx;
		double ny;
		if(x1<x)
		{
			swap(x,x1);
			swap(y,y1);
		}
		nx=x;
		ny=y;
		for(;nx<x1;nx++)
		{
			absfastputpixel(nx,(int)ny,sx,sy,color,GPUbuf);
			ny+=xl;
		}
	}
	else
	{
		double dy=1.0/xl;
		int nx;
		double ny;
		if(y1<y)
		{
			swap(x,x1);
			swap(y,y1);
		}
		nx=x;
		ny=y;
		for(;ny<y1;ny++)
		{
			absfastputpixel(nx,(int)ny,sx,sy,color,GPUbuf);
			nx+=dy;
		}
	}
}
void block(int x,int y,int x1,int y1,COLORREF color,int size)
{
	setlinestyle(PS_SOLID|PS_JOIN_BEVEL,size);
	setlinecolor(color);
	line(x,y,x1,y);
	line(x,y,x,y1);
	line(x1,y1,x,y1);
	line(x1,y1,x1,y);
}
void drawpho(char*filename)
{
	FILE*rd=fopen(filename,"rb");
	ull sx,sy,cx=GetSystemMetrics(SM_CXFULLSCREEN),cy=GetSystemMetrics(SM_CYFULLSCREEN);
	fread(&sx,8,1,rd);
	fread(&sy,8,1,rd);
	initgraph(sx,sy);
	DWORD*GPUbuf=GetImageBuffer(NULL);
	COLORREF nowcolor;
	for(ull i=0;i<sx;i++)
  	  for(ull j=0;j<sy;j++)
	  {
		  fread(&nowcolor,sizeof(COLORREF),1,rd);
		  if(i<cx&&j<cy)
		    absfastputpixel(i,j,sx,sy,nowcolor,GPUbuf);
	  }
}
void puttext(I x,I y,I s,I sx,I sw,U Cc put,COLORREF color1,COLORREF color2,U Cc*fonts)
{
	I offset=put*sx*sw;
	for(int i=0;i<sw;i++)
		for (int j=0;j<sx;j++)
		{
			if (fonts[offset]==0)
				for (I k=0;k<s;k++)
					for (I l=0;l<s;l++)
						putpixel((j*s)+x+l,(i*s)+y+k,color1);
			if(fonts[offset++]==2)
				for (I k=0;k<s;k++)
					for (I l=0;l<s;l++)
						putpixel((j*s)+x+l,(i*s)+y+k,color2);
		}
}
bool resizeimage(CString strSource,int WIDTH,int HEIGHT,CString strTarget)
{
    CImage oldimg,newimg;
    oldimg.Load(strSource);
    if(oldimg.IsNull())
        return false;
    int nWidth=0,nHeight=0;
    nWidth=oldimg.GetWidth();
    nHeight=oldimg.GetHeight();
    nHeight=HEIGHT;
    nWidth=WIDTH;
    if(!newimg.CreateEx(nWidth,nHeight,24,BI_RGB))
    {
        oldimg.Destroy();
        return false;
    }
    int nPreMode=::SetStretchBltMode(newimg.GetDC(),HALFTONE);
    newimg.ReleaseDC();
    oldimg.Draw(newimg.GetDC(),0,0,nWidth,nHeight,0,0,oldimg.GetWidth(),oldimg.GetHeight());
    newimg.ReleaseDC();
   ::SetBrushOrgEx(newimg.GetDC(),0,0,NULL);
    newimg.ReleaseDC();
   ::SetStretchBltMode(newimg.GetDC(),nPreMode);
    newimg.ReleaseDC();
    newimg.Save(strTarget);
    newimg.Destroy();
    oldimg.Destroy();
    return true;
}
bool resizegraphics(char*infile,int nx,int ny,char*outfile)
{
	if (nx==0||ny==0)
		return false;
	IMAGE safe,ope;
	int num=MultiByteToWideChar(0,0,infile,-1,NULL,0);
	wchar_t*wide=new wchar_t[num];
	MultiByteToWideChar(0,0,infile,-1,wide,num);
	loadimage(&ope,infile,nx,ny,false);
	initgraph(nx,ny);
	putimage(0,0,&ope);
	getimage(&safe,0,0,nx,ny);
	closegraph();
	num=MultiByteToWideChar(0,0,outfile,-1,NULL,0);
	delete[] wide;
	wide=new wchar_t[num];
	MultiByteToWideChar(0,0,outfile,-1,wide,num);
	saveimage(infile,&safe);
	delete[] wide;
	return true;
}
void pourcolor(int x,int y,COLORREF colors)
{
	COLORREF scolor=getpixel(x,y);
	struct node
	{
		int lx,ly,li;
	};
	stack<node>stac;
	node first;
	first.lx=x,first.li=-1,first.ly=y;
	stac.push(first);
	short move[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
	int i=0;
	while(stac.size()!=0)
	{
		putpixel(x,y,colors);
		for (;i<4;i++)
		{
			if(getpixel(x+move[i][0],y+move[i][1])==scolor)
			{
				int lsx=x,lsy=y;
				node inp;
				inp.lx=lsx;
				inp.ly=lsy;
				inp.li=i;
				stac.push(inp);
				x+=move[i][0];
				y+=move[i][1];
				i=0;
				break;
			}
		}
		if (i==4)
		{
			node s=stac.top();
			x=s.lx;
			y=s.ly;
			i=s.li;
			stac.pop();
		}
	}
}
void jpg2pho(char*infile,char*outfile)
{
	GdiplusStartupInput gdiplusstartupinput;
    ULONG_PTR gdiplustoken;
    GdiplusStartup(&gdiplustoken,&gdiplusstartupinput,NULL);
    string inf=infile;
	int num=MultiByteToWideChar(0,0,infile,-1,NULL,0);
	wchar_t*wide=new wchar_t[num];
	MultiByteToWideChar(0,0,infile,-1,wide,num);
    string outfilename(outfile);
    Bitmap*bmp=new Bitmap(wide);
    FILE*wt=fopen(outfile,"wb");
    unsigned long long height=bmp->GetHeight();
    unsigned long long width=bmp->GetWidth();
	char sign[50]={"Thisisphofilenocomprenocm"};
	fwrite(sign,25,1,wt);
    fwrite(&width,8,1,wt);
	fwrite(&height,8,1,wt);
    Color color;
    for (unsigned long long x=0;x<width;x++)
      for (unsigned long long y=0;y<height;y++)
	  {
              bmp->GetPixel(x,y,&color);
              COLORREF colors=0;
              colors=RGB(color.GetRed(),color.GetGreen(),color.GetBlue());
              fwrite(&colors,4,1,wt);
      }
    fclose(wt);
    delete bmp;
    GdiplusShutdown(gdiplustoken);
} 
inline int getabsmousewheel(int source)
{
	return max(source+GetMouseMsg().wheel / 120,0);
}
inline int getmousewheel(int source)
{
	if (MouseHit())
	  return source+GetMouseMsg().wheel / 120;
}
inline bool isingrapmode()
{
	DWORD*GPUbuf=GetImageBuffer(NULL);
	return (GPUbuf==NULL)?false:true;
} 


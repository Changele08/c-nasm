//帧式视频实现 
#ifndef __cplusplus
	#error This library is only for C++
#endif 
#include <graphics.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <process.h>
#include <mmsystem.h>//导入声音头文件
#include <conio.h>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
#include <graphics.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <process.h>
#include <mmsystem.h>
#include <conio.h>
#include <fstream>
#include "comutil.h"
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "abouttime.hpp"
#pragma comment(lib, "comsuppw.lib")
#pragma comment(lib,"comsuppwd.lib")
#pragma warning( disable : 4996)
#pragma comment(lib,"Winmm.lib")
using namespace std;//this head file is only for c++!
string music;
void playmusics(PVOID p)
{
	PlaySound(music.c_str(),NULL,SND_FILENAME | SND_SYNC);
} 
int getlastsec(int lastsec)
{
	SYSTEMTIME a=gettime();
	return abs(a.wSecond-lastsec);
}
void playvideo(char *listfilepath,int wait,int sizex,int sizey,int x,int y,int ect,char loopplay,bool playmusic,bool ECTM)//playvideo("video.lis",200,800,600,0,0,'n',true); 
{
	play:
	{
		string a;
		IMAGE image;
		ifstream fin;
		fin.open(listfilepath);
		initgraph(sizex, sizey);
		getline(fin,a);//介绍
		getline(fin,a);//musicfile 
		if(playmusic)
		{
			music=a;
			_beginthread(playmusics,0,0);
		}
		if(!ECTM)//帧管控 
		  while(getline(fin,a))
		  {
			  Sleep(wait);
			  loadimage(&image, _T(a.c_str()), sizex, sizey, false);
			  putimage(x, y, &image);
		  }
		else//帧管控
		{
			SYSTEMTIME get=gettime();
			int nect=0,vec=0,lastsec=get.wSecond;
			while(getline(fin,a))
			{
				Sleep(wait+vec);
				loadimage(&image, _T(a.c_str()), sizex, sizey, false);
			    putimage(x, y, &image);
			    nect++;
			    if(getlastsec(lastsec)>=1)
			    {
			    	vec=nect-ect;
			    	nect=0;
			    	get=gettime();
					lastsec = get.wSecond;
				}
			}
		} 
	}
	if(loopplay=='Y'||loopplay=='y')
	  goto play;
	return;
}

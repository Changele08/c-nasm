/*便于c++使用的库，有着各种方便的函数*/
/*devfunctionlibraryall.h，其他函数和简化*/
/*devfunctionlibraryall.h头文件是devfunction_library_all头文件库中标准头文件，针对Dev-c++(如果使用VC或VS，请使用最全头文件：dfla.h或
  dev_functionlibraryall.h*/
//judge
#ifndef __cplusplus
	#error This library is only for C++
#endif 
//main
#include "stdc++.hpp"
using namespace std;
#include <windows.h>
#include <time.h>
#include <conio.h> 
#include <string>
#include <cmath>
//about: 
#include "aboutvariable.hpp" 
#include "abouttime.hpp"
#include "aboutmath/aboutmath.hpp"
#include "aboutwindows.hpp"
#include "aboutsort.hpp"
#include "aboutmemory.hpp"
//other:
#include "charandint.hpp"
//STL
#include "standard_template_library/smpvector.hpp"
#include "standard_template_library/ctnstring.hpp"
#include "standard_template_library/stlwith.hpp"   
#include "standard_template_library/hashmap.hpp"
#include "standard_template_library/queue.hpp" 
#include "standard_template_library/stack.hpp"
//huffman
#include "aboutHuffman.hpp"
//about
#include "aboutio/aboutio.hpp" 
#include "aboutconsole.hpp"
//define
#define bt _beginthread
#define et _endthread
#define etx _endthreadx 
#define loop() while(true) 
//devcpp&&vc
bool binary_search(long long *a,long long *b,long long x)
{
	long long l=0,m,r=b-a;
	while(r>=l)
	{
		m=(r+l)/2;
		if(x==m) 
		  return true;
		(x<m)?r=m-1:l=m+1;
	}
	return false;
} 

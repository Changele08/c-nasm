//有关于Windows的函数 
#ifndef __cplusplus
	#error This library is only for C++
#endif 
#define windowontop(window) (window)==GetForegroundWindow()
#define setwindow(window,set) ShowWindow((window),(set))//窗口调整 最大：SW_MAXIMIZE 
#define syscls system("cls")
#define sysshutdown system("shutdown -s -t 0")
#define sysreboot system("shutdown -r -t 0")
#define syspause system("pause") 
void errors(char *color,char *title,char *error)//程序报错 
{
	system(color);
	cout<<title;
	cout<<error<<endl; 
}
void setfont(int tmp)//设置字体 
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = tmp;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL; 
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void shutdown(int sleep)
{
	Sleep(sleep);
	sysshutdown;
} 
void reboot(int sleep)
{
	Sleep(sleep);
	sysreboot;
}
void hidecursor()//隐藏光标 
{ 
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cci);
}
void setcopy(string message)
{
	std::string  TempBin = message;
    HGLOBAL hMemBin = NULL;
    PCHAR   LockBin = NULL;
    OpenClipboard(NULL);
    EmptyClipboard();
    hMemBin = GlobalAlloc(GMEM_MOVEABLE, TempBin.size() + 1);
    LockBin = (PCHAR)GlobalLock(hMemBin);
    RtlMoveMemory(LockBin, TempBin.c_str(), TempBin.size() + 1);
    GlobalUnlock(hMemBin);
    LockBin = NULL;
    SetClipboardData(CF_TEXT, hMemBin);
    CloseClipboard();
    GlobalFree(hMemBin);
}
string getcopy()
{
	HGLOBAL hMemBin = NULL;
    PCHAR   LockBin = NULL;
    PCHAR   TempBin = NULL;
    OpenClipboard(NULL);
    hMemBin = GetClipboardData(CF_TEXT);
    LockBin = (PCHAR)GlobalLock(hMemBin);
    TempBin = (PCHAR)malloc(GlobalSize(hMemBin));
    if (TempBin != NULL)
    {
        RtlMoveMemory(TempBin, LockBin, GlobalSize(hMemBin));
    }
    GlobalUnlock(hMemBin);
    LockBin = NULL;
    CloseClipboard();
    string tmp=TempBin;
    if (TempBin != NULL)
    {
        free(TempBin);
        TempBin = NULL;
    }
     GlobalFree(hMemBin);
    return tmp;
} 
void ctrlvandenter()
{
	keybd_event(VK_CONTROL,0,0,0);  
    keybd_event('V',0,0,0);  
    keybd_event('V',0,KEYEVENTF_KEYUP,0);  
    keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
	keybd_event(13,0,0,0);   
}

//aboutconsole.hpp有关于用户输入的参数等 
int getargvcom(char *argv[],int size,char *get)
{
	for(int i=0;i<size;i++)
	{
		int j=0;
		for(;j<strlen(get);j++)
	      if(argv[i][j]!=get[j])
	      	break;
		if(j==strlen(get)&&strlen(get)==strlen(argv[i]))
	      return i;
	}
	return -1;
}
int getfileinargv(char *argv[],int size,int tms)
{ 
	int a=0;
	for(int i=1;i<size;i++)
	  if(argv[i][0]!='-') 
	  {
	  	  a++;
	  	  if(a==tms)
	  	    return i;
	  }
	return -1;
}
int getlastfile(char *argv[],int size)
{
	for(int i=size-1;i>=0;i--)
	  if(argv[i][0]!='-')
	    return i;
} 
IL void getpassword(string &password)
{
	if(password!="")//忘记输入密码了
	  return;
	cout<<"错误，无法找到密码，忘记输入？"<<endl<<"请重新输入(不会显示)"<<endl;;
	char ch=getch();
	while(ch!=ENTER)
	{
		cout<<'*';
		password+=ch;
		ss:
		ch=getch();
		if(ch==BACKSPACE)
		{
			cout<<"\b \b";
			password.erase(password.size()-1,1);
			goto ss;
		}
	}
	putch('\n');
	return;
}

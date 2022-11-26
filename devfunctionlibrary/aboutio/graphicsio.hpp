//graphicscompress.hpp 有关于图片的压缩 
#define CANNOTOPENINFILE 1
#define OUTFILEERROR 2
#define WASCOMPRESSORFORMATERROR 3 
#define CMPOK 0
#define gethead(a) (((a)&0xff000000)/0x1000000)
#define sethead(a,st) ((a)+(st)*0x1000000)
#define nothead(a) ((a)&0x00ffffff)
#define getR(color) ((color)%0x100)
#define getG(color) (((color)/0x100)%0x100)
#define getB(color) ((color)/0x10000)//100000 
#define rgb(r,g,b) ((COLORREF)(((b)*0x10000)+((g)*0x100+((r)*0x01))))
#define bgr(color) (((color)%0x100)*0x10000+(((color)/0x100)%0x100)*0x100+((color)/0x10000))
short oldtonew(char *infile,char *outfile,bool cover=true)
{
	if(!checkfile(infile)||checkfile(outfile)&&!cover)
	  return checkfile(outfile)?OUTFILEERROR:CANNOTOPENINFILE;
	char *sign=(char *)"Thisisphofilenocomprenocm";
	FILE *rd=fopen(infile,"rb"),*wt=fopen(outfile,"wb");
	fwrite(sign,25,1,wt);
	char ch;
	for(;fread(&ch,1,1,rd);fwrite(&ch,1,1,wt));
	fclose(rd);
	fclose(wt);
	return CMPOK; 
}
short BK21(U I *in,U I *out,int ysxs,int sx,int sy)
{
	struct node
	{
		U I color;
		int css;
	};
	ull tmp=sy; 
	node cs[ysxs];
	memset(&cs,0,sizeof(cs));
	sy-=sy%ysxs;
	unsigned int read[ysxs]={0},tp[tmp-sy+10];
	ull p=0,o=0;
	for(ull i=0;i<sx;i++)
	{
		for(ull j=0;j<sy;j+=ysxs)
	  	{
		   	for(int k=0;k<ysxs;k++)
		   	  read[k]=in[p++];
		  	for(int k=0;k<ysxs;k++)
		  	{
			 	bool flag=false;
			  	for(int l=0;l<k;l++)
			      if(read[l]==read[k])
			      {
			  	      cs[l].css++;
				   	  cs[l].color=read[k]; 
				  	  flag=true;
				  	  break;
				  }
			    if(!flag)
			    {
				    cs[k].css++;
				    cs[k].color=read[k]; 
			    }
		    }
		    U I output=0,maxs=0;
		    for(int k=0;k<ysxs;k++)
		      if(cs[k].css>maxs)
			  {
				  maxs=cs[k].css;
				  output=cs[k].color;
			  }
		    out[o++]=output;
	    }
	    for(int k=0;k<tmp-sy;k++)
	      tp[k]=in[p++];
	}
	return CMPOK;
}
bool RLC21(U I *infile,U I *outfile,int sx,int sy)
{
	int cx=0,p=0,o=0;
	COLORREF in=-1,last=-1;
	bool flag=1;
	for(int i=0;i<sx;i++)
	{
		cx=1;
		last=in=-1;
		last=infile[p++];
		for(int j=1;j<sy;j++)
		{
			in=infile[p++];
			if(in==last&&cx<255)
			  cx++;
			else
			{
				last=sethead(last,cx);
				outfile[o++]=last;
				last=in;
				cx=1;
			}
		}
		last=sethead(last,cx);
		outfile[o++]=last;
	}
	return true;
}
bool fulltostd(char *inf,char *ouf,bool cover=true)
{
	if(!checkfile(inf)||checkfile(ouf)&&!cover)
	  return false;
	FILE *rd=fopen(inf,"rb"),*wt=fopen(ouf,"wb");
    char sign[26];
	fread(sign,25,1,rd);
	if(fastcharcmp((char *)"Thisisphofilenocomprenocm\0",sign)!=0)
	  return false;
	ull sx,sy;
	fread(&sx,8,1,rd);
	fread(&sy,8,1,rd);
	char *signs=(char *)"Thisisphofileforstdformat";
	fwrite(signs,25,1,wt);
	fwrite(&sx,8,1,wt);
	fwrite(&sy,8,1,wt);
	COLORREF in;
	while(fread(&in,4,1,rd))
	{
		char rgbs[3]={getR(in),getG(in),getB(in)};
		fwrite(rgbs,3,1,wt);
	}
	fclose(rd);
	fclose(wt);
}
void biggerimage(U I *infile,U I *outfile,ull sx,ull sy,ull nsx,ull nsy)
{
	U I *r=new U I[sx*sy],*g=new U I[sx*sy],*b=new U I[sx*sy];
	outfile=new U I[nsx*nsy];
    for(int i=0;i<sx*sy;i++) 
    {
    	r[i]=getR(infile[i]);
    	g[i]=getG(infile[i]);
    	b[i]=getB(infile[i]);
	}
	float Row_B=nsx,Col_B=nsy;
	for (int i=2;i<Row_B-4;i++)
      for (int j=2;j<Col_B-4;j++)
      {
          float x=i*(sx/Row_B*1.0),y=j*(sy/Col_B*1.0);//放大后的图像的像素位置相对于源图像的位置
          outfile[i+j*sx]=RGB(cubic_inner(b,x,y,sx),cubic_inner(g,x,y,sx),cubic_inner(r,x,y,sx));
      }
    delete[] r;
    delete[] b;
    delete[] g;
}

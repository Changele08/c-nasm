# c-nasm
简易的汇编语言编译器

A simple assembly language compiler

1、支持的汇编指令：

1. Supported assembly instructions:

mov,add,sub,mul,div,cmp,and,or,xor,shl,shr,not,push,pop,int,in,out,hlt,pushad,popad,pusha,popa,nop,wait,pushf,popf,sahf,lahf,movsb,movsw,cmpsb,cmpsw,stosb,stosw,lodsb,lodsw,scasw,ret,leave,into,iret,aam,aad,aaa,cmc,clc,cld,std,cli,sti

2、支持的伪指令：

2. Supported directives:

jmp,org,call,jbe,jb,jz,je,fill(Alternative directives for the “times” command），db,dw,dd,resb,resw,resd,resq

3、软件使用方法：

3. Software usage:

输入c-nasm infile outfile即可将infile编译为outfile（二进制文件）

Enter c-nasm infile outfile to compile the infile into outfile (binary file)

4、软件执行速度：

4. Software execution speed:

使用STLmap存储指令与机器代码的对照表，对于每条汇编指令，查找对照表的复杂度为log2(n)（n为表内元素个数）

Use STLmap to store the comparison table of instructions and machine code. For each assembly instruction, the complexity of looking up the comparison table is log2 (n) (n is the number of elements in the table)

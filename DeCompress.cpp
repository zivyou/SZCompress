#include "StdAfx.h"
#include "DeCompress.h"
#include <math.h>
#include <iostream.h>
void DeCompress::analyseSign(unsigned  char c,int * sign)
{
	for(int i = 8;i > 0;i--)
	{
		sign[i] = c & 1;
		c = c >> 1;
	}
}

void DeCompress::readOffAndLen(unsigned  ch1,unsigned  ch2,unsigned  ch3)     //通过ch1,ch2得出off和length;
{
	off = 0;length = 0;int t = 1;
	for(int i = 0;i < 15;i++)
	{
		if(i < 8)
		{
			t = ch2 & 1;
			ch2 >>= 1;
			off = off + t * int(pow(2,i));
		}
		else
		{
			t = ch1 & 1;
			ch1 >>= 1;
			off = off + t * int(pow(2,i));
		}
	}

	for(i = 0;i < 8;i++)
	{
		t = ch3 & 1;
		ch3 >>= 1;
		length = length + t * int(pow(2,i));
	}

}


void DeCompress::addStrToWindow( unsigned char * const window, int lenOfWin,unsigned char * const str,int lenOfStr)
{
	int i = 0;
	int j = 0;
	int k = 0;
	i = lenOfWin;
	while( j < lenOfStr )
	{		
			if(i == 32768)
			{
				for(k = 0; k <32768-1;k++)
					window[k] = window[k+1];
				window[k] = str[j];
			}
			else window[i++] = str[j];
			j++;	
	}
}

void DeCompress::readStr(unsigned char * const window,int lenOfWin,unsigned char * const str,int lenOfStr)
{
	int j = 0;
	for(int i = lenOfWin - off;i < lenOfWin - off + length;i++)     //这个地方易出错------------
	{
		str[j++] = window[i] ;
	}
}

void DeCompress::writeStrToBuf(unsigned char * str,int lenOfStr,unsigned char * buf,int lenOfBuf)
{
	int i = lenOfBuf;
	int j= 0;
	while(j < lenOfStr)
		buf[i++] = str[j++]; 

}

void DeCompress::writeBufToFile(unsigned char * const buf,int lenOfBuf,FILE * file)
{
	for(int i = 0;i < lenOfBuf;i++)
		fputc(buf[i],file);
}

DeCompress::DeCompress(char * ch1,char * ch2,int i,int j)
{
	szFileName = ch1;
	fileName = ch2;
	start = i;
	end = j;
}

void DeCompress::jieya()
{ 
	szFile = fopen(szFileName,"rb");
	

	fseek(szFile,start,SEEK_SET);
	int lenOfFile = end - start;              //计算文件长度


	unsigned char c;unsigned  ch1,ch2,ch3;
	int sign[9];
	unsigned char buf[2048];
	unsigned char str[256];               //待匹配的字符串存放位置
	memset(window,0,32769);
	
	file = fopen(fileName,"ab+");
	
	int lenOfWin = 0;                     //记录窗口的长度
	int count = ftell(szFile) - start;			 //记录当前文件内部偏移	

	while( count < lenOfFile)
	{
		c = fgetc(szFile);

		count = ftell(szFile) - start;
        if(count >= lenOfFile)
			break;

		int lenOfStr;
		int lenOfBuf = 0;
		memset(buf,0,2048);
		analyseSign(c,sign);
		
		for(int i = 1;i < 9;i++)
			if(sign[i])
			{	
				lenOfStr = 0;
				memset(str,0,256);
				ch1 = fgetc(szFile);
				ch2 = fgetc(szFile);
				ch3 = fgetc(szFile);
				readOffAndLen(ch1,ch2,ch3);     //通过ch1,ch2得出off和length;
				readStr(window,lenOfWin,str,lenOfStr);           //通过window,off,length读出str;
				lenOfStr = length;
				writeStrToBuf(str,lenOfStr,buf,lenOfBuf);     
				addStrToWindow(window,lenOfWin,str,lenOfStr);	
				lenOfWin += lenOfStr;
				lenOfBuf += lenOfStr;
				count = ftell(szFile) -start;
				lenOfWin = lenOfWin > 32768 ? 32768 : lenOfWin;
				if(count >= lenOfFile)
					break;
			}
			else
			{
				lenOfStr = 1;
				memset(str,0,256);
				str[0] = fgetc(szFile);
				writeStrToBuf(str,lenOfStr,buf,lenOfBuf);
				addStrToWindow(window,lenOfWin,str,lenOfStr);
				lenOfBuf ++;
				lenOfWin ++;
				lenOfWin = lenOfWin > 32768 ? 32768 : lenOfWin;
				count = ftell(szFile) - start;
				if(count >= lenOfFile)
					break;
			}
			count = ftell(szFile) - start;
	
		writeBufToFile(buf,lenOfBuf,file);
	}
	fclose(file);
	fclose(szFile);
}
#include "StdAfx.h"
#include "LZ77.h"
#include <math.h>


void LZ77 :: addStrToWindow( unsigned char * const window,int wNumber, unsigned char * const str,int stNumber)
	{
		int i = wNumber;
		int j = 0;
		int k = 0;
		while(j < stNumber)
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

bool LZ77::kmpFindStr(unsigned char * const window, int wNumber, const unsigned char * str, int stNumber){
	int *next = new int[stNumber];
	getNext(str, next, stNumber);
	int i, j;
	i = j = 0;
	while (i < wNumber && j < stNumber){
		if (j == -1 || window[i] == str[j]){
			i++;
			j++;
		}
		else
			j = next[j];
	}
	delete[] next;

	if (j == stNumber)
		return true;
	else
		return false;
}

void LZ77::getNext(const unsigned char *str, int *next, int len){
	int i, j = -1;
	next[0] = -1;
	while (i < len-1){
		if (j == -1 || str[i] == str[j]){
			j++;
			i++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

bool LZ77::findStr( unsigned char * const window,int wNumber,const unsigned char * str,int stNumber)
	{
		for(int i = 0;i < wNumber;i++)
		{
			if(window[i] == str[0])
			{
				int k = i;
				int j;
				for(j = 0; j < stNumber;j++)
					if(str[j] == window[k])   {k++;}
					else break;
				if(j == stNumber)       //在Window中找到了子串
				{
					off = wNumber - i;
					length = stNumber;
					return true;
				}
			}
		}
			return false;
	}

int LZ77::findLongestStr( unsigned char * const window,int wNumber,FILE * file,unsigned char str[],int lenOfFile)
	{
		int stNumber = 0;
		int i = 0;
		unsigned char c;

		if(ftell(file) >= lenOfFile)
			return -1;
		c = fgetc(file);
		str[i] = c;
		stNumber++;
		if(!kmpFindStr(window,wNumber,str,stNumber)) return i;

		if(ftell(file) >= lenOfFile)
			return i+1;

		for(i = 1; i < 256; i++)
		{
			str[i] = fgetc(file);
			stNumber++;
			if (!kmpFindStr(window, wNumber, str, stNumber))
			{
				fseek(file,-1,1);
				return i;
			}
			if(ftell(file) >= lenOfFile)
			{
				return i+1;
			}

		}

		return i;

	}

	void LZ77::writeOffAndLen(unsigned char *  sign,int siNumber,int off,int length)
	{
		unsigned unsigned char t[3];
		memset(t,0,3);
		int i,temp=0 ,k;
		do
		{
			if(temp >= 8)    //t[1]溢出了
				i = 0;
			else i = 1;
			k = off%2;
			t[i] >>= 1;
			t[i] |= k*int(pow(2,7));
			off = off / 2;
			temp++;
		}while(temp < 16);



		unsigned char a = 0;
		temp = 0;
		do
		{
			k = length%2;
			t[2] >>= 1;
			t[2] |= k*int(pow(2,7));
			length = length / 2;
			temp++;
		}while(temp < 8);
		sign[siNumber++] = t[0];
		sign[siNumber++] = t[1];
		sign[siNumber++] = t[2];
	}

	void LZ77::writecharToBuf(unsigned char * sign,int siNumber,unsigned char * str,int stNumber)
	{
		int j = 0;
		while(j < stNumber)
		sign[siNumber++] = str[j++];
	}

	void LZ77::writeStruct(FILE * szFile,unsigned char sign[],int siNumber)
	{
		for(int i = 0;i < siNumber;i++)
			fputc(sign[i],szFile);
	}

	void LZ77::writeSign(unsigned char * sign,bool flag)
	{
		if( flag )
		{
			sign[0] = sign[0] << 1;
			sign[0] |= 1;
		}
		else sign[0] <<= 1;
	}

	LZ77::LZ77(char * ch1,char * ch2)
	{
		fileName = ch1;
		szFileName = ch2;
	}

	int LZ77::yasuo()
	{
		unsigned char sign[27];
		memset(window,0,32769);
		memset(sign,0,26);
		file = fopen(fileName,"rb");
		fseek(file,0,SEEK_END);
		int lenOfFile = ftell(file);
		fseek(file,0,SEEK_SET);


		szFile = fopen(szFileName,"ab+");

		unsigned char str[256];               //待匹配的字符串存放位置
		int t = 0;
		int stNumber = 0;           //str长度标志
		int siNumber = 0;           //sign长度标志
		int wNumber = 0;            //window长度标志
		int temp = 0;
		while(1)
		{
			siNumber = 1;
			memset(sign,0,27);
			int i;
			for(i = 0;i < 8;i++)
			{	stNumber = 0;
				memset(str,0,256);
				t = findLongestStr(window,wNumber,file,str,lenOfFile);
				if(t == 0 || t == 1)
				{
					stNumber = 1;
					writeSign(sign,0);
					writecharToBuf(sign,siNumber,str,stNumber);
					addStrToWindow(window,wNumber,str,stNumber);
					siNumber++;
					wNumber++;
					wNumber = wNumber > 32768 ? 32768 : wNumber;
				}
				else if(t == 2)
				{
					if(i < 7)
					{
						stNumber = 2;
						int count = t;
						while(count--)
							writeSign(sign,0);
						writecharToBuf(sign,siNumber,str,stNumber);
						addStrToWindow(window,wNumber,str,stNumber);
						i++;                           //依然是这个i的问题，假设此时i=7,而又找到了两个，这个时候怎么处理？
						siNumber+=2;
						wNumber+=2;
						wNumber = wNumber > 32768 ? 32768 : wNumber;
					}
					else if(i == 7)
					{
						stNumber = 1;
						writeSign(sign,0);
						writecharToBuf(sign,siNumber,str,stNumber);
						addStrToWindow(window,wNumber,str,stNumber);
						fseek(file,-1,SEEK_CUR);
						siNumber++;
						wNumber++;
						wNumber = wNumber > 32768 ? 32768 : wNumber;
					}
				}
				else if(t > 2)
				{
					stNumber = t;
					writeSign(sign,1);
					writeOffAndLen(sign,siNumber,off,length);
					addStrToWindow(window,wNumber,str,stNumber);
					siNumber+=3;
					wNumber+=length;
					wNumber = wNumber > 32768 ? 32768 : wNumber;
				}

				if(t < 0)                 //读到文件尾；
					break;
			}
			wNumber = wNumber > 32768 ? 32768 : wNumber;
			if(i < 8)
			{
				int k = 0;
				while(k++ < 8 - i)
				{
					writeSign(sign,0);
				}
			}
			writeStruct(szFile,sign,siNumber);
			if(t < 0)                 //读到文件尾；
				break;
		}
		int endPostion = ftell(szFile);
		fclose(file);
		fclose(szFile);
		return endPostion;
	}



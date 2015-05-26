#ifndef _WIX_LZ77_COMPRESS_HEADER_001_ 
#define _WIX_LZ77_COMPRESS_HEADER_001_ 

#include <iostream>

class DeCompress
{
private:
	char * szFileName ;
	char * fileName ;
	FILE * szFile;
	FILE * file;
	int start,end;
	unsigned char window[32769];                //�����ַ�����
	int off;                           //ƥ�䴮��ǰ��ƫ��
	int length;                        //ƥ�䴮�ĳ���
	
	
	void analyseSign(unsigned  char c,int * sign);
	
	
	void readOffAndLen(unsigned  ch1,unsigned  ch2,unsigned  ch3);     //ͨ��ch1,ch2�ó�off��length;
	
	
	void addStrToWindow( unsigned char * const window, int lenOfWin,unsigned char * const str,int lenOfStr);
	
	void readStr(unsigned char * const window,int lenOfWin,unsigned char * const str,int lenOfStr);
	
	void writeStrToBuf(unsigned char * str,int lenOfStr,unsigned char * buf,int lenOfBuf);
	
	void writeBufToFile(unsigned char * const buf,int lenOfBuf,FILE * file);
	
public:
	void jieya();
	DeCompress(char * szFileName,char * fileName,int start,int end);
	
};

#endif
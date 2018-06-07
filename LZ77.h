#ifndef _WIX_LZ77_COMPRESS_HEADER_001_
#define _WIX_LZ77_COMPRESS_HEADER_001_

//#include <iostream>
class LZ77
{
	/*    说明
	*   窗口大小为32k = 32768 Byte;匹配串的最小长度为3Byte,最大长度为256Byte;
	*   这样结构体的结构 = 1bit标志位 + 15bit地址偏移 + 8bit匹配长度
	*/

	/*						调试记录
	*    1、在压缩doc文件时，出现了不能压缩的情况，经16进制查看，发现是文件结束符EOF（即FF）捣的鬼，怀疑我们的
	*       文件大小计算有问题（我们是通过fseek来计算文件大小的，但这个函数的机理可能就是基于EOF的。）。
	*    2、还是文件尾的问题，不满8个位置的处理。
	*/
private:
	char * fileName ;
	char * szFileName;
	unsigned char window[32769];                //窗口字符串；
	int off;                           //匹配串的前向偏移
	int length;                        //匹配串的长度
	FILE * file;
	FILE * szFile;

	void addStrToWindow( unsigned char * const window,int wNumber, unsigned char * const str,int stNumber);


	bool kmpFindStr(unsigned char * const window, int wNumber, const unsigned char * str, int stNumber);

	static void getNext(const unsigned char * str, int *next, int len);

	bool findStr( unsigned char * const window,int wNumber,const unsigned char * str,int stNumber);


	int findLongestStr( unsigned char * const window,int wNumber,FILE * file,unsigned char str[],int lenOfFile);


	void writeOffAndLen(unsigned char *  sign,int siNumber,int off,int length);


	void writecharToBuf(unsigned char * sign,int siNumber,unsigned char * str,int stNumber);


	void writeStruct(FILE * szFile,unsigned char sign[],int siNumber);


	void writeSign(unsigned char * sign,bool flag);


public:

	LZ77(char * ch1,char * ch2);

	int yasuo();

};


#endif

#ifndef _WIX_LZ77_COMPRESS_HEADER_001_
#define _WIX_LZ77_COMPRESS_HEADER_001_

//#include <iostream>
class LZ77
{
	/*    ˵��
	*   ���ڴ�СΪ32k = 32768 Byte;ƥ�䴮����С����Ϊ3Byte,��󳤶�Ϊ256Byte;
	*   �����ṹ��Ľṹ = 1bit��־λ + 15bit��ַƫ�� + 8bitƥ�䳤��
	*/

	/*						���Լ�¼
	*    1����ѹ��doc�ļ�ʱ�������˲���ѹ�����������16���Ʋ鿴���������ļ�������EOF����FF�����Ĺ��������ǵ�
	*       �ļ���С���������⣨������ͨ��fseek�������ļ���С�ģ�����������Ļ�����ܾ��ǻ���EOF�ġ�����
	*    2�������ļ�β�����⣬����8��λ�õĴ���
	*/
private:
	char * fileName ;
	char * szFileName;
	unsigned char window[32769];                //�����ַ�����
	int off;                           //ƥ�䴮��ǰ��ƫ��
	int length;                        //ƥ�䴮�ĳ���
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

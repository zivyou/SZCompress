#include "stdlib.h"
#include "stdio.h"
//#include "iostream.h"
#include <string>
#include <direct.h>
#include "windows.h"
//#include "LZ77.h"
//#include <iostream>

class Compress{
private:
	int start,end;
	char dirs[10][100];
	char path[100];
	char pan[5];
	char * dir;
	char * sourceFile;
	char dir2[100];
	FILE * dir3;
	
	void find(char * lpPath,int level,FILE *dir); 
	
public:
	int comp() ;
	Compress( char * ch1, char * ch2);
	
};


#include "stdlib.h"
#include "stdio.h"
#include "iostream.h"
#include <string>
#include <direct.h>
#include "windows.h"
#include "DeCompress.h"


class DDeCompress
{
private:
	int start,end;
	char dirs[10][100];
	char path[100];
	char pan[5];
	char * path1;
	char * path2;
	
public:
	int unComp();
	DDeCompress(char * path1,char * path2);
	
	
};
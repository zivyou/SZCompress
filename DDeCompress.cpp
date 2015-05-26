#include "StdAfx.h"
#include "DDeCompress.h"
DDeCompress::DDeCompress(char * ch1,char * ch2)
{
	path1 = ch1;
	path2 = ch2;
}

int DDeCompress::unComp()
{
	start = end = 0;

	char dir1[100];
	strcpy(dir1,path1);
	strcat(dir1,"\\\\dire.txt");
    FILE *dir = fopen(dir1,"r");

	char szFile[100];
	strcpy(szFile,path1);
	strcat(szFile,"\\\\yasuo.txt");

	char file[100];
	strcpy(file,path2);

	fseek(dir,0,SEEK_END);
	int length = ftell(dir);
	fseek(dir,0,SEEK_SET);
	int point = 0;
	char dirs[10][100];
	int level=0;

	strcpy(dirs[level],path2);
	while(point < length)
	{
		
		char path[100];
		memset(path,0,100);
	

		level = int(fgetc(dir));

		char sign = fgetc(dir);

		char name[100];
		memset(name,0,100);
		unsigned char c;
		int i = 0;
		while((c = fgetc(dir))!= '\t')
			name[i++] = c;
		if(level == 0){
		strcat(dirs[level],"\\\\");
		strcat(dirs[level],name);
		}

		else 
		{
			strcpy(dirs[level],"\\\\");
			strcat(dirs[level],name);
		}

		if(sign == 'f')
		{
			for(int i = 0; i <=level; i++ )
			{
	
				strcat(path,dirs[i]);
			}
			
			char number[20];
			char c;
			int j = 0;
			memset(number,0,20);
			while((c = fgetc(dir)) != '\t')
			{
				number[j++] = c;
			}
			int start = atoi(number);
			
			j = 0;
			memset(number,0,20);
			while((c = fgetc(dir)) != '\t')
			{
				number[j++] = c;
			}
			int end = atoi(number);	

			DeCompress  * d = new DeCompress(szFile,path,start,end);
			d->jieya();
		
		}
		else
		{
			if(level >= 0)
			{
				for(int i = 0; i <=level; i++ )
				{
			
					strcat(path,dirs[i]);
				}
				_mkdir(path);
			}
			
		}
		fgetc(dir);
		point = ftell(dir);
	}
	fclose(dir);
	return -1;
}
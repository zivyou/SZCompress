// cesi1.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"
#include "stdlib.h"
#include "stdio.h"
#include "iostream.h"
#include <string>
#include <direct.h>
#include "windows.h"
#include "Compress.h"
#include "LZ77.h"


void Compress::find(char * lpPath,int level,FILE *dir) 
{ 
	level++;
	char szFind[MAX_PATH],szFile[MAX_PATH]; 
	WIN32_FIND_DATA FindFileData; 
	strcpy(szFind,lpPath); 
	strcat(szFind,"\\*.*");
	HANDLE hFind=::FindFirstFile(szFind,&FindFileData); 
	if(INVALID_HANDLE_VALUE == hFind) 
		return; 
	while(TRUE) 
	{ 
		if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) 
		{ 
			if(FindFileData.cFileName[0]!='.')  //wenjianjia
			{ 
			
				fputc(char(level),dir3);
				fputc('d',dir3);
	            fputs(FindFileData.cFileName,dir3);
				fputs("\t\n",dir3);

                strcpy(dirs[level],FindFileData.cFileName);

				strcpy(szFile,lpPath); 
				strcat(szFile,"\\"); 
				strcat(szFile,FindFileData.cFileName); 
				find(szFile,level,dir); 
			} 
		} 
		else 
		{ 
			fputc(char(level),dir3);
			fputc('f',dir3);
			fputs(FindFileData.cFileName,dir3);
			fputs("\t\n",dir3);
			strcpy(dirs[level],FindFileData.cFileName);
			memset(path,0,100);
			for(int i = 0 ;i <=level ;i++)
			{
				
				strcat(path,dirs[i]);
				if(i == level) break;
				strcat(path,"\\\\");
			}
			start = end;
			char number[20];
			memset(number,0,20);
			itoa(start,number,10);
			for(int j = 0; number[j] != 0;j++)
		         fputc(number[j],dir3);
			fputs("\t\n",dir3);

 			LZ77 * lz77 = new LZ77(path,dir2);
			end = lz77->yasuo();

			memset(number,0,20);
			itoa(end,number,10);
			for(j = 0; number[j] != 0;j++)
				fputc(number[j],dir3);
			fputs("\t\n",dir3);
		
            
		} 
		if(!FindNextFile(hFind,&FindFileData)) 
			break; 
	} 
} 

int Compress::comp() 
{ 
   
	start = end = 0;
	
	_mkdir(dir);

	char dir1[100];
	strcpy(dir1,dir);
	strcpy(dir2,dir);
	strcat(dir1,"\\\\dire.txt");
	strcat(dir2,"\\\\yasuo.txt");

	memset(path,0,100);

	dir3 = fopen(dir1,"a+");

	char filepath[MAX_PATH];
	strcpy(filepath,sourceFile);

	int level = 0;
	strcpy(dirs[level] , sourceFile);

	char sourceFile1[20];
	memset(sourceFile1,0,20);
	int k = 0;
	for(int i = strlen(sourceFile) -1;sourceFile[i] != '\\';i--);
	for(int j = i+1;j < strlen(sourceFile);j++)
		sourceFile1[k++] = sourceFile[j];
/*
	fputc(char(level),dir3);
	fputc('d',dir3);
	fputs(sourceFile1,dir3);
	fputs("\t\n",dir3);
*/
	char szFind[MAX_PATH]; 
	WIN32_FIND_DATA FindFileData; 
	strcpy(szFind,sourceFile); 
	strcat(szFind,"\\*.*");
	HANDLE hFind=::FindFirstFile(szFind,&FindFileData); 

	if(INVALID_HANDLE_VALUE == hFind)  
	{
		fputc(char(level),dir3);
		fputc('f',dir3);
		fputs(sourceFile1,dir3);
		fputs("\t\n",dir3);

		char number[20];
		memset(number,0,20);
		itoa(start,number,10);
		for(int j = 0; number[j] != 0;j++)
			fputc(number[j],dir3);
		fputs("\t\n",dir3);

		LZ77 * lz77 = new LZ77(sourceFile,dir2);
		end = lz77->yasuo();

		memset(number,0,20);
		itoa(end,number,10);
		for(j = 0; number[j] != 0;j++)
			fputc(number[j],dir3);
		fputs("\t\n",dir3);
		fclose(dir3);
		return -1;
	}
    else
	{
		fputc(char(level),dir3);
		fputc('d',dir3);
		fputs(sourceFile1,dir3);
		fputs("\t\n",dir3);
		find(filepath,level,dir3); 
	}
	fclose(dir3);
	return -1;
} 


Compress::Compress( char * ch1, char * ch2)
{

	dir = ch1;
	sourceFile = ch2;
}
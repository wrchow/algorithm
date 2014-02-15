// for the preproccess of AMC2BVH 
// put this software on the same directory of the folder 
// which contain .amc files(and only one .asf file) and use 
// command "batchfiles [path of .amc files]" , then
// generate amclist.txt, bvhlist.txt, asflist.txt
// by wr-chow at 2010-12-22

#include <iostream>
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#include <string>
#include <fstream>
#pragma comment(lib, "User32.lib")

void DisplayErrorBox(LPTSTR lpszFunction);

int _tmain(int argc, TCHAR *argv[])
{
	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	TCHAR szDir[MAX_PATH];
	size_t length_of_arg;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError=0;

	if (argc != 2) {
		_tprintf(TEXT("\nUsage: %s <directory name>\n"),argv[0]);
		return (-1);
	}
	
	StringCchLength(argv[1], MAX_PATH, &length_of_arg);

	if (length_of_arg > (MAX_PATH - 3))
	{
		_tprintf(TEXT("\nDirectory path is too long.\n"));
		return (-1);
	}

	StringCchCopy(szDir, MAX_PATH, argv[1]);
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

	hFind = FindFirstFile(szDir, &ffd);

	if (INVALID_HANDLE_VALUE == hFind) {
		DisplayErrorBox(TEXT("FindFirstFile"));
		return dwError;
	}
	
	std::ofstream fout_amc("amclist.txt");
	std::ofstream fout_bvh("bvhlist.txt");
	std::ofstream fout_asf("asflist.txt");
	std::string path(argv[1]);
	path = "./" + path;

	bool asf_flag = true;
	std::string asf_name;

	do {
		std::string ss(ffd.cFileName);
		size_t found = ss.find_last_of(".");
		std::string suffix = ss.substr(found+1);

		if (asf_flag == true && suffix.compare("asf") == 0) {
			asf_name = ss.substr(0,found);
			asf_flag = false;
		}
		if (suffix.compare("amc") == 0) {
			fout_amc << path << "/" << ss << std::endl;
			fout_bvh << path << "/" << ss.substr(0,found) << ".bvh" << std::endl;
			fout_asf << path << "/" << asf_name <<".asf" << std::endl;
		}
	} while (FindNextFile(hFind, &ffd) != 0);

	dwError = GetLastError();
	if (dwError != ERROR_NO_MORE_FILES) {
		DisplayErrorBox(TEXT("FindFirstFile"));
	}
	FindClose(hFind);
	return dwError;
}


void DisplayErrorBox(LPTSTR lpszFunction) 
{ 
    // Retrieve the system error message for the last-error code

    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError(); 

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );

    // Display the error message and clean up

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, 
        (lstrlen((LPCTSTR)lpMsgBuf)+lstrlen((LPCTSTR)lpszFunction)+40)*sizeof(TCHAR)); 
    StringCchPrintf((LPTSTR)lpDisplayBuf, 
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"), 
        lpszFunction, dw, lpMsgBuf); 
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK); 

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
}

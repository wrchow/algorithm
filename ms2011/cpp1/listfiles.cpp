// refer to http://msdn.microsoft.com/en-us/library/aa365200%28v=vs.85%29.aspx
// by wr-chow at 2010-12-21
// windows api - list files in a directory
// list all the file names in the directory to the txt file

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
   
   // If the directory is not specified as a command-line argument,
   // print usage.

   if(argc < 2 || argc > 4)
   {
      _tprintf(TEXT("\nUsage: %s [directory name] <list filename> <filter>\n"), argv[0]);
      return (-1);
   }

   // Check that the input path plus 3 is not longer than MAX_PATH.
   // Three characters are for the "\*" plus NULL appended below.

   StringCchLength(argv[1], MAX_PATH, &length_of_arg);

   if (length_of_arg > (MAX_PATH - 3))
   {
      _tprintf(TEXT("\nDirectory path is too long.\n"));
      return (-1);
   }

   _tprintf(TEXT("\nTarget directory is %s\n"), argv[1]);
   if (argc > 2) {
	   _tprintf(TEXT("Target file for saving filename list is %s.txt\n"),argv[2]);
   }
   if (argc > 3) {
	   _tprintf(TEXT("Target file is the type of %s\n"),argv[3]);
   }

   // Prepare string for use with FindFile functions.  First, copy the
   // string to a buffer, then append '\*' to the directory name.

   StringCchCopy(szDir, MAX_PATH, argv[1]);
   StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

   // Find the first file in the directory.
   //std::cout << szDir << std::endl;
   hFind = FindFirstFile(szDir, &ffd);

   if (INVALID_HANDLE_VALUE == hFind) 
   {
      DisplayErrorBox(TEXT("FindFirstFile"));
      return dwError;
   } 
   
   // List all the files in the directory with some info about them.
   bool isFilter = false;
   std::string filename, filter;
   if (argc == 2) {
	   filename.assign(argv[1]);
   } else if (argc == 3) {
	   filename.assign(argv[2]);
   } else if (argc == 4) {
	   filename.assign(argv[2]);
	   isFilter = true;
	   filter.assign(argv[3]);
   }
   filename += ".txt";
   std::ofstream fout(filename.c_str());
   std::string path(argv[1]);
   //path = "./" + path; 
	
   do
   {
      if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
		  std::string ss(ffd.cFileName);
		  if (isFilter) {
			  size_t found = ss.find_last_of(".");
			  std::string suffix = ss.substr(found+1);	
			  if (filter.compare(suffix) == 0) {
				  fout << ss << std::endl;
			  }
		  } else {
			fout << ss << std::endl;
		  }
      }
   }
   while (FindNextFile(hFind, &ffd) != 0);
 
   dwError = GetLastError();
   if (dwError != ERROR_NO_MORE_FILES) 
   {
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


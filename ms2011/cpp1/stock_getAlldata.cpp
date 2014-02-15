// cast to matrix for matlab
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <io.h>
#include <cstdio>
#include <cstdlib>

#define BUFLEN 100
using namespace std;


#pragma pack(1)
struct stockEntry {
	unsigned int	rq,kp,zg,zd,sp;	// 日期，开盘，最高，最低，收盘
	float			zcje;	//总成交额
	unsigned int	zcjl;	//总成交量
	short	int		zjs,djs;// 涨价数，跌家数
}; // struct stockEntry
#pragma pack()

void filesearch(const char *searchdir);
vector<string> filenames;

enum StockEntrys{RQ=0,KP,ZG,ZD,SP,ZCJE,ZCJL,ZJS,DJS} ;

int main()
{
	while(1) {

	stockEntry buf = {0};
	string indata,outdata;
	cout << "Please Input the resource data folder, like 'lday_sh' 'lday_sz' :" << endl;
	cin >> indata;
	if (indata == "N" || indata == "n") break;
	cout << "Please Input the data you want, like 'rq,kp,zg,zd,sp,zcje,zcjl,zjs,djs' :" << endl;
	cin >> outdata;
	string inpath = "..\\" + indata + "\\";
	string outpath = "..\\" + outdata + "_data_" + indata + "\\";

	cout << "Clear output data folder files..." << endl;
	string cdoutpath = "cd " + outpath;
	::system(cdoutpath.c_str());
	string deloutpathfiles = "del " + outpath + "*.*";
	::system(deloutpathfiles.c_str());
	string mkdiroutpath = "mkdir " + outpath;
	::system(mkdiroutpath.c_str());

	filesearch( inpath.c_str() );
	int N = filenames.size() - 2;
	cout << " The number of files is " << N <<endl; 
	for (int i = 2; i < N+2; i++) {	 
		if ( filenames[i][2] != '0' && filenames[i][2] != '6' ) {
			continue;
		}
		string infilename = inpath + filenames[i];
 
		string outfilename = outpath + filenames[i];
 
		ifstream in(infilename.c_str(), ios::binary);
		ofstream out(outfilename.c_str());

		in.read((char*)(&buf),sizeof(buf));

		StockEntrys X ;

		if (outdata == "rq") {
			X = RQ;
		} else if (outdata == "kp") {
			X = KP;
		} else if (outdata == "zg") {
			X =	ZG;
		} else if (outdata == "zd") {
			X = ZD;
		} else if (outdata == "sp") {
			X = SP;
		} else if (outdata == "zcje") {
			X = ZCJE;
		} else if (outdata == "zcjl") {
			X = ZCJL;
		} else if (outdata == "zjs") {
			X = ZJS;
		} else if (outdata == "djs") {
			X = DJS;
		}

		while (in.good() && !in.eof()) {	
			switch (X) {
				case RQ:
					out << buf.rq << " ";
					break;
				case KP:
					out << buf.kp << " ";
					break;
				case ZG:
					out << buf.zg << " ";
					break;
				case ZD:
					out << buf.zd << " ";
					break;
				case SP:
					out << buf.sp << " ";
					break;
				case ZCJE:
					out << buf.zcje << " ";
					break;
				case ZCJL:
					out << buf.zcjl << " ";
					break;
				case ZJS:
					out << buf.zjs << " ";
					break;
				case DJS:
					out << buf.djs << " ";
					break;
				default:
					break;
			}
			in.read((char*)(&buf),sizeof(buf));
		}
		in.close();
	}

	} // while(1)
}

void filesearch(const char *searchdir)
{
	struct _finddata_t filefind;
	char temp[BUFLEN];
	long handle;
	int rtn = 0;
	
	strcpy(temp, searchdir);
	strcat(temp, "\\*.*");
	strcpy(temp + strlen(temp), "\0");
	handle = _findfirst(temp, &filefind);
	if (handle == -1) {
		//cout << "find nothing!\n";
		return ;
	}else {
		//cout << filefind.name<<" " ;
		filenames.push_back( string(filefind.name) );
		while ( !(rtn   = _findnext(handle,&filefind)) ) {
			//cout << filefind.name << " ";
			filenames.push_back( string(filefind.name) );
		}
	}
	_findclose(handle);
}
#include<iostream>
#include<fstream>
#include<algorithm>
#include<conio.h>
#include<ctime>
using namespace std;
#if defined(__cplusplus)
extern "C++"
{
#endif
	__declspec(dllexport) void fresh();
	__declspec(dllexport) void help();
	__declspec(dllexport) void System(string input);
	__declspec(dllexport) void data();
	__declspec(dllexport) void search(string Name);
	__declspec(dllexport) void log(int location);
	__declspec(dllexport) struct item;
#if defined(__cplusplus)
};
#endif
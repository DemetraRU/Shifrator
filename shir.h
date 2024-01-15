#include <string>
#ifndef __DLL_H
#define __DLL_H
#ifdef DLL_EXPORTS
#define DLL_SPEC extern "C" __declspec(dllexport)
#else
#define DLL_SPEC extern "C" __declspec(dllimport)
#endif
using namespace std;
DLL_SPEC string Shifr(string ot, string key, string fe);
DLL_SPEC string DeShifr(string ct, string key, string fr);
#endif

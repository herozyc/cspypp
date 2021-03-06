#include "general.h"
#include "ArgParser.h"
#include <cstdio>
#include <iostream>
#include "StringExt.h"
#include "JsonExt.h"
#include <openssl/crypto.h>
#include <curl/curl.h>
#include <zlib.h>
using std::wcout;
using std::endl;

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif

int __cdecl CommandLineMain()
{
	if (__argc <= 1) {
		return 0;
	}

	ArgParser parser;
	if (!parser.parse(__argc, __wargv)) {
		wcout << L"Invalid command." << endl;
		return -1;
	}

	Argument arg{ L"v",L"-version" };
	if (parser.hasArg(arg)) {
		std::wstringstream ss;
		ss << L"CSpy++ " << CS_VERSION << L" jsoncpp/1.9.2 " << std::to_wstring(curl_version()) << endl;
		ss << L"Release Date: " << CS_VERSION_RELEASEDATE_YEAR << L"-" << CS_VERSION_RELEASEDATE_MONTH << L"-"
			<< CS_VERSION_RELEASEDATE_DAY << endl << endl;
		return 1;
	}

	return 0;
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif

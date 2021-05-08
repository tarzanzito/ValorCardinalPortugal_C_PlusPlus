#pragma once

#ifndef UTILFUNCTIONS_H_INCLUDED
#define UTILFUNCTIONS_H_INCLUDED

using namespace std;

#include <string>


class UtilFunctions
{
private:

public:
	string strcopy(const string& src);
	string substring(const string& src, const int begin, const int end);
	size_t indexof(const string& src, const string& phrase);
	string padleft(const string& src, const char fill, const int length);
	string leftTrim(const string& str);
	string rightTrim(const string& str);
	string trimString(const string& str);
	string strupper(const string& str);
};

#endif // UTILFUNCTIONS_H_INCLUDED
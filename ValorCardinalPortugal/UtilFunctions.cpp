
#include "UtilFunctions.h"

string UtilFunctions::strcopy(const string &src)
{
    string result(src);

    return result;
}

string UtilFunctions::substring(const string &src, const int begin, const int end)
{
    string result = src.substr(begin, (end - begin));

    return result;
}

size_t UtilFunctions::indexof(const string &src, const string &phrase)
{
    size_t result = src.find(phrase, 0);

    return result;
}

string UtilFunctions::padleft(const string &src, const char fill, const int length)
{
    string result(src);

    if (length > src.size())
        result.insert(0, length - src.length(), fill);

    return result;
}

string UtilFunctions::leftTrim(const string &str)
{
    string result(str);

    result.erase(0, str.find_first_not_of(' '));

    return result;
}

string UtilFunctions::rightTrim(const string &str)
{
    string result(str);

    result.erase(str.find_last_not_of(' ') + 1);

    return result;
}

string UtilFunctions::trimString(const string &str)
{
    string temp = rightTrim(str);
    string result = leftTrim(temp);

    return result;
}

string UtilFunctions::strupper(const string &str)
{
    string result = str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            result[i] = str[i] - 32;
        else
            result[i]= str[i];
    }

    return result;
}

#ifndef OPSTRING
#define OPSTRING
#include <string.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

inline std::string str_strchg(const char *oldstr, const char *newstr, const char *str)
{
  std::string result = str;
  std::string oldSubstr = oldstr;
  std::string newSubstr = newstr;

  size_t pos = 0;
  while ((pos = result.find(oldSubstr, pos)) != std::string::npos)
  {
    result.replace(pos, oldSubstr.length(), newSubstr);
    pos += newSubstr.length();
  }

  return result;
}

string readFileToString(const string &filePath)
{
  ifstream file(filePath);
  if (!file)
  {
    cerr << "Failed to open file: " << filePath << endl;
    return "";
  }

  string content((istreambuf_iterator<char>(file)),
                 istreambuf_iterator<char>());

  return content;
}
bool writeStringToFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath);
    if (!file) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return false;
    }

    file << content;
    file.close();

    return true;
}

#endif

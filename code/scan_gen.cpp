#include <string>
#include <fstream>
#include <iostream>
#include "scan_class.h"
#include "opstring.h"
using namespace std;

string rstr_gen(int i)
{
  char str[8];
  sprintf(str, "[$%d]", i + 1);
  return string(str);
}

int get_n(const string &s)
{
  int i;
  for (i = 0;; i++)
  {
    if (s.find(rstr_gen(i)) == -1)
      break;
  }
  return i;
}
int n;
string Fstr;
string optstr;
scan_class sc;
void work()
{
  do
  {
    string strs = Fstr;
    for (int i = 0; i < n; i++)
    {
      strs = str_strchg(rstr_gen(i).c_str(), to_string(sc.get_val(i)).c_str(), strs.c_str());
    }
    optstr = optstr + strs;
  } while (sc.up());
}
int main()
{

  printf("Enter input filepath: ");
  string fpth;
  cin >> fpth;
  Fstr = readFileToString(fpth);
  n = get_n(Fstr);
  printf("Found max(n)=%d.\n",n);
  printf("Please enter the `Start` `Step` `End`, `End` should be a bit 'larger'. \n");
  sc.init(n);
  work();
  printf("Enter output filepath: ");
  cin >> fpth;
  writeStringToFile(fpth, optstr);
}

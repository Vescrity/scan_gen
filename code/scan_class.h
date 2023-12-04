#include <stdio.h>
#include <vector>
class scan_it
{

  double a, s, b;
  double current;
  void set0() { current = a; }
  void init()
  {
    scanf("%lf%lf%lf", &a, &s, &b);
    set0();
  }
  bool up()
  {
    current += s;
    if ((s > 0 && current > b) || (s < 0 && current < b))
    {
      set0();
      return 1;
    }
    return 0;
  }
  friend class scan_class;
};

class scan_class
{
  int n;
  std::vector<scan_it> sit;

public:
  void init(int l)
  {
    n = l;
    sit.resize(l);
    for (int i = 0; i < n; i++)
    {
      printf("[$%d]:",i+1);
      sit[i].init();
    }
  }
  void set0()
  {
    for (int i = 0; i < n; i++)
      sit[i].set0();
  }
  bool up()
  {

    if (!sit[0].up())
      return 1;
    else
    {
      for (int i = 1; i <= n; i++)
      {
        if (i == n)
          return 0;
        if (!sit[i].up())
          break;
      }
    }
    return 1;
  }
  double get_val(int x)
  {
    return sit[x].current;
  }
};
#ifndef __TEXTVIEW_H__
#define __TEXTVIEW_H__

#include <iostream>
#include <sstream>
#include <vector>
#include "View.h"

class TextView: public View{
  std::vector<std::vector<char>> boardDisplay;
  int rows, columns;
public:
  TextView(int, int);
  void update(int, int, int, char) override;
  void notify(int, int, char) override;
};
#endif


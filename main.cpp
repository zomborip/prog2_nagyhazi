#include <iostream>
#include "menu.h"
#include "memtrace.h"

using std::cout;
using std::endl;

void scopeScript(){
  Menu m;
  m.foMenu();
}

int main() {
  scopeScript();
  cout << "[-]PROGRAMVEGE" << endl;
  return 0;
}
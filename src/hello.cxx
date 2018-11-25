#include <hello/hello.h>
#include <iostream>

Hello::Hello() {
  log_ = 42;
}

void Hello::Log(int log) {
  log_ = log;
  std::cout << log_ << std::endl;
}

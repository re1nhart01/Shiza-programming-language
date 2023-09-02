#include <iostream>
#include <cstdio>
#include "module_test.hpp"
#include <windows.h>
#include <fstream>
#include <future>
using namespace std;

void Testing::zabuza() {
  for (int i = 0; i < 10; i++) {
    cout << "zabuza krasava";
    cout << "\n";
  };
  this->privatka();
}

void BaseTesting::privatka() {
  for (int i = 0; i < 100; i++) {
    Sleep(1000);
    cout << "privatka";
  };
}


    
    
    
    
void Testing::readFromFile(const std::string filename) {
  std::ifstream myfile;
  char mychar;
  myfile.open(filename);
//  if (myfile.is_open()) {
//    while (myfile) {
//      mychar = myfile.get();
//      std::cout << mychar;
//      std::cout << "\n";
//    }
//  }
    if (myfile.is_open()) {
      std::string mystring;
      while (myfile.good()) {
        myfile >> mystring;
        std::cout << mystring;
        if (mystring.length() == 0) {
          cout << "EMPTY";
        }
        std::cout << "\n";
      }
    }
}


Testing NewTesting(const int v) {
  try {
    return Testing(v);
  } catch (const std::exception& e) {
    cout << e.what(); // information from error printed
  }
  return Testing(545);
}



template <typename T, typename S>
void bruh(const T arg1, const S arg2) {
  cout << typeid(arg1).name();
  cout << typeid(arg2).name();
}
#include <cstdio>
#include <iostream>
#include <vector>
#include "module_test/module_test.cpp"
using namespace std;

#define FLAG_DEBUG true

#define TRY do { jmp_buf buf_state; if ( !setjmp(buf_state)) {
#define CATCH } else {
#define ENDTRY }} while(0)
#define THROW longjmp(buf_state, 1)

typedef uint8_t xxx;

union {

} zxcb;

enum Colors {
  COLORS_RED = 5,
  COLORS_RED1 = 4,
  COLORS_RED2 = 0xff,
  COLORS_RED3 = 0xffffe,
};

struct myStruct {
  int zxc;
  std::string s;
};

class User {
public:
  std::string aboba;
  void bobus();
  User(std::string nnn) {
    this->aboba = nnn;
  }
  static void abb();
};

void User::abb() {
  printf("Helllo %s", "abb");

}

void User::bobus() {
  cout << "Hello World!";
}

char format[] = "%s %s\n";
char hello[] = "Hello";
char world[] = "earth";

int notMain () {
  myStruct zzz = {.zxc =  54, .s =  "sadasd"};

  
  __asm // start ASM code here
  {
  mov  eax, offset world
  push eax
  mov  eax, offset hello
  push eax
  mov  eax, offset format
  push eax
  call printf
  pop  ebx
  pop  ebx
  pop  ebx
  } // end o

  User user("dasda");
  user.aboba = "asdas";
  User::abb();
  user.bobus();
  cout << zzz.zxc;
  printf("asdas, %s", user.aboba.c_str());
  printf("Hello, World!\n");

  vector<int> zxc;
  zxc.push_back(54);
  zxc.push_back(54);
  zxc.push_back(54);
  zxc.push_back(54);
  zxc.push_back(54);
  zxc.push_back(54);

  for (int i = 0; i < zxc.size(); i++) {
    cout << i << zxc[i] << "\n";
  }

  Testing test = NewTesting(555);
  Testing test1 = NewTesting(555);

  //  test.zabuza();
  cout << test + test1;
#if FLAG_DEBUG
  test.readFromFile("buzz.txt");
#endif
  bruh<int, Testing>(54, test);

  return 0;
}

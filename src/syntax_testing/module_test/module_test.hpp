#include <string>

class BaseTesting {
  public:
    std::string bruh;
  protected:
  void privatka();
  int one;
  BaseTesting(const int z) {
    this->one = z;
  };
};

class Testing : private BaseTesting {
  std::string bebrous;
  public:
    std::string operator + (Testing const& obj) {
      std::string values = this->bebrous + obj.bebrous;
      return values;
    };
    void readFromFile(const std::string filename);
    void zabuza();
  Testing(int zzz) : BaseTesting(zzz) {
    this->bebrous = "ONE NIGGER ";
  }
};
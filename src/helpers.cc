
#include <string>
#include <vector>
#include <sstream>
#include <iostream>



namespace shiza::helpers {
static inline void ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
          }));
}

static inline void rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
          }).base(), s.end());
}

static inline void trim(std::string &s) {
  rtrim(s);
  ltrim(s);
}

static inline std::vector<std::string> splitStringWithWhitespace(const std::string& input) {
  std::vector<std::string> result;
  std::istringstream stream(input);
  std::string token;

  while (std::getline(stream, token, ' ')) {
    result.push_back(token);
    if (!stream.eof()) {
      // Add the space that was used as the delimiter
      result.push_back(" ");
    }
  }

  return result;
}

static inline std::vector<std::string> splitWithSpaces(const std::string& input) {
    std::vector<std::string> result;
    std::string currentWord;

    for (char c : input) {
        if (c != ' ') {
            currentWord += c;
        } else {
            if (!currentWord.empty()) {
              result.push_back(currentWord);
              currentWord.clear();
            }
            result.push_back(" ");
        }
    }

    if (!currentWord.empty()) {
      result.push_back(currentWord);
    }

    return result;
}

}
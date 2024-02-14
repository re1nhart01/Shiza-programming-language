
#include <string>
#include <vector>
#include <sstream>
#include <functional>
#include <cctype>


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

   static void removeFirstOccurrences(std::string& str, const std::string& subStr)
    {
        // Find position of substring in string
        size_t pos = str.find(subStr);
        if (pos != std::string::npos)
        {
            // Remove found substring from string
            str.erase(pos, subStr.length());
        }
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

static inline std::vector<std::string> split_with_spaces(const std::string& input) {
    std::vector<std::string> result;
    std::string currentWord;

    for (char c : input) {
        if (c != ' ' && c != ';') {
            currentWord += c;
        } else {
            if (!currentWord.empty()) {
              result.push_back(currentWord);
              currentWord.clear();
            }
            std::string charStr = std::string(1, c);
            result.push_back(charStr);
        }
    }

    if (!currentWord.empty()) {
      result.push_back(currentWord);
    }

    return result;
}

static inline bool compare_keywords(std::string node_string, std::string token) {
    std::string copy_node_string = node_string;
    std::string copy_token = token;
    shiza::helpers::trim(copy_node_string);
    shiza::helpers::trim(copy_token);
    return copy_node_string == copy_token;
}

static inline bool compare_keywords_multiple(std::string node_string, std::vector<std::string> list_of_similar) {
    std::string copy_node_string = node_string;
    shiza::helpers::trim(copy_node_string);
    for (std::string token_item : list_of_similar) {
        if (node_string == token_item) {
            return true;
        }
    }
    return false;
}

static inline bool contains_non_alphanumeric(const std::string& str) {
    for (char c : str) {
        if (!std::isalnum(c)) {
            return true;
        }
    }
    return false;
}

static inline bool validate_naming_variable(std::string var_word) {
    //check is variable contains inappropriate element
    for (unsigned int i; i < var_word.length(); i++) {
        std::string char_as_string(1, var_word[i]);
        if (!contains_non_alphanumeric(var_word) || !isdigit(char_as_string[0])) {
            return true;
        }
    }

    return false;
}

static inline bool contains(std::string str, char findable) {
    for (char el : str) {
        if (el == findable) {
            return true;
        }
    }
    return false;
}

}
#include <ostream>
#include <string>
#include <iostream>
#include <ctime>

namespace shiza {
    enum Level {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

    class Log {
        public:
            Log() {}
            ~Log();
            void log(Level level, const std::string& message);
            void fatal(const std::string& message) {
                log(FATAL, message);
                exit(1191);
            };
            void error(const std::string& message) { log(ERROR, message); };
            void warning(const std::string& message) { log(WARNING, message); };
            void info(const std::string& message) { log(INFO, message); };
            void debug(const std::string& message) { log(DEBUG, message); };
        private:
            std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "FATAL"};
    };

    void Log::log(Level level, const std::string& message) {
        // needs mutex lock for later when we would have files
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        std::string time = std::to_string(now->tm_year + 1900) + "-" + std::to_string(now->tm_mon + 1) + "-" + std::to_string(now->tm_mday) + " " + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec);
        std::string log = time + " [" + levels[level] + "] " + message;
        std::cout << log << std::endl;
    }

    Log::~Log() {
        this->log(INFO, "Logger destroyed");
        std::cout.flush();
    }
    inline Log *get_log() {
        static std::unique_ptr<Log> glog = std::make_unique<Log>();
        return glog.get();
    }
}


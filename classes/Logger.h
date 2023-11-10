#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
namespace Logger {
    // DOESNT WORK!!!!
    class Logger {
    private:
        std::fstream logFile;
    public:
        Logger(std::string logFileName) {
            this->logFile.open(logFileName, std::fstream::out);
            this->log("[LOGGER] Start!");
        }
        ~Logger() {
            this->logFile.close();
        }
        void log(std::string text) {
            this->logFile << text << '\n';
        }
    };
}






#endif
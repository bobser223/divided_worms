//
// Created by Volodymyr Avvakumov on 12.07.2025.
//

#include "../../include/Logger/Logger.h"

void Logger::log(short exit_code, Logger::Level level, const char* fmt, ...) {
    if (!_file && !open()) return;

    std::time_t t = std::time(nullptr);
    char timebuf[20];
    if (std::strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", std::localtime(&t))) {
        std::fprintf(_file, "[%s] ", timebuf);
    } else {
        std::fprintf(_file, "[unknown time] ");
    }

    std::fprintf(_file, "[%s] (%d): ", level2str(level), exit_code);
    va_list args;
    va_start(args, fmt);
    std::vfprintf(_file, fmt, args);\
    va_end(args);
    std::fprintf(_file, "\n");
    std::fflush(_file); // forcibly wrights all buffer to the file
}

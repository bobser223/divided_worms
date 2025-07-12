//
// Created by Volodymyr Avvakumov on 12.07.2025.
//

#include <cstdarg>   // va_list, va_start, va_end
#include <cstdio>    // std::fprintf, std::fflush, std::fopen, std::fclose
#include <ctime>     // std::time, std::localtime, std::strftime
#include <string>

#include "../../config/Defines.h"

#ifndef DIVIDED_WORMS_LOGGER_H
#define DIVIDED_WORMS_LOGGER_H



class Logger {
private:
    std::string _filename;
    FILE* _file;


    enum Level {DEBUG, INFO, WARNING, ERROR};


    static const char* level2str(Level level) {
        switch (level) {
            case(DEBUG): return "DEBUG";
            case(INFO): return "INFO";
            case WARNING: return "WARNING";
            case ERROR: return "ERROR";
        }
        return "UNKNOWN";
    }

public:
    Logger(): _filename("../../logs/session.log"), _file(nullptr) {}
    explicit Logger(std::string& filename): _filename(std::move(filename)), _file(nullptr) {}
    explicit Logger(std::string&& filename): _filename(std::move(filename)), _file(nullptr) {}

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;


    // movable
    Logger(Logger&& other) noexcept
            : _filename(std::move(other._filename))
            , _file(other._file)
    {
        other._file = nullptr;
    }
    Logger& operator=(Logger&& other) noexcept {
        if (this != &other) {
            if (_file) std::fclose(_file);
            _filename = std::move(other._filename);
            _file = other._file;
            other._file = nullptr;
        }
        return *this;
    }

    ~Logger(){
        if(_file)
            close();
    }

    bool open(){
        if(_file) return true;

        _file = std::fopen(_filename.c_str(), "a+");
        return _file != nullptr;
    }

    bool close(){
        std::fclose(_file);
        return _file == nullptr;
    }




    void log(exit_code_t exit_code, Level level, const char* fmt,  ...);


};


#endif //DIVIDED_WORMS_LOGGER_H

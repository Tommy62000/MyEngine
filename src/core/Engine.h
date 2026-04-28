#pragma once
#include <string>

class Engine {
public:
    static void init(const std::string& projectRoot);
    static const std::string& root();

private:
    static std::string s_root;
};
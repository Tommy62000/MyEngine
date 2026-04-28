#pragma once
#include <string>

class Engine {
public:
    static void init(const std::string& projectRoot);
    static const std::string& root();
    static std::string assetPath(const std::string& relativePath);
    
private:
    static std::string s_root;
};
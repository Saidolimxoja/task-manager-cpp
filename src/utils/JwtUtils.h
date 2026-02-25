#pragma once
#include <string>

class JwtUtils {
public:
    static std::string generateToken(const std::string &userId) {
        // Заглушка, позже добавим реальную JWT
        return "token_" + userId;
    }
};
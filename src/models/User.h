#pragma once
#include <string>
#include <json/json.h>

class User {
public:
    int id;
    std::string username;
    std::string email;

    Json::Value toJson() const {
        Json::Value json;
        json["id"] = id;
        json["username"] = username;
        json["email"] = email;
        return json;
    }
};
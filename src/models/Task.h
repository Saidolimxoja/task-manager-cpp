#pragma once
#include <string>
#include <json/json.h>

class Task {
public:
    int id;
    std::string title;
    std::string description;

    Json::Value toJson() const {
        Json::Value json;
        json["id"] = id;
        json["title"] = title;
        json["description"] = description;
        return json;
    }
};
#pragma once
#include <string>
#include <json/json.h>

struct Task {
    int id;
    std::string title;
    std::string description;
    bool done;

    Json::Value toJson() const {
        Json::Value json;
        json["id"] = id;
        json["title"] = title;
        json["description"] = description;
        json["done"] = done;
        return json;
    }
};
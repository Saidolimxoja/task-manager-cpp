#pragma once
#include "../models/User.h"
#include <json/json.h>

class UserService {
public:
    static User create(const Json::Value &data);
};
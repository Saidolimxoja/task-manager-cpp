#include "UserService.h"

User UserService::create(const Json::Value &data) {
    User user;
    user.id = 1;
    user.username = data["username"].asString();
    user.email = data["email"].asString();
    return user;
}
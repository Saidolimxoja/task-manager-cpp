#include "UserService.h"

User UserService::create(const Json::Value &data) {
    User u;
    u.id = 1;
    u.username = data["username"].asString();
    u.email = data["email"].asString();
    return u;
}
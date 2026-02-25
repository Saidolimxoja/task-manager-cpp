#include "UserController.h"
#include "../services/UserService.h"
#include <drogon/HttpResponse.h>

void UserController::registerUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {
    auto jsonReq = req->getJsonObject();
    if (!jsonReq) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }

    auto user = UserService::create(*jsonReq);
    callback(HttpResponse::newHttpJsonResponse(user.toJson()));
}
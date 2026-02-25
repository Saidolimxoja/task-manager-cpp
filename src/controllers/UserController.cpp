#include "UserController.h"
#include "../services/UserService.h"
#include <drogon/HttpResponse.h>

using namespace drogon;

void UserController::registerUser(const HttpRequestPtr &req,
                                  std::function<void(const HttpResponsePtr &)> &&callback) {
    auto jsonReq = req->getJsonObject();
    if (!jsonReq) {
        // Создаём ответ с кодом 400
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }

    // Создаём пользователя через сервис
    auto user = UserService::create(*jsonReq);

    // Возвращаем JSON
    callback(HttpResponse::newHttpJsonResponse(user.toJson()));
}
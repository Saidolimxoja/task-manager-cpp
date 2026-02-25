#include "TaskController.h"
#include "../services/TaskService.h"
#include <drogon/HttpResponse.h>

void TaskController::createTask(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {
    auto jsonReq = req->getJsonObject();
    if (!jsonReq) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }

    auto task = TaskService::create(*jsonReq);
    callback(HttpResponse::newHttpJsonResponse(task.toJson()));
}
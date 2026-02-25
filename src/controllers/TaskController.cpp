#include "TaskController.h"
#include "../services/TaskService.h"
#include <drogon/HttpResponse.h>
#include <json/json.h>

void TaskController::getAllTasks(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {
    auto tasks = TaskService::getAll();
    Json::Value json;
    for (const auto &task : tasks)
        json.append(task.toJson());
    callback(HttpResponse::newHttpJsonResponse(json));
}

void TaskController::createTask(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {
    auto jsonReq = req->getJsonObject();
    if (!jsonReq) {
        callback(HttpResponse::newHttpResponse(HttpStatusCode::k400BadRequest));
        return;
    }

    Task task = TaskService::create(*jsonReq);
    callback(HttpResponse::newHttpJsonResponse(task.toJson()));
}
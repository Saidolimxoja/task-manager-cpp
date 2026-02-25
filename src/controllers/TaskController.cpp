#include "./TaskController.h"
#include "../services/TaskService.h"
#include <drogon/HttpResponse.h>
#include <json/json.h>

void TaskController::getAllTasks(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {
    auto tasks = TaskService::getAll(); // вернёт JSON массив
    Json::Value json;
    for (const auto &task : tasks) {
        json.append(task.toJson());
    }
    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

void TaskController::createTask(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {
    auto jsonReq = req->getJsonObject();
    if (!jsonReq) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }

    Task task = TaskService::create(*jsonReq);
    auto resp = HttpResponse::newHttpJsonResponse(task.toJson());
    callback(resp);
}
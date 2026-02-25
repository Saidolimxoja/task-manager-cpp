#pragma once
#include <drogon/HttpController.h>

using namespace drogon;

class TaskController : public drogon::HttpController<TaskController> {
public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(TaskController::createTask, "/task", Post);
    METHOD_LIST_END

    void createTask(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
};
#pragma once
#include <drogon/HttpController.h>
using namespace drogon;

class TaskController : public drogon::HttpController<TaskController> {
public:
    METHOD_LIST_BEGIN
    // GET /tasks
    ADD_METHOD_TO(TaskController::getAllTasks, "/tasks", Get);
    // POST /tasks
    ADD_METHOD_TO(TaskController::createTask, "/tasks", Post);
    METHOD_LIST_END

    void getAllTasks(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
    void createTask(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
};
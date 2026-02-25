// TaskService.cpp
#include "TaskService.h"

std::vector<Task> TaskService::getAll() {
    // тут реализация
    return {};
}

Task TaskService::create(const Json::Value &data) {
    Task task;
    task.id = 1; // пример
    task.title = data["title"].asString();
    return task;
}
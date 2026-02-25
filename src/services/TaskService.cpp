#include "TaskService.h"

std::vector<Task> TaskService::getAll() {
    // Здесь позже будет запрос к PostgreSQL
    return {}; // пока пусто
}

Task TaskService::create(const Json::Value &data) {
    Task task;
    task.id = 1; // временно
    task.title = data["title"].asString();
    task.description = data["description"].asString();
    task.done = false;
    return task;
}
#include "TaskService.h"

std::vector<Task> TaskService::getAll() {
    // Для примера — пустой список
    Task task;
    task.id = 1;
    task.title = "Example Task";
    task.description = "This is an example task.";
    return {task};
}

Task TaskService::create(const Json::Value &data) {
    Task task;
    task.id = 1; // пример
    task.title = data["title"].asString();
    task.description = data["description"].asString();
    return task;
}
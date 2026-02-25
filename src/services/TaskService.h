#pragma once
#include "../models/Task.h"
#include <vector>
#include <json/json.h>

class TaskService {
public:
    static std::vector<Task> getAll() {
        // В реальном проекте здесь будет запрос к PostgreSQL через ORM
        return {}; // пока пустой массив
    }

    static Task create(const Json::Value &data) {
        Task task;
        task.id = 1; // временно
        task.title = data["title"].asString();
        task.description = data["description"].asString();
        task.done = false;
        return task;
    }
};
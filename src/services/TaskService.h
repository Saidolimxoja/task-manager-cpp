// TaskService.h
#pragma once
#include <vector>
#include "../models/Task.h"
#include <json/json.h>

class TaskService {
public:
    static std::vector<Task> getAll();        // <-- объявление
    static Task create(const Json::Value &data);
};
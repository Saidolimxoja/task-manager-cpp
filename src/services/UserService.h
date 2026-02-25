#pragma once
#include "../models/Task.h"
#include <vector>
#include <json/json.h>

class TaskService {
public:
    static std::vector<Task> getAll();          // <-- только объявление
    static Task create(const Json::Value &data); // <-- только объявление
};
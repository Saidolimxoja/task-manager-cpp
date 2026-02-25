#include <drogon/drogon.h>
#include "controllers/TaskController.h"
#include "controllers/UserController.h"

int main() {
    // Загружаем конфиг (если есть)
    drogon::app().loadConfigFile("config.json");

    // Регистрируем контроллеры
    drogon::app().registerController(std::make_shared<TaskController>());
    drogon::app().registerController(std::make_shared<UserController>());

    // Запускаем сервер на порту из config.json или 8080 по умолчанию
    drogon::app().run();
}
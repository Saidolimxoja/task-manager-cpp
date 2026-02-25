#include <drogon/drogon.h>

int main() {
    drogon::app().loadConfigFile("../config.json"); // путь к конфигу
    drogon::app().run();
}
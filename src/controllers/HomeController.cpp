#include "HomeController.h"
#include <drogon/HttpResponse.h>

void HomeController::index(const HttpRequestPtr &req,
                           std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto resp = HttpResponse::newHttpResponse();
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_TEXT_HTML);
    resp->setBody("<!DOCTYPE html><html><head><title>TaskManager</title></head>"
                  "<body><h1>Welcome to TaskManager!</h1></body></html>");
    callback(resp);
}
#pragma once
#include <cpprest/http_listener.h>

class Server
{
public:
    Server(const std::string& uri);
private:
    void handlePost(const web::http::http_request& request);
    web::http::experimental::listener::http_listener _listener;
};
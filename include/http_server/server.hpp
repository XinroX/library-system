#pragma once
#include <cpprest/http_listener.h>
#include "interfaces/ilibrary.hpp"

class Server
{
public:
    Server(const std::string& uri);
private:
    void handlePost(const web::http::http_request& request);
    void handleGet(const web::http::http_request& request);
    web::http::http_response getAllBooks();
    web::http::http_response getAvailableBooks();
    web::http::http_response getUserBooks(const web::json::value& request);
    web::http::experimental::listener::http_listener _listener;

    std::unique_ptr<ILibrary> _librarySystem;
};
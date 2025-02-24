#include "server.hpp"

Server::Server(const std::string& uri) : _listener(uri)
{
    _listener.support(web::http::methods::POST, [&](const web::http::http_request& request){ handlePost(request);});
    _listener.open();
}

void Server::handlePost(const web::http::http_request& request)
{
    std::cout << request.extract_json().get().serialize() << std::endl;
    web::http::http_response response;
    web::json::value jsonResponse;
    jsonResponse["info"] = web::json::value::string("Test");
    response.set_body(jsonResponse);
    response.set_status_code(web::http::status_codes::OK);
    request.reply(response);
}
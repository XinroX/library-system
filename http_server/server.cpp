#include "server.hpp"
#include <cpprest/json.h>
#include "lib_mock.hpp"

Server::Server(const std::string& uri) : _listener(uri)
{
    _listener.support(web::http::methods::POST, [&](const web::http::http_request& request){ handlePost(request);});
    _listener.support(web::http::methods::GET, [&](const web::http::http_request& request){ handleGet(request);});
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

void Server::handleGet(const web::http::http_request& request)
{
    // request.reply(web::http::status_codes::OK, U("Hello"));
    auto paths = web::uri::split_path(request.request_uri().to_string());
    if (paths.size() == 0)
    {
        request.reply(web::http::status_codes::BadRequest);
        return;
    }
    if (paths.size() == 2 && paths.at(1) == "library")
    {
        if (paths.at(2) == "get-all-books")
        {
            request.extract_json().then([&](const web::json::value& jsonRequest){
                auto response = getAllBooks();
                request.reply(response);
            });
        }
        else if (paths.at(2) == "get-available-books")
        {
            request.extract_json().then([&](const web::json::value &jsonRequest){
                auto response = getAvailableBooks();
                request.reply(response); 
            });
        }
        else if (paths.at(2) == "get-user-books")
        {
            request.extract_json().then([&](const web::json::value &jsonRequest){
                auto response = getUserBooks(jsonRequest);
                request.reply(response); 
            });
        }
    }
    request.reply(web::http::status_codes::OK);
}

web::http::http_response Server::getAllBooks()
{
    web::json::value result;
    web::http::http_response response;
    std::vector<Item> items = _librarySystem->getAllItems();
    std::map<std::string, std::vector<web::json::value>> categoryMap;
    std::for_each(items.begin(), items.end(), [&](const Item& item){
        web::json::value value;
        value["author"] = web::json::value::string(item.getAuthor());
        value["title"] = web::json::value::string(item.getTitle());
        categoryMap[item.getCategory()].emplace_back(value);
    });
    std::vector<web::json::value> category;
    for (const auto& key : categoryMap)
    {
        web::json::value value;
        value[key.first] = web::json::value::array(key.second);
        category.emplace_back(value);
    }
    result["categories"] = web::json::value::array(category);
    response.set_body(result);
    response.set_status_code(web::http::status_codes::OK);
    return response;
}

web::http::http_response Server::getAvailableBooks()
{
    return web::http::http_response();
}
web::http::http_response Server::getUserBooks(const web::json::value &request)
{
    return web::http::http_response();
}
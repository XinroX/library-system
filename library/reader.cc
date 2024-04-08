#include "reader.hh"
#include <algorithm>

Reader::Reader(std::string first_name, std::string last_name, std::string number)
    : User{first_name, last_name, number}
{
}

void Reader::add_item(std::shared_ptr<Item> item)
{
    if (std::find(items.begin(), items.end(), item) == items.end()) {
        items.push_back(item);
    }
    else {
        std::cout << "Item already exists\n";
    }

    // std::cout << items.size() << '\n';
}

Items Reader::get_items() {
    return items;
}

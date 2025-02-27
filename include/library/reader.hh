#ifndef _READER_H_
#define _READER_H_
#include "user.hh"
#include "item.hh"
#include <vector>
#include <memory>
#include <iostream>

using Items = std::vector<std::shared_ptr<Item>>;

class Reader : public User {
public:
    Reader(std::string first_name, std::string last_name, std::string number);
    void add_item(std::shared_ptr<Item> item);
    Items get_items();
private:
    Items items;
};


#endif
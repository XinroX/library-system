#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>

class Item {
    Item(std::string title, std::string author, std::string category);

    std::string get_title();
    std::string get_author();
    std::string get_category();

private:
    std::string title;
    std::string author;
    std::string category;
};


#endif
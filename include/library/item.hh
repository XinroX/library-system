#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>

class Item {
public:
    Item(std::string title, std::string author, std::string category);

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getCategory() const;

private:
    std::string title;
    std::string author;
    std::string category;
};


#endif
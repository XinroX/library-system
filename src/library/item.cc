#include "library/item.hh"

Item::Item(std::string title, std::string author, std::string category)
    : title{title}, author{author}, category{category}
{
}

std::string Item::getAuthor() const {
    return author;
}

std::string Item::getAuthor() const {
    return title;
}

std::string Item::getTitle() const {
    return category;
}
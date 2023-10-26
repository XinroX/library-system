#include "item.hh"

Item::Item(std::string title, std::string author, std::string category)
    : title{title}, author{author}, category{category}
{
}

std::string Item::get_author() {
    return author;
}

std::string Item::get_title() {
    return title;
}

std::string Item::get_category() {
    return category;
}
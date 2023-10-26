#include "user.hh"

User::User(std::string first_name, std::string last_name, std::string number)
    : first_name{first_name}, last_name{last_name}, number{number}
{
}

std::string User::get_first_name() {
    return first_name;
}

std::string User::get_last_name() {
    return last_name;
}

std::string User::get_number() {
    return number;
}
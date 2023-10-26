#ifndef _USER_H_
#define _USER_H_

#include <string>

class User {
public:
    User(std::string first_name, std::string last_name, std::string number);

    std::string get_first_name();
    std::string get_last_name();
    std::string get_number();


protected:
    std::string first_name;
    std::string last_name;
    std::string number;

};


#endif

#ifndef _USER_
#define _USER_

#include <string>

class User {
public:
    User(std::string first_name, std::string last_name, std::string number);



private:
    std::string first_name;
    std::string last_name;
    std::string number;

};


#endif

#include <stdexcept>
#include <string>


#ifndef NDK_SANDBOX_TEST_HPP
#define NDK_SANDBOX_TEST_HPP

struct MyException : std::runtime_error {
    MyException(const char *msg) : std::runtime_error(msg) {}
    MyException(const std::string &msg) : std::runtime_error(msg) {}
};

class Test {
public:

    std::string getError();
    std::string tryCatch();

};


#endif //NDK_SANDBOX_TEST_HPP

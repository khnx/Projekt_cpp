#ifndef CLASS_EXCEPTIONS
#define CLASS_EXCEPTIONS 1

#include <stdexcept>
#include <string>

class cExceptions : public std::runtime_error {
public:
  cExceptions(const char *msg) : std::runtime_error(msg) {}
};

#endif
#ifndef PARSEJSONERROR_H
#define PARSEJSONERROR_H

#include <cerrno>
#include <cstring>
#include <stdexcept>

namespace GitHubAPI
{
    struct ParseJsonError : public std::runtime_error {
    public:
        explicit ParseJsonError(const char *what_msg) : std::runtime_error(what_msg) {};
	explicit ParseJsonError() : std::runtime_error(strerror(errno)) {};
};
    
}

#endif /* PARSEJSONERROR_H */


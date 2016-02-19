#ifndef GITHUBAPIERROR_H
#define GITHUBAPIERROR_H

#include <cerrno>
#include <cstring>
#include <stdexcept>

namespace GitHubAPI
{
    struct GitHubApiError : public std::runtime_error {
    public:
        explicit GitHubApiError(const char *what_msg) : std::runtime_error(what_msg) {};
	explicit GitHubApiError() : std::runtime_error(strerror(errno)) {};
};
    
}

#endif /* GITHUBAPIERROR_H */


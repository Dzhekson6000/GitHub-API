#ifndef GITHUB_H
#define GITHUB_H
#include "Http/HttpSocketClient.h"

using namespace SiTNetwork;

namespace GitHubAPI
{
    class GitHub
    {
    public:
        GitHub();
        GitHub(std::string login, std::string password);
        GitHub(std::string token);
        virtual ~GitHub();

        void connect();
        bool isAnonymous();
    private:
        std::string _login;
        std::string _password;
        std::string _token;
        HttpSocketClient* _httpSocketClient;
    };
}



#endif /* GITHUB_H */


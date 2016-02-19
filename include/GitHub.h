#ifndef GITHUB_H
#define GITHUB_H
#include "Http/HttpSocketClient.h"
#include "User/Myself.h"

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
        HttpResponse connect(HttpRequest httpRequest);
        
        bool isAnonymous();
        Myself getMyself();
        User getUser(std::string login);
    private:
        std::string _login;
        std::string _password;
        std::string _token;
        std::string _authorization;
        HttpSocketClient* _httpSocketClient;
    };
}



#endif /* GITHUB_H */


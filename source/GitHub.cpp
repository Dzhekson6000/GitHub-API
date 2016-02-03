#include "GitHub.h"

using namespace GitHubAPI;

GitHub::GitHub()
{
}

GitHub::GitHub(std::string login, std::string password)
{
    _login = login;
    _password = password;
}

GitHub::GitHub(std::string token)
{
    _token = token;
}


GitHub::~GitHub()
{
}

void GitHub::connect()
{
    _httpSocketClient = new HttpSocketClient("api.github.com",443);
    _httpSocketClient->setUseSSL(true);
    _httpSocketClient->create();
    
    //auth
    HttpRequest httpRequestAuth;
    httpRequestAuth.setMethod(Http::METHOD::GET);
    httpRequestAuth.setPath("");
    httpRequestAuth.setProtocol("HTTP/1.1");
    httpRequestAuth.addHeader("Host", "api.github.com");
    httpRequestAuth.addHeader("User-Agent", "GitHubAPI");
    
    std::string authorization;
    
    if(_token.length()!=0)
    {
        authorization = "token " + _token;
    }
    else if(_login.length()!=0 && _password.length()!=0)
    {
        authorization = "Basic " + _login + ':' + _password;//use basic 64
    }
    else
    {
        return;
    }
    
    httpRequestAuth.addHeader("Authorization", authorization);
    httpRequestAuth.gen();
    
    _httpSocketClient->send(httpRequestAuth);
}

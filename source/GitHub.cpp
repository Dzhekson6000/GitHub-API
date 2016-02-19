#include "GitHub.h"
#include <json/json.h>
#include <GitHubApiError.h>

using namespace GitHubAPI;

GitHub::GitHub()
{
}

GitHub::GitHub(std::string login, std::string password)
{
    _login = login;
    _password = password;
    connect();
}

GitHub::GitHub(std::string token)
{
    _token = token;
    connect();
}


GitHub::~GitHub()
{
}

bool GitHub::isAnonymous()
{
    if(_token.length()!=0 || _login.length()!=0 && _password.length()!=0)
        return true;
    return false;
}

Myself GitHub::getMyself()
{
    HttpRequest httpRequest;
    httpRequest.setMethod(Http::METHOD::GET);
    httpRequest.setPath("/user");
    
    HttpResponse httpResponse = connect(httpRequest);
    
    Myself user;
    user.parse(httpResponse.getBody());
    return user;
}

User GitHub::getUser(std::string login)
{
    HttpRequest httpRequest;
    httpRequest.setMethod(Http::METHOD::GET);
    httpRequest.setPath("/users/"+login);
    
    HttpResponse httpResponse = connect(httpRequest);
    
    User user;
    user.parse(httpResponse.getBody());
    return user;
}


void GitHub::connect()
{
    _httpSocketClient = new HttpSocketClient("api.github.com",443);
    _httpSocketClient->setUseSSL(true);
    _httpSocketClient->create();
    
    if(_token.length()!=0)
    {
        _authorization = "token " + _token;
    }
    else if(_login.length()!=0 && _password.length()!=0)
    {
        _authorization = "Basic " + _login + ':' + _password;//use basic 64
    }
    
    HttpRequest httpRequestAuth;
    httpRequestAuth.setMethod(Http::METHOD::GET);
    httpRequestAuth.setPath("/");
    
    HttpResponse httpResponse = connect(httpRequestAuth);
    
    Json::Value root;
    Json::Reader reader;
    
    if(!reader.parse(httpResponse.getBody(),root)) throw ParseJsonError(reader.getFormattedErrorMessages().c_str());
    for (Json::Value::iterator it = root.begin(); it != root.end(); ++it)
    {
        if(it.key().asString() == "message")
        {
            throw GitHubApiError(root.get(it.key().asString(), 0).asString().c_str());
        }
    }
}

HttpResponse GitHub::connect(HttpRequest httpRequest)
{
    httpRequest.setProtocol("HTTP/1.1");
    httpRequest.addHeader("Host", "api.github.com");
    httpRequest.addHeader("User-Agent", "GitHubAPI");
    
    if(_authorization.length()!=0) httpRequest.addHeader("Authorization", _authorization);
    httpRequest.gen();
    
    _httpSocketClient->send(httpRequest);
    
    HttpResponse httpResponse;
    _httpSocketClient->read(httpResponse);
    return httpResponse;
}


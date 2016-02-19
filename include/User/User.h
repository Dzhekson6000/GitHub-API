#ifndef USER_H
#define USER_H
#include <string>
#include "ParseJsonError.h"

namespace GitHubAPI
{
    class User
    {
    public:
        User();
        virtual ~User();
        
        virtual void parse(const std::string& body) throw(ParseJsonError);
        
    protected:
        unsigned int _id;
        std::string _login;
        std::string _avatarUrl;
        std::string _gravatarId;
        std::string _url;
        std::string _htmlUrl;
        std::string _followersUrl;
        std::string _followingUrl;
        std::string _gistsUrl;
        std::string _starredUrl;
        std::string _subscriptionsUrl;
        std::string _organizationsUrl;
        std::string _reposUrl;
        std::string _eventsUrl;
        std::string _receivedEventsUrl;
        std::string _type;
        bool _siteAdmin;
        std::string _name;
        std::string _company;
        std::string _blog;
        std::string _location;
        std::string _email;
        bool _hireable;
        std::string _bio;
        unsigned int _publicRepos;
        int _publicGists;
        unsigned int _followers;
        unsigned int _following;
        std::string _createdAt;
        std::string _updatedAt;
    };
}

#endif /* USER_H */


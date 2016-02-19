#ifndef MYSELF_H
#define MYSELF_H
#include "User.h"

namespace GitHubAPI
{
    class Myself:public User
    {
    public:
        struct Plan
        {
            std::string name;
            int space;
            unsigned int privateRepos;
            unsigned int collaborators;
        };
        
        Myself();
        virtual ~Myself();
        
        virtual void parse(const std::string& body) throw(ParseJsonError);
    protected:
        unsigned int _totalPrivateRepos;
        unsigned int _ownedPrivateRepos;
        int _privateGists;
        int _diskUsage;
        unsigned int _collaborators;
        Plan _plan;
    };
}

#endif /* MYSELF_H */


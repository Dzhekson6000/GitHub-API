#include "User/Myself.h"
#include <json/json.h>

using namespace GitHubAPI;

Myself::Myself()
{
}

Myself::~Myself()
{
}

void Myself::parse(const std::string& body) throw(ParseJsonError)
{
    User::parse(body);
    
    Json::Value root;
    Json::Reader reader;
    
    if(!reader.parse(body,root)) throw ParseJsonError(reader.getFormattedErrorMessages().c_str());
    
    for (Json::Value::iterator it = root.begin(); it != root.end(); ++it)
    {
        if(it.key().asString() == "total_private_repos")
        {
            _totalPrivateRepos = root.get(it.key().asString(), 0).asInt();
        } else
        if(it.key().asString() == "owned_private_repos")
        {
            _ownedPrivateRepos = root.get(it.key().asString(), 0).asInt();
        } else
        if(it.key().asString() == "private_gists")
        {
            _privateGists = root.get(it.key().asString(), 0).asInt();
        } else
        if(it.key().asString() == "disk_usage")
        {
            _diskUsage = root.get(it.key().asString(), 0).asInt();
        } else
        if(it.key().asString() == "collaborators")
        {
            _collaborators = root.get(it.key().asString(), 0).asInt();
        } else
        if(it.key().asString() == "plan")
        {
            _plan.name = root.get(it.key().asString(), 0).get("name",0).asString();
            _plan.space = root.get(it.key().asString(), 0).get("space",0).asInt();
            _plan.privateRepos = root.get(it.key().asString(), 0).get("private_repos",0).asInt();
            _plan.collaborators = root.get(it.key().asString(), 0).get("collaborators",0).asInt();
        }
    }
    
}



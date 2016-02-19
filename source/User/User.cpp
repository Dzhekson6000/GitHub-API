#include "User/User.h"
#include <json/json.h>

using namespace GitHubAPI;

User::User()
{
}

User::~User()
{
}

void User::parse(const std::string& body) throw(ParseJsonError)
{
    Json::Value root;
    Json::Reader reader;
    
    if(!reader.parse(body,root)) throw ParseJsonError(reader.getFormattedErrorMessages().c_str());
    
    for (Json::Value::iterator it = root.begin(); it != root.end(); ++it)
    {
        if(it.key().asString() == "login")
        {
            _login = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "id")
        {
            _id = root.get(it.key().asString(), 0).asInt();
        } else
        if(it.key().asString() == "login")
        {
            _login = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "avatar_url")
        {
            _avatarUrl = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "gravatar_id")
        {
            _gravatarId = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "url")
        {
            _url = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "html_url")
        {
            _htmlUrl = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "followers_url")
        {
            _followersUrl = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "following_url")
        {
            _followingUrl = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "gists_url")
        {
            _gistsUrl = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "starred_url")
        {
            _starredUrl = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "subscriptions_url")
        {
            _subscriptionsUrl = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "organizations_url")
        {
            _organizationsUrl = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "repos_url")
        {
            _reposUrl = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "events_url")
        {
            _eventsUrl = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "received_events_url")
        {
            _receivedEventsUrl = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "type")
        {
            _type = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "site_admin")
        {
            _siteAdmin = root.get(it.key().asString(), 0).asBool();
        } else
        if(it.key().asString() == "name")
        {
            _name = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "company")
        {
            _company = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "blog")
        {
            _blog = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "location")
        {
            _location = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "email")
        {
            _email = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "hireable")
        {
            _hireable = root.get(it.key().asString(), 0).asBool();
        } else
        if(it.key().asString() == "bio")
        {
            _bio = root.get(it.key().asString(), 0).asString();
        } else
        if(it.key().asString() == "public_repos")
        {
            _publicRepos = root.get(it.key().asString(), 0).asInt();
        } else
        if(it.key().asString() == "public_gists")
        {
            _publicGists = root.get(it.key().asString(), 0).asInt();
        } else
        if(it.key().asString() == "followers")
        {
            _followers = root.get(it.key().asString(), 0).asInt();
        } else
        if(it.key().asString() == "following")
        {
            _following = root.get(it.key().asString(), 0).asInt();
        }else
        if(it.key().asString() == "created_at")
        {
            _createdAt = root.get(it.key().asString(), 0).asString();
        }else
        if(it.key().asString() == "updated_at")
        {
            _updatedAt = root.get(it.key().asString(), 0).asString();
        }
    }
}
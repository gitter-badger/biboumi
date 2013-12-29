#include <irc/irc_user.hpp>

#include <iostream>

IrcUser::IrcUser(const std::string& name,
                 const std::map<char, char>& prefix_to_mode)
{
  if (name.empty())
    return ;
  const std::string::size_type sep = name.find("!");
  const std::map<char, char>::const_iterator prefix = prefix_to_mode.find(name[0]);
  const size_t name_begin = prefix == prefix_to_mode.end()? 0: 1;
  if (sep == std::string::npos)
    this->nick = name.substr(name_begin);
  else
    {
      this->nick = name.substr(name_begin, sep);
      this->host = name.substr(sep+1);
    }
  if (prefix != prefix_to_mode.end())
    this->modes.insert(prefix->second);
}

IrcUser::IrcUser(const std::string& name):
  IrcUser(name, {})
{
}

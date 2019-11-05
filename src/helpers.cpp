#include "helpers.hpp"
#include <sstream>
#include <dirent.h>
#include <iostream>

bool ends_with(std::string const &fullString, std::string const &ending)
{
   if (fullString.length() >= ending.length())
   {
      return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
   }
   else
   {
      return false;
   }
}

std::vector<std::string> split(const std::string &s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

std::vector<Available_Connection> scan_config_dir(std::string path)
{
   //TODO: check if path ends with a /
   std::vector<Available_Connection> return_vec;
   DIR *dir;
   struct dirent *ent;
   if ((dir = opendir(path.c_str())) != NULL)
   {
      /* print all the files and directories within directory */
      while ((ent = readdir(dir)) != NULL)
      {
         //printf("%s\n", ent->d_name);
         std::string candidate(ent->d_name);
         if (ends_with(candidate, ".conf") || ends_with(candidate, ".ovpn"))
         {
            std::cout << "Found available connection: " << ent->d_name << std::endl;
            return_vec.push_back(Available_Connection(path + std::string(ent->d_name)));
         }
      }
      closedir(dir);
   }
   return return_vec;
}

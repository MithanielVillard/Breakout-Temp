#include "pch.h"
#include "Utils.h"

std::string Utils::getResourcesPath()
{
    //Go back to the res directory from the exe path (ide dir when launched from an ide)
    static std::string path = std::filesystem::current_path().parent_path().
    parent_path().parent_path().string() + "\\res\\";
    
    return path;
}


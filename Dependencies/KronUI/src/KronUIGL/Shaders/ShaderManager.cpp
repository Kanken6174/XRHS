#include "ShaderManager.hpp"
#include <algorithm>
#include "Shader.hpp"
#include "../../../include/logger.hpp"

const std::shared_ptr<ShaderManager> ShaderManager::instance = std::make_shared<ShaderManager>();

/// @brief set the currently used shader by opengl if it's not already used and is within the shader collection
/// @param s shader to be used
void ShaderManager::setShader(std::shared_ptr<Shader> s)
{
    if (std::any_of(shaders.begin(), shaders.end(), [&s](const auto& shader) { return shader->ID == s->ID; }))
    {
        if(!this->current.has_value() || this->current.value()->ID != s->ID){
            current = s;
            current.value()->use();
        }
    }else{
        Logger::getInstance().warn("Shader with id " + std::to_string(s->ID) + " not found (setShader(std::shared_ptr<Shader> s))");
    }
}

void ShaderManager::setShader(const unsigned int& id)
{
    if(!id || (current.has_value() && current.value()->ID == id)){
        return;
    }
    auto it = std::find_if(shaders.begin(), shaders.end(), [&id](const auto& shader) { return shader->ID == id; });
    if (it != shaders.end())
    {
        if(!this->current.has_value() || this->current.value()->ID != id){
            current = *it;
            current.value()->use();
        }
    }else{
        Logger::getInstance().warn("Shader with id " + std::to_string(id) + " not found (setShader(const unsigned int& id)))");
    }
}


/// @brief check if shader is present in the shader collection and if not add it
/// @param s shader to be added
void ShaderManager::addShader(std::shared_ptr<Shader> s)
{
    if (std::none_of(shaders.begin(), shaders.end(), [&s](const auto& shader) { return shader->ID == s->ID; }))
    {
        shaders.push_back(s);
    }else{
        Logger::getInstance().warn("Shader with id " + std::to_string(s->ID) + " already exists");
    }
}

/// @brief check if shader is present in the shader collection and remove it
/// @param s shader to be removed
void ShaderManager::remShader(std::shared_ptr<Shader> s)
{
    if(!s || current == s){
        Logger::getInstance().warn("Shader with id " + std::to_string(s->ID) + " not found (remShader(std::shared_ptr<Shader> s)))");
        return;
    }
    auto it = std::find_if(shaders.begin(), shaders.end(), [&s](const auto& shader) { return shader->ID == s->ID; });
    if (it != shaders.end())
    {
        if (current.has_value() && current.value() == *it)
            current.reset();  // reset the current shader if it's the one being removed

        shaders.erase(it);
    }
}

std::shared_ptr<Shader> ShaderManager::buildShader(const std::string &vertexPath, const std::string &fragmentPath, const std::string &geometryPath)
{
    auto shader = std::make_shared<Shader>(vertexPath.c_str(), fragmentPath.c_str(), geometryPath == "" ? nullptr : geometryPath.c_str());
    shaders.push_back(shader);
    Logger::getInstance().warn("Shader with id " + std::to_string(shader->ID) + " built");
    return shader;
}
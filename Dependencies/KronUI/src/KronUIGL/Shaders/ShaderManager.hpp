#pragma once

#include <vector>
#include <memory>
#include <optional>
#include <string>

class Shader;

/// @brief Manages shaders (with singleton)
class ShaderManager {
protected:
    std::vector<std::shared_ptr<Shader>> shaders;
    std::optional<std::shared_ptr<Shader>> current;
    static const std::shared_ptr<ShaderManager> instance;
public:
    ShaderManager(){
        shaders = std::vector<std::shared_ptr<Shader>>();
        current = std::nullopt;
    }
    static const std::shared_ptr<ShaderManager> getInstance(){
        return instance;
    }
    void setShader(std::shared_ptr<Shader> s);
    void setShader(const unsigned int& id);
    void addShader(std::shared_ptr<Shader> s);
    void remShader(std::shared_ptr<Shader> s);
    std::shared_ptr<Shader> buildShader(const std::string& vertexPath, const std::string& fragmentPath, const std::string& geometryPath = std::string(""));
};
#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform {
public:
    virtual glm::vec3 getPosition() const = 0;
    virtual void setPosition(const glm::vec3& position) = 0;
    virtual void translate(const glm::vec3& translation) = 0;

    virtual glm::vec3 getScale() const = 0;
    virtual void setScale(const glm::vec3& scale) = 0;

    virtual glm::vec3 getEulerAngles() const = 0;
    virtual void setEulerAngles(const glm::vec3& eulerAngles) = 0;
    virtual void rotate(const glm::vec3& rotation) = 0;

    virtual glm::quat getQuaternion() const = 0;
    virtual void setQuaternion(const glm::quat& quaternion) = 0;

    virtual glm::vec3 getForward() const = 0;
    virtual glm::vec3 getUp() const = 0;
    virtual glm::vec3 getRight() const = 0;

    virtual glm::mat4 getTransformMatrix() const;   //pre-defined utility

    virtual ~Transform() {}
};

class EulerTransform : public Transform {
private:
    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 eulerAngles;
public:
    EulerTransform();
    EulerTransform(glm::vec3 position, glm::vec3 scale, glm::vec3 eulerAngles);
    glm::vec3 getPosition() const override;
    void setPosition(const glm::vec3& position) override;
    glm::vec3 getScale() const override;
    void setScale(const glm::vec3& scale) override;
    glm::vec3 getEulerAngles() const override;
    void setEulerAngles(const glm::vec3& eulerAngles) override;
    glm::quat getQuaternion() const override;
    void setQuaternion(const glm::quat& quaternion) override;
    void translate(const glm::vec3& translation) override;
    void rotate(const glm::vec3& rotation) override;
    glm::vec3 getForward() const override;
    glm::vec3 getUp() const override;
    glm::vec3 getRight() const override;
};

class QuaternionTransform : public Transform {
private:
    glm::vec3 position;
    glm::vec3 scale;
    glm::quat rotation;
public:
    QuaternionTransform();
    QuaternionTransform(glm::vec3 position, glm::vec3 scale, glm::quat rotation);
    glm::vec3 getPosition() const override;
    void setPosition(const glm::vec3& position) override;
    glm::vec3 getScale() const override;
    void setScale(const glm::vec3& scale) override;
    glm::vec3 getEulerAngles() const override;
    void setEulerAngles(const glm::vec3& eulerAngles) override;
    glm::quat getQuaternion() const override;
    void setQuaternion(const glm::quat& quaternion) override;
    void translate(const glm::vec3& translation) override;
    void rotate(const glm::vec3& rotation) override;
    glm::vec3 getForward() const override;
    glm::vec3 getUp() const override;
    glm::vec3 getRight() const override;

    glm::mat4 getTransformMatrix() const override; 
};
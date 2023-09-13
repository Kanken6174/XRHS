#pragma once
#include "./KronUIGL/KronUIGL.hpp"
#include "./KronUIGL/Input/Input.hpp"
#include "./KronUIGL/Shaders/ShaderManager.hpp"

#include "./KronUIGL/3D/Renderers/MeshRenderer.hpp"
#include "./KronUIGL/3D/Surfaces/X11DrawSurface.hpp"
#include "./KronUIGL/3D/Surfaces/VideoFrame.hpp"
#include "./KronUIGL/3D/Elements/world.hpp"
#include "./KronUIGL/3D/Kinematics/KinematicsProcessor.hpp"
#include "./KronUIGL/3D/Kinematics/Skeleton.hpp"
#include "./KronUIGL/3D/Surfaces/DrawCommands/DrawCommands.hpp"
#include "./KronUIGL/Geometry/Shapes.hpp"

#include "../include/logger.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <chrono>
#include <thread>
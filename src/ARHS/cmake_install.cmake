# Install script for directory: /home/kanken/code/XRHS/Dependencies/AHRS_core/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/kanken/code/XRHS/src/ARHS/threadweaver/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/model/perfcheckers/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/model/hardware/ihidapi/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/model/hardware/cameras/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/model/hardware/psvr/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/model/hardware/hw/extendables/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/model/hardware/hw/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/model/controllers/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/model/patterns/observer/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/model/patterns/commands/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/processing/zbar/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/model/windows/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/ui/support/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/pipeline/cmake_install.cmake")
  include("/home/kanken/code/XRHS/src/ARHS/pluginManagement/cmake_install.cmake")

endif()


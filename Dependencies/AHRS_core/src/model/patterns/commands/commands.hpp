#ifndef _COMMAND
#define _COMMAND
#include <iostream>

/**
 * The Command interface declares a method for executing a command.
 */
class Command {
 public:
  virtual ~Command() {
  }
  virtual void Execute() = 0;
};

class BoolCommand : public Command {
public:
    bool value = false;
    BoolCommand(bool value) : value(value) {}
    BoolCommand() {}
    virtual void Execute() {}
};
#endif
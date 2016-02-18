#include <string>
#include <iostream>
#include <sstream>

#include "interface.h"



class Application
{
public:

  Application()
  {
  }

  ~Application()
  {
  }

  const std::string requestState(const std::string& module, const std::string& state)
  {
    std::stringstream value;

    value << "<value>";

    return value.str();
  }

  const std::string sendCommand(const std::string& module, const std::string& command, const std::string& arguments)
  {
    std::stringstream ret;

    ret << "<return>";

    return ret.str();
  }
};



static Application * application = 0;



void startApplication()
{
  if(application == 0)
  {
    application = new Application();
    std::cout << "[C++] startApplication() : application started" << std::endl;
  }
  else
  {
    std::cout << "[C++] startApplication() : application already started" << std::endl;
  }
}



void stopApplication()
{
  if(application != 0)
  {
    delete application;
    std::cout << "[C++] stopApplication() : application stopped" << std::endl;
  }
  else
  {
    std::cout << "[C++] stopApplication() : application not started yet" << std::endl;
  }
}



const std::string requestState(const std::string& module, const std::string& state)
{
  if(application != 0)
  {
    return application->requestState(module, state);
  }
  else
  {
    std::cout << "[C++] requestState(...) : application not started yet" << std::endl;
    return "N/A";
  }
}



const std::string sendCommand(const std::string& module, const std::string& command, const std::string& arguments)
{
  if(application != 0)
  {
    return application->sendCommand(module, command, arguments);
  }
  else
  {
    std::cout << "[C++] sendCommand(...) : application not started yet" << std::endl;
    return "N/A";
  }
}


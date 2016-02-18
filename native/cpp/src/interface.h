#include <string>



void startApplication();

void stopApplication();

const std::string requestState(const std::string& module, const std::string& state);

const std::string sendCommand(const std::string& module, const std::string& command, const std::string& arguments);


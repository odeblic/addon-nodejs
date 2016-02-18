#include <iostream>

#include <interface.h>



int main()
{
  startApplication();

  std::cout << requestState("MyModule", "stbool") << std::endl;
  std::cout << requestState("MyModule", "stint") << std::endl;
  std::cout << requestState("MyModule", "ststr") << std::endl;

  sendCommand("MyModule", "cmdSetState", "stbool=true");
  sendCommand("MyModule", "cmdSetState", "stint=45");
  sendCommand("MyModule", "cmdSetState", "ststr=banane");

  std::cout << requestState("MyModule", "stbool") << std::endl;
  std::cout << requestState("MyModule", "stint") << std::endl;
  std::cout << requestState("MyModule", "ststr") << std::endl;

  sendCommand("MyModule", "cmdTerminate", "");

  stopApplication();

  return 0;
}

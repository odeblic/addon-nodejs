#include <v8.h>
#include <node.h>
#include <iostream>

#include "interface.h"



v8::Handle<v8::Value> startApplication(const v8::Arguments& args)
{
  v8::HandleScope scope;

  startApplication();

  return scope.Close(v8::String::New("N/A"));
}



v8::Handle<v8::Value> stopApplication(const v8::Arguments& args)
{
  v8::HandleScope scope;

  stopApplication();

  return scope.Close(v8::String::New("N/A"));
}



v8::Handle<v8::Value> requestState(const v8::Arguments& args)
{
  v8::HandleScope scope;
  std::string value;

  if(args.Length() == 2)
  {
    v8::String::AsciiValue actor(args[0]->ToString());
    v8::String::AsciiValue state(args[1]->ToString());

    value = requestState(*actor, *state);

    return scope.Close(v8::String::New(value.c_str()));
  }
  else
  {
    return scope.Close(v8::String::New("N/A"));
  }
}



v8::Handle<v8::Value> sendCommand(const v8::Arguments& args)
{
  v8::HandleScope scope;

  if(args.Length() == 3)
  {
    v8::String::AsciiValue actor(args[0]->ToString());
    v8::String::AsciiValue command(args[1]->ToString());
    v8::String::AsciiValue arguments(args[2]->ToString());

    sendCommand(*actor, *command, *arguments);

    return scope.Close(v8::String::New("N/A"));
  }
  else
  {
    return scope.Close(v8::String::New("N/A"));
  }
}



v8::Handle<v8::Value> getBool(const v8::Arguments& args)
{
  v8::HandleScope scope;

  bool arg = args[0]->BooleanValue();

  std::cout << "[C++] I reverse booleans..." << std::endl;

  return scope.Close(v8::Boolean::New(! arg));
}



v8::Handle<v8::Value> getInt(const v8::Arguments& args)
{
  v8::HandleScope scope;

  int arg = args[0]->Int32Value();

  std::cout << "[C++] I calculate square of integers..." << std::endl;

  return scope.Close(v8::Integer::New(arg * arg));
}



v8::Handle<v8::Value> getStr(const v8::Arguments& args)
{
  v8::HandleScope scope;

  v8::String::AsciiValue arg(args[0]->ToString());

  std::cout << "[C++] I append something to strings..." << std::endl;

  return scope.Close(v8::String::New(std::string(std::string(*arg) + " added").c_str()));
}



void init(v8::Handle<v8::Object> exports, v8::Handle<v8::Object> module)
{
  std::cout << "[C++] NodeJS Module 'plugin' has been initialized" << std::endl;

  NODE_SET_METHOD(exports, "startApplication", startApplication);
  NODE_SET_METHOD(exports, "stopApplication", stopApplication);
  NODE_SET_METHOD(exports, "requestState", requestState);
  NODE_SET_METHOD(exports, "sendCommand", sendCommand);

  NODE_SET_METHOD(exports, "getBool", getBool);
  NODE_SET_METHOD(exports, "getInt", getInt);
  NODE_SET_METHOD(exports, "getStr", getStr);
}

NODE_MODULE(plugin, init)


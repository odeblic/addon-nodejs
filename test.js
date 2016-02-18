var myplugin = require("./nodejs/build/Release/plugin.node");

myplugin.startApplication();

console.log('stbool ' + myplugin.requestState("MyModule", "stbool"));
console.log('stint ' + myplugin.requestState("MyModule", "stint"));
console.log('ststr ' + myplugin.requestState("MyModule", "ststr"));

console.log('cmdSetState > ' + myplugin.sendCommand("MyModule", "cmdSetState", "stbool=true"));
console.log('cmdSetState > ' + myplugin.sendCommand("MyModule", "cmdSetState", "stint=45"));
console.log('cmdSetState > ' + myplugin.sendCommand("MyModule", "cmdSetState", "ststr=banane"));

console.log('stbool ' + myplugin.requestState("MyModule", "stbool"));
console.log('stint ' + myplugin.requestState("MyModule", "stint"));
console.log('ststr ' + myplugin.requestState("MyModule", "ststr"));

console.log('cmdTerminate > ' + myplugin.sendCommand("MyModule", "cmdTerminate"));

myplugin.stopApplication();

console.log('Calling getBool(false)');
var value = myplugin.getBool(false);
console.log('Return value = ' + value);

console.log('Calling getInt(5)');
var value = myplugin.getInt(5);
console.log('Return value = ' + value);

console.log('Calling getStr("content")');
var value = myplugin.getStr("content");
console.log('Return value = "' + value + '"');


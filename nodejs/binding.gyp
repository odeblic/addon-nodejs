{
  "targets":
  [
    {
      "target_name"   : "plugin",
      "sources"       : [ "plugin.cpp" ],
      "include_dirs"  : [ "../native/cpp/src" ],
      "libraries"     : [ "-lplugin", "-L../../native/cpp/target" ]
    }
  ]
}


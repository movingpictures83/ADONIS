#ifndef ADONISPLUGIN_H
#define ADONISPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class ADONISPlugin : public Plugin
{
public: 
 std::string toString() {return "ADONIS";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;
 std::vector<std::string> metrics;
};

#endif

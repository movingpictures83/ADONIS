#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "ADONISPlugin.h"

void ADONISPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
 
}

void ADONISPlugin::run() {
   
}

void ADONISPlugin::output(std::string file) {
//beta_diversity.py -i filtered_otu_table.biom -m euclidean,weighted_unifrac,unweighted_unifrac -t rep_set.tre -o beta_div
   std::string command = "compare_categories.py ";
 command += "-i "+std::string(PluginManager::prefix())+"/"+parameters["matrix"];
 command += " -m "+std::string(PluginManager::prefix())+"/"+parameters["mapping"];
 command += " -c "+parameters["column"];
 command += " --method "+parameters["method"];
 command += " -o "+file+"; cp "+file+"/adonis_results.txt "+file+"/..";//; export PYTHONPATH=OLDPATH";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<ADONISPlugin> ADONISPluginProxy = PluginProxy<ADONISPlugin>("ADONIS", PluginManager::getInstance());

#include <iostream>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <vector>

void  displayCfg(const Json::Value &cfg_root)
{
    //std::string serverIP = cfg_root["Config"]["server-ip"].asString();
    //std::string serverPort = cfg_root["Config"]["server-port"].asString();
    //unsigned int bufferLen = cfg_root["Config"]["buffer-length"].asUInt();

    std::cout << "______ Configuration ______" << std::endl;
    for (int i=0;i<5;i++){
    	std::cout<<" input "<<cfg_root[i]["input"][0]<<std::endl;
    }
    std::array <int,5> v;
    v[0] = cfg_root[0]["input"][1].asInt();
    std::cout<<v[0]<<"hello"<<std::endl;
    if (cfg_root[0]["input"][1].asString() == "null" ){
    	std::cout<<"True";
    }

}

int main()
{
    Json::Reader reader;
    Json::Value cfg_root;
    std::ifstream cfgfile("dot.json");
    cfgfile >> cfg_root;

    //std::cout << "______ cfg_root : start ______" << std::endl;
    //std::cout << cfg_root << std::endl;
    //std::cout << "______ cfg_root : end ________" << std::endl;

    displayCfg(cfg_root);
}       


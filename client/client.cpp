#include <iostream>
#include <fstream>
#include "core.hpp"
#include <boost/program_options.hpp>

void show_help() {
    std::cout << "Usage: client [options]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  --help    Show this help message" << std::endl;
}

struct Config {
    std::string database_name;
    std::string url;
    int port;
};

struct Config_AppCopy {
    std::string file_path;
    std::string target_path;
    int size_buffer = 1024;
};

int main(int argc, char* argv[]) {
    
    
    boost::program_options::options_description desc("App copy files options");
    desc.add_options()("help", "produce help message")
    ("file_path", boost::program_options::value<std::string>(), "set file path")
    ("target_path", boost::program_options::value<std::string>(), "set target path")
    ("size_buffer", boost::program_options::value<int>(), "set buffer size");
    
    // Parse
    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);
    
    Config_AppCopy config;
    
    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 0;
    }
    
    if (vm.count("file_path"))
    {
        config.file_path = vm["file_path"].as<std::string>();
        // std::cout << "File path set to: " << config.file_path << std::endl;
    }
    else
    {
        std::cout << "File path not set." << std::endl;
        return 1;
    }

    if (vm.count("target_path"))
    {
        config.target_path = vm["target_path"].as<std::string>();
        // std::cout << "Target path set to: " << config.target_path << std::endl;
    }
    else
    {
        std::cout << "Target path not set." << std::endl;
        return 1;
    }
    
    if (vm.count("size_buffer"))
    {
        config.size_buffer = vm["size_buffer"].as<int>();
        // std::cout << "Buffer size set to: " << config.size_buffer << std::endl;
    }    
    
    std::cout << "Copying file from " << config.file_path 
                << " to " << config.target_path 
                << " with buffer size " << config.size_buffer << std::endl;   
    
    
    return 0;
}
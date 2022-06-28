#include <iostream>
#include <filesystem>
#include <exception>


int main()
{
    auto recursiveGetFileNamesByExtension = [](std::filesystem::path path, const std::string extension)
    {
        if(std::filesystem::is_directory(path))
        {
            for(auto& p: std::filesystem::recursive_directory_iterator(path))
            {
                if(!p.path().extension().compare("."+extension))
                    std::cout << p.path().filename() << '\n';
            }
        }else
        {
            throw std::runtime_error("WARNING: No such directory.");
        }

    };

    std::cout << "Specify target directory: ";
    std::string filePath;
    getline(std::cin, filePath);

    std::cout << "Search file extensions: ";
    std::string extensions;
    getline(std::cin, extensions);

    try {
        recursiveGetFileNamesByExtension(std::filesystem::path(filePath), extensions);
    }  catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

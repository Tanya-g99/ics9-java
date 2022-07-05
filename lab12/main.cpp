#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[]){
    if (argc == 1){
        perror("one arg");
    }
    ///home/gnatenkota/vsc/ics9-java/lab12/test/
    auto dir = opendir(argv[1]);
    if (!dir){
        perror("opendir");
    }
    auto file = readdir(dir);
    std::ofstream fo("ifs.txt");
    while (file)
    {
        auto lenf = strlen(file->d_name);
        if((file->d_name)[lenf - 2] == '.' && (file->d_name)[lenf - 1] == 'c'){
            std::ifstream f;
	        f.open(argv[1] + string(file->d_name));
	        std::string line;
            std::vector <int> arr;
            int count = 0;
	        while (getline(f, line)){
                auto lenline = line.length();
                for(int i = 0; i < lenline - 1; i++){
                    if(line[i] == 'i' && line[i+1] == 'f'){
                        arr.push_back(count);
                        break;
                    }
                }
                count++;
	        }
            fo << std::string(file->d_name)<< ' ';
            for(auto a : arr) 
            { 
                fo << a << ' ';
            }
            fo << "\n";
        }
        file = readdir(dir);
    }
    fo.close();
    
    closedir(dir);
}
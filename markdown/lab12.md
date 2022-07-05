---
предмет: Языки и методы программирования
название:
номер:
тип_работы: Лабораторная работа
группа: ИУ9-22Б
автор: Гнатенко Т. А.
преподаватель: Посевин Д. П.
---

# Цели

Целью лабораторной работы является приобретение навыка разработки на языке C++ программ, осуществляющих анализ и преобразование текстовых файлов, записанных в различных форматах.

# Задачи

Найти все файлы с расширением «c» в указанном каталоге, и для каждого файла составить последовательность номеров строк, в которых располагаются заголовки операторов «if». Полученную информацию нужно сохранить в файле ifs.txt в текущем каталоге. Каждая строка файла ifs.txt должна содержать имя c-файла и последовательность номеров строк, отсортированную в порядке возрастания. 
Работоспособность программы нужно проверить на наборе предварительно подготовленных файлов с исходниками на языке C (можно использовать, например, часть исходных текстов ядра Linux).

# Решение

## Исходный код

`main.cpp`

```cpp
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;
int main(){
    auto dir = opendir("/home/gnatenkota/vsc/ics9-java/lab12/test/");
    if (!dir){
        perror("opendir");
    }
    auto file = readdir(dir);
    while (file)
    {
        auto lenf = strlen(file->d_name);
        if((file->d_name)[lenf - 2] == '.' && (file->d_name)[lenf - 1] == 'c'){
            std::ifstream f;
	        f.open("/home/gnatenkota/vsc/ics9-java/lab12/test/" + string(file->d_name));
	        std::string line;
            std::vector <int> arr;
            int count = 0;
	        while (getline(f, line)){
                std::cout << line;
                auto lenline = line.length();
                for(int i = 0; i < lenline - 1; i++){
                    if(line[i] == 'i' && line[i+1] == 'f'){
                        arr.push_back(count);
                        break;
                    }
                }
                count++;
	        }
            std::ofstream fo("ifs.txt");
            fo << std::string(file->d_name)<< ' ';
            for(auto a : arr) 
            { 
                fo << a << ' ';
            }
            fo << "\n";
            fo.close();
        }
        file = readdir(dir);
    }
    
    closedir(dir);
}
```
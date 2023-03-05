#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include <ncurses.h>

int main() {
    std::fstream files;
    char check;
    std::string fileSelector;
    int z = 1;
    std::string name;
    int i = 0;
    bool whileCheck = true;
    system("reset");
    while (whileCheck == true) {
        if (i <= 0) {
            std::cout << "\033[1mBritney | \033[0;31mhttps://github.com/diegxherrera" << std::endl;
            std::cout << "\033[0m";
        } else {
            std::cout << "\033[31;1;4m" << "OPTION NOT FOUND!" << std::endl;
            std::cout << "\033[0m";
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            std::cout << "\033[1mBritney | \033[0;31mhttps://github.com/diegxherrera" << std::endl;
            std::cout << "\033[0m";

        }
        std::cout << "+---------------------------------------+" << std::endl;
        std::cout << "| [1] Create a new file\t\t\t|\n";
        std::cout << "| [2] Open a file\t\t\t|\n";
        std::cout << "| [3] Write a file\t\t\t|\n";
        std::cout << "| [4] Find some help\t\t\t|\n";
        std::cout << "| [5] Close Britney\t\t\t|\n";
        std::cout << "+---------------------------------------+" << std::endl;
        std::cout << "What do you want do? (Select with the numbers): ";
        std::cin >> check;
        switch(check) {
            case '1':
                whileCheck = false;

                break;
            case '2':
                whileCheck = false;
                system("clear");
                FILE *fp;
                char path[1035];
                fp = popen("ls | grep .bn", "r");
                std::cout << "\033[1mBritney | \033[0;31mFiles available" << std::endl; 
                std::cout << "\033[0m";
                std::cout << "-----------------------------------------" << std::endl;
                while (fgets(path, sizeof(path)-1, fp) != NULL) {
                    std::cout << "[" << z << "] " << path;
                    z++;
                }
                pclose(fp);
                std::cout << "-----------------------------------------" << std::endl;
                std::cout << "Which file would you like to open?: ";
                std::cin >> fileSelector;
                break;
            case '3':
                system("reset");
                break;
            case '4':
                break;
            case '5':
                break;
            default:
                whileCheck = true;
                i++;
                system("clear");
                break;
        }
    }
}
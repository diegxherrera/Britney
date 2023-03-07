#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include <ncurses.h>
#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#endif

int main() {
    std::fstream files;
    char buffer[256];
    bool exitFlag = false;
    char check;
    int fileSelector;
    int z = 1;
    std::string name;
    std::string fileName;
    std::string input;
    std::string output;
    int i = 0;
    bool whileCheck = true;
    while (whileCheck == true) {
        if (i <= 0) {
            std::cout << "+---------+-------------------------------------+" << std::endl;
            std::cout << "\033[1m| Britney | \033[0;31mhttps://github.com/diegxherrera\t\033[0m|" << std::endl;
            std::cout << "\033[0m";
        } else {
            std::cout << "+---------+-------------------------------------+" << std::endl;
            std::cout << "\033[1m| Britney | \033[1;31mOPTION NOT FOUND!\t\t\t\033[0m|" << std::endl;
            std::cout << "\033[0m";
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
        std::cout << "+---------+-------------------------------------+" << std::endl;
        std::cout << "| [1] Create a new file\t\t\t\t|\n";
        std::cout << "| [2] Open a file\t\t\t\t|\n";
        std::cout << "| [3] Write a file\t\t\t\t|\n";
        std::cout << "| [4] Find some help\t\t\t\t|\n";
        std::cout << "| [5] Close Britney\t\t\t\t|\n";
        std::cout << "+-----------------------------------------------+" << std::endl;
        std::cout << "What do you want do? (Select with the numbers): ";
        std::cin >> check;
        std::cin.ignore();
        switch(check) {
            case '1':
                whileCheck = false;
                std::cout << "File name: ";
                std::cin >> fileName;
                std::cin.ignore();
                if (true) {
                    files.open(fileName + ".bn", std::ios::out);
                    system("clear");
                    std::cout << "+---------+-------------------------------------+" << std::endl;
                    std::cout << "\033[1m| Britney | \033[0;31m" + fileName + ".bn" + "\t\033[0m" << std::endl;
                    std::cout << "\033[0m";
                    std::cout << "+---------+-------------------------------------+" << std::endl;
                    std::cin.ignore();
                    initscr();
                    noecho();
                    cbreak();
                    keypad(stdscr, true);
                    std::cin.ignore();
                    endwin();
                    files.close();
                }
                return 0;
                break;
            case '2':
                whileCheck = false;
                system("clear");
                FILE *fp;
                char path[1035];
                fp = popen("ls | grep .bn", "r");
                
                if (fgets(path, sizeof(path)-1, fp) != NULL){ 
                    std::cout << "+---------+-------------------------------------+" << std::endl;
                    std::cout << "\033[1m| Britney | \033[0;31mFiles available\t\t        \033[0m|" << std::endl; 
                    std::cout << "\033[0m";
                    std::cout << "+---------+-------------------------------------+" << std::endl;
                    while (fgets(path, sizeof(path)-1, fp) != NULL) {
                        std::cout << "| [" << z << "] " << path;
                        z++;
                    }
                    pclose(fp);
                    std::cout << "| [" << z << "] " << "Home" << std::endl;
                    std::cout << "+-----------------------------------------------+" << std::endl;
                    std::cout << "Which file would you like to open?: ";
                    std::cin >> fileSelector;
                    switch (fileSelector) {
                        case '1':
                            std::cout << path;
                            std::cin >> fileSelector;
                            files.close();
                            break;
                        case '3':
                            whileCheck = true;
                            break;
                    }
                } else {
                    std::cout << "\033[1mBritney | \033[0;31mNo files available!" << std::endl; 
                    std::cout << "\033[0m";
                    std::cout << "-----------------------------------------" << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
                    whileCheck = true;
                }
                break;
            case '3':
                break;
            case '4':
                whileCheck = false;
                system("clear");
                std::cout << "\t\t+---------+-------------------------------------+" << std::endl;
                std::cout << "\t\t\033[1m| Britney | \033[0;31mHelp file\t\t\t\t\033[0m|" << std::endl; 
                std::cout << "\033[0m";
                std::cout << "\t\t+---------+-------------------------------------+" << std::endl;
                std::cout << "\t\t| \033[1m¿How it works?\033[0m\t\t\t\t|" << std::endl;
                std::cout << "\t\t| To create a file go to the option one, insert |" << std::endl;
                std::cout << "\t\t| a name and then write into that file. To save |" << std::endl;
                std::cout << "\t\t| it press Ctrl + S.\t\t\t\t|" << std::endl;
                std::cout << "\t\t| In case you want to open a file press option  |" << std::endl;
                std::cout << "\t\t| two and select the .bn file you want to open. |" << std::endl;
                std::cout << "\t\t| \033[1mNote\033[0m: If the .bn file does not exist it will  |" << std::endl;
                std::cout << "\t\t| not appear, the program will only list the\t|" << std::endl;
                std::cout << "\t\t| current directory.\t\t\t\t|" << std::endl;
                std::cout << "\t\t+-----------------------------------------------+" << std::endl;
                std::cout << "" << std::endl;
                break;
            case '5':
                whileCheck = false;
                std::cout << "Closing Britney!";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                system("clear");
                break;
            default:
                whileCheck = true;
                i++;
                system("clear");
                break;
        }
    }
}
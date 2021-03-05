#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <algorithm>

void welcome()
{
    std::cout << "Welcome to this short quiz where you can test your general knowledge.\n"
        << "This test consists of multiple choice 5 questions - each correct answer is 1 point.\n"
        << "Press Enter key whenever you're ready and good luck!";
    std::cin.clear();
    std::cin.get();
    system("cls");
}

int main()
{
    std::array<std::string, 5> question{};
    std::array<std::string, 5> ansA{};
    std::array<std::string, 5> ansB{};
    std::array<std::string, 5> ansC{};
    std::array<std::string, 5> correct{};
    std::string answer{};
    int score{ 0 };
    
    welcome();
    
    std::ifstream in_file{};
    int line_nr{ 1 };
    int q_nr{};
    std::string line{};
    
    in_file.open("quiz.txt");

    if (!in_file)
    {
        std::cerr << "Couldn't open the file. Shutting down now." << std::endl;
        return 1;
    }
   
    while (std::getline(in_file,line))
    {
        switch (line_nr)
        {
        case 1: question[q_nr] = line; break;
        case 2:ansA[q_nr] = line; break;
        case 3:ansB[q_nr] = line; break;
        case 4:ansC[q_nr] = line; break;
        case 5:correct[q_nr] = line; break;
        }
        if (line_nr == 5) { line_nr = 0, q_nr++; }
        line_nr++;
    }

    in_file.close();

    for (size_t i = 0; i <=4; ++i)
    {
        std::cout <<"\n"<< question[i] << std::endl;
        std::cout << "A) "<< ansA[i] << std::endl;
        std::cout << "B) "<< ansB[i] << std::endl;
        std::cout << "C) "<< ansC[i] << std::endl;

        std::cout << "Your answer:";
        std::cin >> answer;

        if (answer==correct[i])
        {
            std::cout << "Correct! +1 point" << std::endl;
            score++;
        }else {
            std::cout << "Wrong answer." << std::endl;
        }
    }
    std::cout << "That's the end of this quiz. Your score is " << score << "/5" << std::endl;

    system("pause");
}

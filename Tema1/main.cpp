#include "include/player.h"
#include "include/item.h"
#include "include/case.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <cstdlib>
#include <time.h>
#include <windows.h>

int main()
{
    // rand seed to be unix time
    srand((int)time(NULL));

    // players
    std::vector<Player> players;
    players.push_back(Player("Fabi", 5000, "parolafabi"));
    players.push_back(Player("Tudi", 1000, "parolatudi"));
    players.push_back(Player("Cosmin", 2000, "parolacosmin"));
    players.push_back(Player("Vlad", 1000000, "parolavlad"));
    players.push_back(Player("Random", rand() % 1000000, "parolarandom"));

    // authetication method
    std::string inputPlayerName;
    std::string inputPassword;
    bool authenticated = false;
    float availableBalance = 0;

    while (!authenticated)
    {
        std::cout << "Enter your Username (or type 'exit' to quit): ";
        std::cin >> inputPlayerName;
        if (inputPlayerName == "exit")
            return 0;

        std::cout << "Enter your password: ";
        std::cin >> inputPassword;
        for (const auto &player : players)
        {
            if (player.authPassword(inputPassword) && player.authPlayerName(inputPlayerName))
            {
                Sleep(1500);
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "Authentication successful. Welcome, " << player.getName() << "!" << std::endl;
                // std::cout << "Your current balance is: $" << player.getBalance() << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                availableBalance = player.getBalance();
                authenticated = true;
                break;
            }
        }
        if (!authenticated)
        {
            Sleep(1500);
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "Authentication failed. Incorrect username or password. Wish to continue? ('y' / 'n')" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cin >> inputPlayerName;
            if (inputPlayerName == "n")
                return 0;
        }
    }

    // std::cout << "Current Balance: " << availableBalance << std::endl;

    // items
    Item item1("Dual Berettas | Hideout", 0.3, "blue");
    Item item2("Nova | Dark Sigil", 0.3, "blue");
    Item item3("Tec-9 | Slag", 0.4, "blue");
    Item item4("UMP-45 | Motorized", 0.35, "blue");
    Item item5("XM1014 | Irezumi", 0.3, "blue");
    Item item6("SSG 08 | Dezastre", 0.5, "blue");
    Item item7("MAC-10 | Light Box", 0.7, "blue");
    Item item8("MP7 | Just Smile", 2.15, "purple");
    Item item9("Sawed-Off | Analog Input", 2.3, "purple");
    Item item10("Five-SeveN | Hybrid", 2.25, "purple");
    Item item11("M4A4 | Etch Lord", 3, "purple");
    Item item12("Glock-18 | Block-18", 3.5, "purple");
    Item item13("USP-S | Jawbreaker", 15.5, "pink");
    Item item14("Zeus x27 | Olympus", 17, "pink");
    Item item15("M4A1-S | Black Lotus", 35, "pink");
    Item item16("AK-47 | Inheritance", 130, "red");
    Item item17("AWP | Chrome Cannon", 110, "red");
    Item item18("Kukri Knife | Vanilla", 1044, "gold");
    Item item19("Kukri Knife | Slaughter", 950, "gold");
    Item item20("Kukri Knife | Blue Steel", 650, "gold");
    Item item21("Kukri Knife | Case Hardened", 1000, "gold");
    Item item22("Kukri Knife | Crimson Web", 870, "gold");
    Item item23("Kukri Knife | Stained", 450, "gold");
    Item item24("Kukri Knife | Scorched", 400, "gold");
    Item item25("Kukri Knife | Forest DDPAT", 500, "gold");
    Item item26("Kukri Knife | Night Stripe", 550, "gold");
    Item item27("Kukri Knife | Safari Mesh", 350, "gold");
    Item item28("Kukri Knife | Urban Masked", 400, "gold");
    Item item29("Kukri Knife | Boreal Forest", 350, "gold");
    Item item30("Kukri Knife | Fade", 1500, "gold");

    // the case
    Case kwCase("Kilowatt Case", 5);
    // posibility to add more cases...
    kwCase.addItem(item1);
    kwCase.addItem(item2);
    kwCase.addItem(item3);
    kwCase.addItem(item4);
    kwCase.addItem(item5);
    kwCase.addItem(item6);
    kwCase.addItem(item7);
    kwCase.addItem(item8);
    kwCase.addItem(item9);
    kwCase.addItem(item10);
    kwCase.addItem(item11);
    kwCase.addItem(item12);
    kwCase.addItem(item13);
    kwCase.addItem(item14);
    kwCase.addItem(item15);
    kwCase.addItem(item16);
    kwCase.addItem(item17);
    kwCase.addItem(item18);
    kwCase.addItem(item19);
    kwCase.addItem(item20);
    kwCase.addItem(item21);
    kwCase.addItem(item22);
    kwCase.addItem(item23);
    kwCase.addItem(item24);
    kwCase.addItem(item25);
    kwCase.addItem(item26);
    kwCase.addItem(item27);
    kwCase.addItem(item28);
    kwCase.addItem(item29);
    kwCase.addItem(item30);

    std::string userInput;
    int userNumber;
    float spentOnCases = 0;
    float earnedFromCase = 0;
    float totalSpent = 0;
    float totalEarned = 0;
    int blueCounter = 0;
    int purpleCounter = 0;
    int pinkCounter = 0;
    int redCounter = 0;
    int goldCounter = 0;
    int totalBlueCounter = 0;
    int totalPurpleCounter = 0;
    int totalPinkCounter = 0;
    int totalRedCounter = 0;
    int totalGoldCounter = 0;

    Sleep(1500);

    while (true)
    {
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "What do you want to do next? (type the number)" << std::endl;
        std::cout << "(1) Open cases!" << std::endl;
        std::cout << "(2) Show balance." << std::endl;
        std::cout << "(3) Show case!" << std::endl;
        std::cout << "(4) Show analytics." << std::endl;
        std::cout << "(5) Top up balance :)" << std::endl;
        std::cout << "(6) Quit :/" << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

        std::cin >> userInput;
        Sleep(500);
        if (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5" && userInput != "6")
        {
            std::cout << "Only numbers... try again? ('y' / 'n')" << std::endl;
            std::cin >> userInput;
            if (userInput == "n" || userInput != "y")
            {
                std::cout << "Bye!" << std::endl;
                break;
            }
        }
        else if (userInput == "1")
        {
            while (true)
            {
                std::cout << "You got " << availableBalance << "$ left." << std::endl;
                std::cout << "Case price: " << kwCase.getCasePrice() << "$." << std::endl;
                std::cout << "How many cases do you want to open? ('-1' - all in, '0' - quit)" << std::endl;
                std::cin >> userNumber;
                if (userNumber == 0)
                    break;
                else
                {
                    Sleep(1000);
                    if (userNumber == -1)
                        userNumber = availableBalance / (kwCase.getCasePrice());
                    spentOnCases = userNumber * kwCase.getCasePrice();
                    earnedFromCase = 0;
                    if (availableBalance < spentOnCases)
                    {
                        std::cout << "Insufficient balance!" << std::endl;
                    }
                    else
                    {
                        std::cout << "Let's open..." << std::endl;
                        blueCounter = 0;
                        purpleCounter = 0;
                        pinkCounter = 0;
                        redCounter = 0;
                        goldCounter = 0;
                        // std::cout << "Money spent on cases: " << spentOnCases << std::endl;
                        for (int i = 1; i <= userNumber; i++)
                        {

                            Item selected = kwCase.openCase();
                            // std::cout << "You obtained: ";
                            // selected.printItem();
                            if (selected.getRarity() == "blue")
                                blueCounter++;
                            else if (selected.getRarity() == "purple")
                                purpleCounter++;
                            else if (selected.getRarity() == "pink")
                                pinkCounter++;
                            else if (selected.getRarity() == "red")
                                redCounter++;
                            else if (selected.getRarity() == "gold")
                                goldCounter++;
                            earnedFromCase += selected.getItemPrice();
                        }
                        availableBalance -= spentOnCases;
                        totalBlueCounter += blueCounter;
                        totalPurpleCounter += purpleCounter;
                        totalPinkCounter += pinkCounter;
                        totalRedCounter += redCounter;
                        totalGoldCounter += goldCounter;
                        Sleep(1000);
                        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                        if (blueCounter != 0)
                            std::cout << "You got " << blueCounter << " blues." << std::endl;
                        if (purpleCounter != 0)
                            std::cout << "You got " << purpleCounter << " purples." << std::endl;
                        if (pinkCounter != 0)
                            std::cout << "You got " << pinkCounter << " pinks!" << std::endl;
                        if (redCounter != 0)
                            std::cout << "You got " << redCounter << " reds!!" << std::endl;
                        if (goldCounter != 0)
                            std::cout << "You got " << goldCounter << " golds!!!" << std::endl;
                        std::cout << "You spent: " << spentOnCases << "$ on cases." << std::endl;
                        std::cout << "You earned items valued at: " << earnedFromCase << "$." << std::endl;
                        if (earnedFromCase - spentOnCases < 0)
                        {
                            std::cout << "So you lost: " << earnedFromCase - spentOnCases << "$. ";
                            std::cout << "That's " << ((spentOnCases - earnedFromCase) / spentOnCases) * 100 << "% of your money lost... Well done!" << std::endl;
                        }
                        else
                        {
                            std::cout << "So you earned: " << earnedFromCase - spentOnCases << "$. ";
                            std::cout << "That's " << ((earnedFromCase - spentOnCases) / spentOnCases) * 100 << "% profit ... Great!" << std::endl;
                        }
                        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                        totalEarned += earnedFromCase - spentOnCases;
                        totalSpent += spentOnCases;
                        availableBalance += earnedFromCase;
                    }
                    Sleep(1000);
                    std::cout << "Try again? ('y'/'n')" << std::endl;
                    std::cin >> userInput;
                    if (userInput == "n")
                    {
                        Sleep(500);
                        break;
                    }
                }
            }
        }
        else if (userInput == "2")
        {
            Sleep(1000);
            std::cout << "Current Balance: " << availableBalance << "$." << std::endl;
            Sleep(3000);
        }
        else if (userInput == "3")
        {
            std::cout << kwCase << std::endl;
        }
        else if (userInput == "4")
        {
            Sleep(1000);
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "You spent " << totalSpent << "$ on cases." << std::endl;
            if (totalEarned < 0)
                std::cout << "You lost: " << totalEarned << "$ opening cases. Bad luck?" << std::endl;
            else
                std::cout << "You earned: " << totalEarned << "$ opening cases. Suspicious..." << std::endl;
            if (totalBlueCounter != 0)
                std::cout << "You got " << totalBlueCounter << " blues." << std::endl;
            if (totalPurpleCounter != 0)
                std::cout << "You got " << totalPurpleCounter << " purples." << std::endl;
            if (totalPinkCounter != 0)
                std::cout << "You got " << totalPinkCounter << " pinks!" << std::endl;
            if (totalRedCounter != 0)
                std::cout << "You got " << totalRedCounter << " reds!!" << std::endl;
            if (totalGoldCounter != 0)
                std::cout << "You got " << totalGoldCounter << " golds!!!" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            Sleep(1000);
        }
        else if (userInput == "5")
        {
            Sleep(1000);
            availableBalance += 10000;
            std::cout << "You got an additional 10,000$." << std::endl;
            std::cout << "(99% of all gamblers stop before a lifechanging win...)" << std::endl;
            Sleep(1000);
        }
        else if (userInput == "6")
        {
            Sleep(500);
            std::cout << "Bye!" << std::endl;
            break;
        }
    }
    return 0;
}
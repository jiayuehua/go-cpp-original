#include "ConsoleUI.hpp"
#include <iostream>
#include <cassert>
#include <string>
#include <utility>

static const unsigned char kBorderTopLeftChar = '+';
static const unsigned char kBorderTopRightChar = '+';
static const unsigned char kBorderBottomLeftChar = '+';
static const unsigned char kBorderBottomRightChar = '+';
static const unsigned char kBorderTopChar = '=';
static const unsigned char kBorderRightChar = '=';
static const unsigned char kBorderBottomChar = '=';
static const unsigned char kBorderLeftChar = '=';
static const unsigned char kPointChar = '+';
static const unsigned char kPointSpacerChar = '-';

void printBoard ()
{
    std::cout << kBorderTopLeftChar << std::string((19*2)+1, kBorderTopChar) << kBorderTopRightChar << std::endl;;


    for (size_t i = 0; i < 19; ++i)
    {
        std::cout << kBorderLeftChar;
        for (size_t i = 0; i < 19; ++i)
        {
            std::cout << kPointSpacerChar;
            std::cout << kPointChar;
        }
        std::cout << kPointSpacerChar << kBorderRightChar << std::endl;
    }

    std::cout << kBorderBottomLeftChar << std::string((19*2)+1, kBorderBottomChar) << kBorderBottomRightChar << std::endl;;
}

namespace Go
{

ConsoleUI::ConsoleUI (const IPlayer & player)
  : m_player(player)
{ }

std::pair<size_t, size_t> ConsoleUI::promptForMove ()
{
    std::cout << m_player.getName() << ", enter move: " << std::endl;

    size_t x_coord = 0;
    size_t y_coord = 0;

    std::cin >> x_coord >> y_coord;

    return std::make_pair(x_coord, y_coord);
}

std::string ConsoleUI::promptForName ()
{
    std::cout << "Name for " << m_player.getName() << ": ";

    std::string playerName;
    std::cin >> playerName;

    return playerName;
}

Stone::Color ConsoleUI::promptForStoneColor ()
{
    std::cout << m_player.getName() << ", would you like to play as Black (0) or White (1): ";

    unsigned short choice = 0;
    std::cin >> choice;

    assert(choice == 0 || choice == 1);

    return (choice == 0) ? Stone::Color::BLACK : Stone::Color::WHITE;
}

void ConsoleUI::updateGameState ()
{
    if (m_updateCount == 0)
      std::cout << m_player.getName() << " is ready!" << std::endl;
    else
    {
      printBoard();
    }

    ++m_updateCount;
}

};
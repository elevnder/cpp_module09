/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:38:51 by marvin            #+#    #+#             */
/*   Updated: 2025/10/14 10:29:15 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include "../includes/colors.hpp"
#include <utility>
#include <cstdlib>

std::string trim(std::string& str){
    std::string s = str;
    s.erase(s.find_last_not_of(" \t") + 1);
    s.erase(0, s.find_first_not_of(" \t"));
    return s;
}

/*****************************CONSTRUCTEURS*********************************** */

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
    *this = other;
}

BitcoinExchange::BitcoinExchange(int argc, std::string arg){
    this->parseArg(argc, arg);
}

/*******************************DESTRUCTEURS*********************************** */

BitcoinExchange::~BitcoinExchange(){

}

/*********************************OPERATEURS*********************************** */

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src){
    if(this != &src)
    {
        this->_database = src._database;
    }
    return(*this);
}

/************************************METHODES*********************************** */

void BitcoinExchange::parseArg(int argc, std::string arg){
    if(argc != 2)
        throw NotEnoughArgumentsException();
    if(arg.empty())
        throw WrongFormatException();
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream fichier(filename.c_str());
    if (!fichier.is_open())
        throw FileProblemException();

    std::string line;
    std::getline(fichier, line);

    while (std::getline(fichier, line))
    {
        std::stringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, ','))
            continue;
        if (!std::getline(ss, valueStr))
            continue;

        std::istringstream valueStream(valueStr);
        float value;
        valueStream >> value;

        if (valueStream.fail())
        {
            std::cerr << BOLDRED << "Erreur de conversion pour la ligne : " << line << std::endl;
            continue;
        }
        if(!isValidDate(date) || value < 0)
        {
            std::cerr << BOLDRED << "Erreur de donnée invalide dans la base : " << line << std::endl;
            continue;
        }
        this->_database.insert(std::make_pair(date, value));
    }

    fichier.close();
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream fichier(filename.c_str());
    if (!fichier.is_open())
        throw FileProblemException();

    std::string line;
    std::getline(fichier, line);

    while (std::getline(fichier, line))
    {
        std::stringstream ss(line);
        std::string date, valueStr;
        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)){
            std::cerr << BOLDRED << "Error: bad input : " << line << std::endl;
            continue;
        }
        std::istringstream valueStream(valueStr);
        float value;
        valueStream >> value;
        if (valueStream.fail())
        {
            std::cerr << BOLDRED << "Error: bad input : " << line << std::endl;
            continue;
        }
        date = trim(date);
        valueStr = trim(valueStr);
        if(!this->isValidDate(date)){
            std::cerr << BOLDRED << "Error: bad date => " << date << std::endl;
            continue;
        }
        if(value < 0){
            std::cerr << BOLDRED << "Error: not a positive number." << std::endl;
            continue;
        }
        if(value > 1000){
            std::cerr << BOLDRED << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string, float>::iterator it = _database.lower_bound(date);
        if(it == _database.begin() && it->first > date){
            std::cerr << BOLDRED << "Error: no earlier rate for date " << date << std::endl;
            continue;
        }
        if(it == _database.end() || it->first != date)
            --it;

        std::cout << BOLDGREEN << date << " => " << BOLDYELLOW << value << " = " << value * it->second << std::endl;
    }

    fichier.close();
}
void BitcoinExchange::executeArg(std::string arg)
{
    this->loadDatabase("data.csv");
    this->processInput(arg);
}

bool BitcoinExchange::isValidDate(const std::string &date){
    if(date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if(year < 1900 ||  year > 2100 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
        
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;
    return day <= daysInMonth[month - 1];
}

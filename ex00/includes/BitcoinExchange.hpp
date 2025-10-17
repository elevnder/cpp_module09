/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:39:11 by marvin            #+#    #+#             */
/*   Updated: 2025/10/15 08:48:35 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

class BitcoinExchange
{
    public:

                /*Constructeurs*/
                    BitcoinExchange();
                    BitcoinExchange(const BitcoinExchange& other);
                    BitcoinExchange(int argc, std::string arg);

                /*Destructeurs*/
                    ~BitcoinExchange();

                /*Surcharge opérateur*/
                    BitcoinExchange& operator=(const BitcoinExchange& other);
                /*Méthodes*/
                    void parseArg(int argc, std::string arg);
                    void executeArg(std::string arg);
                    void loadDatabase(const std::string &filename);
                    void processInput(const std::string &filename);
                    bool isValidDate(const std::string &date);
                /*Exceptions*/

                    class NotEnoughArgumentsException : public std::exception
                    {
                        public:
                            const char* what() const throw(){
                                return "Mauvais nombre d'arguments";
                            }
                    };
                    class WrongFormatException : public std::exception
                    {
                        public:
                            const char* what() const throw(){
                                return "Mauvais format";
                            }
                    };
                    class FileProblemException : public std::exception
                    {
                        public:
                            const char* what() const throw(){
                                return "Impossible d'ouvrir le fichier";
                            }
                    };


    private:
                /* Attributs */
                std::map<std::string, float> _database;
};


#endif
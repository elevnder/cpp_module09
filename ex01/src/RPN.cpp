/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:43:30 by earnera           #+#    #+#             */
/*   Updated: 2025/10/17 10:18:27 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/**************************************************************************** */

int hasgoodchar(std::string str)
{
    const std::string valid = "0123456789+-*/";
    return valid.find(str) != std::string::npos;
}

/*****************************CONSTRUCTEURS********************************** */

RPN::RPN(){}

RPN::RPN(int argc, char **arg)
{
    this->calculateArg(argc, arg);
}

/******************************DESTRUCTEURS********************************** */

RPN::~RPN(){}

/********************************OPERATEURS********************************** */


const RPN &RPN::operator=(const RPN &src){
    if(&src != this)
        this->_data = src._data;
    return(*this);
}

/*********************************METHODES*********************************** */


void RPN::calculateArg(int argc, char **arg)
{
    if(argc != 2)
        throw NotEnoughArgumentsException();
        
    std::string         str = arg[1], input;
    std::istringstream  stringstream(str);
    
    while(stringstream >> input)
    {
        if(input.size() != 1 || !hasgoodchar(input))
            throw WrongFormatException();
            
        char c = input[0];
        
        if(std::isdigit(c))
        {
            
            this->_data.push(c - '0');
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (this->_data.size() < 2)
                throw WrongInputException();

            int b = this->_data.top();
            this->_data.pop();
            int a = this->_data.top();
            this->_data.pop();
            switch(c)
            {
                case '+' :
                {
                    this->_data.push(a + b);
                    break;
                }
                case '*' :
                {
                    this->_data.push(a * b);
                    break;
                }
                case '-' :
                {
                    this->_data.push(a - b);
                    break;
                }
                case '/' :
                {
                    if(b == 0)
                        throw WrongDivisionFormat();
                    this->_data.push(a / b);
                    break;
                }
            }
        }
        else
            throw WrongFormatException();
    }
    if(this->_data.size() != 1)
        throw WrongFormatException();
    std::cout << BOLDGREEN << this->_data.top() << std::endl;
}
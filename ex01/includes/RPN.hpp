/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:45:53 by earnera           #+#    #+#             */
/*   Updated: 2025/10/17 10:16:52 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>

#include "../includes/colors.hpp"

class RPN {
    public :
         /*Constructeurs*/
            RPN();
            RPN(int argc, char **arg);
            RPN(const RPN &src);     
        /*Destructeurs*/
            ~RPN();
        /*Opérateurs*/
            const RPN &operator=(const RPN &);
        /*Méthodes*/
            // void parseArgs(int argc, char **argv);
            void calculateArg(int argc, char **argv);
        /*Attributs*/
            std::stack<int> _data;
        /*Exceptions*/
            class WrongFormatException : public std::exception
            {
                public:
                            const char* what() const throw()
                            {
                                return "Erreur de format";
                            }
            };
            class NotEnoughArgumentsException : public std::exception
            {
                public:
                            const char* what() const throw()
                            {
                                return "Allez sois pas avare comme ça";
                            }
            };
            class WrongInputException : public std::exception
            {
                public:
                            const char* what() const throw()
                            {
                                return "Oui bah relis un peu avant de m'envoyer n'importe quoi";
                            }
            };
            class WrongDivisionFormat : public std::exception
            {
                public:
                            const char* what() const throw()
                            {
                                return "T'es sérieux là tu veux vrm diviser par 0 ???";
                            }
            };
            
    private :
        
};

#endif
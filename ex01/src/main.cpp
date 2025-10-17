/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:43:43 by earnera           #+#    #+#             */
/*   Updated: 2025/10/16 15:36:59 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char **argv)
{
    
    try
    {
        RPN rpn(argc, argv);
    }
    catch(std::exception &e)
    {
        std::cout << BOLDRED << "Erreurrrr : " << e.what() << std::endl;
    }
    std::cout << DEFAULTCOL << std::endl;
    return 0;
}
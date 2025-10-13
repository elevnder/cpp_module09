/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:39:59 by marvin            #+#    #+#             */
/*   Updated: 2025/10/13 15:12:09 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include "../includes/colors.hpp"

int main(int argc, char **argv)
{
    try{
        BitcoinExchange btc(argc, argv[1]);
        btc.executeArg(argv[1]);
    }
    catch (std::exception &e){
        std::cout << BOLDRED << e.what() << std::endl;
    }
    std::cout << DEFAULTCOL;
    return 0;
}
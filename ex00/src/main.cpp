/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:39:59 by marvin            #+#    #+#             */
/*   Updated: 2025/10/02 12:39:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main()
{
    std::ifstream fichier("data.csv");
    std::string line;

    if(fichier.is_open())
    {
        while(getline(fichier, line))
        {
            std::stringstream           ss(line);
            std::string                 champ;
            std::vector<std::string>    array;
            
            while(std::getline(ss, champ, ',')){
                array.push_back(champ);
            }

            for (const auto &val : array){
                std::cout << val << " ";
            }

            std::cout << std::endl;
        }
    }
}
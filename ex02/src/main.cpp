/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:14:16 by earnera           #+#    #+#             */
/*   Updated: 2025/11/17 15:21:59 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PMergeMe.hpp"

// std::string convertArg(char **arg)
// {
//     std::string str;
//     for(int i = 1; arg[i]; i++)
//     {
//         str.append(arg[i]);
//         if(arg[i + 1])
//             str.append(" ");
//     }
//     return(str);
// }

int main(int argc, char **argv){
    if(argc < 2){
        std::cerr << BOLDRED << "Error : no input numbers" << DEFAULTCOL << std::endl;
        return 1;
    }
    // std::string str = convertArg(argv);
    std::cout << BOLDBLUE << "*~~~~~~~~~~~~~~~~~~~~~~~~~Sort~~~~~~~~~~~~~~~~~~~~~~~~*" << std::endl;
    PMergeMe PMM(argv);
    PMM.displayUnsorted();
    PMM.displaySort();
    // std::cout << BOLDBLUE << "*~~~~~~~~~~~~~~~~~~~~~~~~~~Deque~~~~~~~~~~~~~~~~~~~~~~~~*" << std::endl;
    // PMM.displayUnsorted();
    // PMM.displaySort();
    // std::cout << DEFAULTCOL;
    return 0;
}
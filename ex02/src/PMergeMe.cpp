/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:55:56 by earnera           #+#    #+#             */
/*   Updated: 2025/10/17 11:20:42 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PMergeMe.hpp"

/**************************************************************************** */

int hasgoodchar(std::string str)
{
    const std::string valid = "0123456789+-*/";
    return valid.find(str) != std::string::npos;
}

/*****************************CONSTRUCTEURS********************************** */

PMergeMe::PMergeMe(void) {}

PMergeMe::PMergeMe(std::string sequence) {
    (void)sequence;
}


PMergeMe(const PMergeMe &copy);

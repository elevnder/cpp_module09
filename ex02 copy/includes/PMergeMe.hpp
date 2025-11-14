/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:01:28 by earnera           #+#    #+#             */
/*   Updated: 2025/11/04 14:44:53 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMergeMe_HPP
#define PMergeMe_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <bits/stdc++.h>

#include "./colors.hpp"

class PMergeMe{
    public :
        /*Constructeurs*/
            PMergeMe();
            PMergeMe(char **argv);
            PMergeMe(const PMergeMe &copy);
        /*Destructeurs*/
            ~PMergeMe();
        /*Opérateurs*/
            const PMergeMe &operator=(const PMergeMe &src);
        /*Méthodes*/
            void displayUnsorted();
            void displaySort();
            void sortVector();
        /*Attributs*/
        std::vector<int> _vector;
        std::list<int> _list;
        
    private :
    
};

#endif
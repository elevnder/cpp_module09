/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:01:28 by earnera           #+#    #+#             */
/*   Updated: 2025/11/17 15:12:07 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMergeMe_HPP
#define PMergeMe_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
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
            /*****Vector****** */
            std::vector<int>                                    mergeInsertSort(std::vector<int> input);
            std::vector<int>                                    insertJacobsthal(std::vector<int> bigs, std::vector<int> smalls);
            std::pair<std::vector<std::pair<int,int> >, int>    make_pairs(const std::vector<int> &input);
            /******List******* */
            std::deque<int>                                     mergeInsertSort(std::deque<int> input);
            std::deque<int>                                     insertJacobsthal(std::deque<int> bigs, std::deque<int> smalls);
            std::pair<std::deque<std::pair<int,int> >, int>     make_pairs(const std::deque<int> &input);
            

            int                                                 JacobsthalNum(int n);
        /*Attributs*/
        std::vector<int> _vector;
        std::deque<int> _deque;
        int             last;
        
    private :
    
};

#endif
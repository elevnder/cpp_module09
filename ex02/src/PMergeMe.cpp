/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:55:56 by earnera           #+#    #+#             */
/*   Updated: 2025/11/17 15:21:42 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PMergeMe.hpp"

#define JACOBSTHAL = [3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123, 22906492245, 45812984491, 91625968981, 183251937963, 366503875925, 733007751851, 1466015503701, 2932031007403, 5864062014805, 11728124029611, 23456248059221, 46912496118443]

/**************************************************************************** */



/*****************************CONSTRUCTEURS********************************** */

PMergeMe::PMergeMe(void) {}

PMergeMe::PMergeMe(char **argv) {
    for (int i = 1; argv[i]; i++)
        this->_vector.push_back(std::atoi(argv[i]));
    for (int j = 1; argv[j]; j++)
        this->_deque.push_back(std::atoi(argv[j]));
}


PMergeMe::PMergeMe(const PMergeMe &copy){
    *this = copy;
}

PMergeMe::~PMergeMe() {
}


/********************************OPERATEURS********************************** */


const PMergeMe &PMergeMe::operator=(const PMergeMe &src){
    if(&src != this)
    {
        this->_vector = src._vector;
        this->_deque = src._deque;
    }
    return(*this);
}
/********************************METHODES********************************** */



int PMergeMe::JacobsthalNum(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    int a = 0; 
    int b = 1; 
    int c;
    for(int i = 2; i <= n; ++i)
    {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

void    PMergeMe::displayUnsorted() {
    std::cout << BOLDPEACH << "Before sorting vector : ";
    std::copy(this->_vector.begin(), this->_vector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << DEFAULTCOL << std::endl;
    std::cout << BOLDPEACH << "Before sorting deque : ";
    std::copy(this->_deque.begin(), this->_deque.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << DEFAULTCOL << std::endl;
}
void    PMergeMe::displaySort() {
    this->_vector = this->mergeInsertSort(this->_vector);
    std::cout << BOLDGREEN << "After sorting vector : ";
    std::copy(this->_vector.begin(), this->_vector.end(), std::ostream_iterator<int>(std::cout, " "));
    // this->displayTime();
    std::cout << DEFAULTCOL << std::endl;
    this->_deque = this->mergeInsertSort(this->_deque);
    std::cout << BOLDGREEN << "After sorting deque : ";
    std::copy(this->_deque.begin(), this->_deque.end(), std::ostream_iterator<int>(std::cout, " "));
    // this->displayTime();
    std::cout << DEFAULTCOL << std::endl;
}


/**********************************VECTOR********************************************* */

std::pair<std::vector<std::pair<int,int> >, int> PMergeMe::make_pairs(const std::vector<int> &input)
{
    std::vector<std::pair<int, int> > pairs;
    int last = -1;

    for (size_t j = 0; j + 1 < input.size(); j += 2)
        pairs.push_back(std::make_pair(input[j], input[j + 1]));

    if (input.size() % 2 != 0)
        last = input.back();

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    return std::make_pair(pairs, last);
}



std::vector<int> PMergeMe::mergeInsertSort(std::vector<int> input)
{
    if (input.size() <= 1)
        return input;

    std::pair<std::vector<std::pair<int,int> >, int> pair_result = make_pairs(input);
    std::vector<std::pair<int,int> > pairs = pair_result.first;
    int last = pair_result.second;

    std::vector<int> bigs;
    std::vector<int> smalls;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        bigs.push_back(pairs[i].second);
        smalls.push_back(pairs[i].first);
    }

    bigs = mergeInsertSort(bigs);

    std::vector<int> sorted = insertJacobsthal(bigs, smalls);

    if (last != -1)
        sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), last), last);

    return sorted;
}


std::vector<int> PMergeMe::insertJacobsthal(std::vector<int> bigs, std::vector<int> smalls)
{
    std::vector<int> order;

    int n = smalls.size();

    for(int k = 2; ; ++k)
    {
        int index = JacobsthalNum(k) - 1;
        if(index >= n)
            break;
        order.push_back(index);
    }

    for(int i = n - 1; i >= 0; --i)
    {
        if(std::find(order.begin(), order.end(), i) == order.end())
            order.push_back(i);
    }

    for(size_t i = 0; i < order.size(); ++i)
    {
        int val = smalls[order[i]];
        bigs.insert(std::lower_bound(bigs.begin(), bigs.end(), val), val);
        
    }

    return(bigs);
}
/**************************************DEQUE******************************************* */

std::deque<int> PMergeMe::mergeInsertSort(std::deque<int> input)
{
    if (input.size() <= 1)
        return input;

    std::pair<std::deque<std::pair<int,int> >, int> pair_result = make_pairs(input);
    std::deque<std::pair<int,int> > pairs = pair_result.first;
    int last = pair_result.second;

    std::deque<int> bigs;
    std::deque<int> smalls;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        bigs.push_back(pairs[i].second);
        smalls.push_back(pairs[i].first);
    }

    bigs = mergeInsertSort(bigs);

    std::deque<int> sorted = insertJacobsthal(bigs, smalls);

    if (last != -1)
        sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), last), last);

    return sorted;
}


std::deque<int> PMergeMe::insertJacobsthal(std::deque<int> bigs, std::deque<int> smalls)
{
    std::deque<int> order;

    int n = smalls.size();

    for(int k = 2; ; ++k)
    {
        int index = JacobsthalNum(k) - 1;
        if(index >= n)
            break;
        order.push_back(index);
    }

    for(int i = n - 1; i >= 0; --i)
    {
        if(std::find(order.begin(), order.end(), i) == order.end())
            order.push_back(i);
    }

    for(size_t i = 0; i < order.size(); ++i)
    {
        int val = smalls[order[i]];
        bigs.insert(std::lower_bound(bigs.begin(), bigs.end(), val), val);
        
    }

    return(bigs);
}

std::pair<std::deque<std::pair<int,int> >, int> PMergeMe::make_pairs(const std::deque<int> &input)
{
    std::deque<std::pair<int, int> > pairs;
    int last = -1;

    for (size_t j = 0; j + 1 < input.size(); j += 2)
        pairs.push_back(std::make_pair(input[j], input[j + 1]));

    if (input.size() % 2 != 0)
        last = input.back();

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    return std::make_pair(pairs, last);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:55:56 by earnera           #+#    #+#             */
/*   Updated: 2025/11/06 10:48:08 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PMergeMe.hpp"

/**************************************************************************** */



/*****************************CONSTRUCTEURS********************************** */

PMergeMe::PMergeMe(void) {}

PMergeMe::PMergeMe(char **argv) {
    for (int i = 1; argv[i]; i++)
        this->_vector.push_back(std::atoi(argv[i]));
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
        this->_list = src._list;
    }
    return(*this);
}
/********************************METHODES********************************** */

void PMergeMe::sortVector() {
    std::vector<std::pair<int, int> > _temp;
    
    for(size_t j = 0; j + 1 < this->_vector.size(); j += 2)
        _temp.push_back(std::make_pair(this->_vector[j], this->_vector[j + 1]));
    int last = -1;
    if(this->_vector.size() % 2 != 0)
        last = this->_vector.back();
    int n = _temp.size();
    for (int i = 0; i < n; i++)
    {
        if(_temp[i].first > _temp[i].second)
            std::swap(_temp[i].first, _temp[i].second);
    }

    
    // std::sort(_temp.begin(), _temp.end());
    /*REMETTRE LE TABLEAU ; à garder pr la fin*/
    this->_vector.clear();
    this->_vector.reserve(_temp.size() * 2);
    for (std::vector < std::pair<int, int> >::const_iterator it = _temp.begin(), end_it = _temp.end(); it != end_it; ++it)
    {
        this->_vector.push_back(it->first);
        this->_vector.push_back(it->second);
    }
    if(last != -1)
        this->_vector.push_back(last);

}

void    PMergeMe::displayUnsorted() {
    std::cout << BOLDPEACH << "Before sorting : ";
    std::copy(this->_vector.begin(), this->_vector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << DEFAULTCOL << std::endl;
}
void    PMergeMe::displaySort() {
    this->sortVector();
    std::cout << BOLDGREEN << "After sorting : ";
    std::copy(this->_vector.begin(), this->_vector.end(), std::ostream_iterator<int>(std::cout, " "));
    // this->displayTime();
    std::cout << DEFAULTCOL << std::endl;
}
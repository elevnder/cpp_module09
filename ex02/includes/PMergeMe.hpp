/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:01:28 by earnera           #+#    #+#             */
/*   Updated: 2025/10/17 11:22:06 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMergeMe_HPP
#define PMergeMe_HPP

#include <iostream>
#include <string>

#include "./colors.hpp"

class PMergeMe{
    public :
        /*Constructeurs*/
            PMergeMe();
            PMergeMe(std::string sequence);
            PMergeMe(const PMergeMe &copy);
        /*Destructeurs*/
            ~PMergeMe();
        /*Opérateurs*/
            const PMergeMe &operator =(const PMergeMe &src);
        /*Méthodes*/
        
        /*Attributs*/
        
        
    private :
    
};

#endif
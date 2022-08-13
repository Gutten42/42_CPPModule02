/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:39:43 by vgutten           #+#    #+#             */
/*   Updated: 2022/08/13 15:00:19 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed ( void ): _n(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed ( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed ( Fixed const & to_copy )/*: _n(to_copy.getRawBits())*/ {
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed &	Fixed::operator=( Fixed const & to_assign ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_n = to_assign.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _n;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;
}

const int	Fixed::frac = 8;

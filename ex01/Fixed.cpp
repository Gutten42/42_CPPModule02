/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:39:43 by vgutten           #+#    #+#             */
/*   Updated: 2022/08/13 16:54:33 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed ( void ): _n(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed ( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed ( Fixed const & to_copy ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::Fixed( int const n ) {
	std::cout << "Int constructor called" << std::endl;
	this->_n = n * pow(2, frac);
}

Fixed::Fixed( float const n ) {
	std::cout << "Float constructor called" << std::endl;
	this->_n = (int)roundf(n * pow(2, frac));
}

Fixed &	Fixed::operator=( Fixed const & to_assign ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_n = to_assign.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const {
	return _n;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)_n / pow(2, frac);
}

int	Fixed::toInt( void ) const {
	return _n / pow(2, frac);
}

std::ostream &	operator<<( std::ostream & o, Fixed const & output ) {
	o << output.toFloat();
	return o;
}

const int	Fixed::frac = 8;

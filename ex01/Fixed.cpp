/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgutten <vgutten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:39:43 by vgutten           #+#    #+#             */
/*   Updated: 2022/05/30 14:35:06 by vgutten          ###   ########.fr       */
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

Fixed::Fixed ( Fixed const & to_copy )/*: _n(to_copy.getRawBits())*/ {
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::Fixed( int const n ) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n * pow(2, frac));
}

Fixed::Fixed( float const n ) {
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(n * pow(2, frac)));
}

Fixed &	Fixed::operator=( Fixed const & to_assign ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_n = to_assign.getRawBits();
//	this->setRawBits(to_assign.getRawBits());
	return *this;
}

int	Fixed::getRawBits( void ) const {
//	std::cout << "getRawBits member function called" << std::endl;
	return _n;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)this->getRawBits() / pow(2, frac);
}

int	Fixed::toInt( void ) const {
	return this->getRawBits() / pow(2, frac);
}

std::ostream &	operator<<( std::ostream & o, Fixed const & output ) {
	o << output.toFloat();
	return o;
}

const int	Fixed::frac = 8;
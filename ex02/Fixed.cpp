/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgutten <vgutten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:39:43 by vgutten           #+#    #+#             */
/*   Updated: 2022/05/30 21:02:20 by vgutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed ( void ): _n(0) {
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed ( void ) {
//	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed ( Fixed const & to_copy )/*: _n(to_copy.getRawBits())*/ {
//	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::Fixed( int const n ) {
//	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n * pow(2, frac));
}

Fixed::Fixed( float const n ) {
//	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(n * pow(2, frac)));
}

Fixed &	Fixed::operator=( Fixed const & to_assign ) {
//	std::cout << "Assignation operator called" << std::endl;
	this->_n = to_assign.getRawBits();
//	this->setRawBits(to_assign.getRawBits());
	return *this;
}

bool	Fixed::operator>( Fixed const & to_compare ) const {
	if (this->getRawBits() > to_compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<( Fixed const & to_compare ) const {
	if (this->getRawBits() < to_compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=( Fixed const & to_compare ) const {
	if (this->getRawBits() >= to_compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=( Fixed const & to_compare ) const {
	if (this->getRawBits() <= to_compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==( Fixed const & to_compare ) const {
	if (this->getRawBits() == to_compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=( Fixed const & to_compare ) const {
	if (this->getRawBits() != to_compare.getRawBits())
		return true;
	return false;
}

Fixed	Fixed::operator+( Fixed const & sum ) const {
	Fixed	copy;
	copy.setRawBits(this->getRawBits() + sum.getRawBits());
	return copy;
}

Fixed	Fixed::operator-( Fixed const & sum ) const{
	Fixed	copy;
	copy.setRawBits(this->getRawBits() - sum.getRawBits());
	return copy;
}

Fixed	Fixed::operator*( Fixed const & sum ) const{
	Fixed	copy(this->toFloat() * sum.toFloat());
	//std::cout << "I'm the multiplier and I'm going to multiply " << this->getRawBits() << " and " << sum.getRawBits() << std::endl;
	//copy.setRawBits(this->getRawBits() * sum.getRawBits() / pow(2, frac));
	return copy;
}

Fixed	Fixed::operator/( Fixed const & sum ) const{
	Fixed	copy(this->toFloat() / sum.toFloat());
//	copy.setRawBits(this->getRawBits() / sum.getRawBits() * pow(2, frac));
	return copy;
}

/*Fixed &	Fixed::operator++( void ) {
	this->setRawBits(this->getRawBits + 1);
	return *this;
}

Fixed	Fixed::operator++( Fixed const & to_incr, int n ) {
	return Fixed( to_incr.getRawBits() + 1 );	
}

Fixed &	Fixed::operator--( void ) {
	this->setRawBits(this->getRawBits - 1);
	return *this;
}

Fixed	Fixed::operator--( Fixed const & to_incr, int n ) {
	return Fixed( to_incr.getRawBits() - 1 );	
}*/

/*Fixed &	Fixed::operator++( Fixed & to_incr ) {
	to_incr.setRawBits(to_incr.getRawBits() + 1);
	return to_incr;
}

Fixed	Fixed::operator++( Fixed & to_incr, int incr ) {
	return Fixed(to_incr.getRawBits() + incr);
}

Fixed &	Fixed::operator--( Fixed & to_decr ) {
	to_decr.setRawBits(to_decr.getRawBits() - 1);
	return to_decr;
}

Fixed	Fixed::operator--( Fixed & to_decr, int decr ) {
	return Fixed(to_decr.getRawBits() - decr);
}*/

Fixed &	Fixed::operator++( void ) {
//	std::cout << "Pre-increment operator called" << std::endl;
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed	Fixed::operator++( int incr ) {
//	std::cout << "Post-increment operator called" << std::endl;
	if (!incr)
		incr = 1;
	Fixed	copy = *this;
	this->setRawBits(this->getRawBits() + incr);
	return copy;
}

Fixed &	Fixed::operator--( void ) {
//	std::cout << "Pre-decrement operator called" << std::endl;
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator--( int decr ) {
//	std::cout << "Post-decrement operator called" << std::endl;
	if (!decr)
		decr = 1;
	Fixed	copy = *this;
	this->setRawBits(this->getRawBits() - decr);
	return copy;
}

int	Fixed::getRawBits( void ) const {
//	std::cout << "getRawBits member function called" << std::endl;
	return _n;
}

void	Fixed::setRawBits( int const raw ) {
//	std::cout << "setRawBits member function called" << std::endl;
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

int &	Fixed::min( int & a, int & b ) {
	if (b < a)
		return b;
	return a;
}

const Fixed &	Fixed::min( Fixed const & a, Fixed const & b ) {
	if (b.getRawBits() < a.getRawBits())
		return b;
	return a;
}

int &	Fixed::max( int & a, int & b ) {
	if (b > a)
		return b;
	return a;
}

const Fixed &	Fixed::max( Fixed const & a, Fixed const & b ) {
	if (b.getRawBits() > a.getRawBits())
		return b;
	return a;
}

const int	Fixed::frac = 8;
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:39:43 by vgutten           #+#    #+#             */
/*   Updated: 2022/08/13 17:06:04 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed ( void ): _n(0) {
}

Fixed::~Fixed ( void ) {
}

Fixed::Fixed ( Fixed const & to_copy ) {
	*this = to_copy;
}

Fixed::Fixed( int const n ) {
	this->_n = n * pow(2, frac);
}

Fixed::Fixed( float const n ) {
	this->_n = (int)roundf(n * pow(2, frac));
}

Fixed &	Fixed::operator=( Fixed const & to_assign ) {
	this->_n = to_assign.getRawBits();
	return *this;
}

bool	Fixed::operator>( Fixed const & to_compare ) const {
	if (_n > to_compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<( Fixed const & to_compare ) const {
	if (_n < to_compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=( Fixed const & to_compare ) const {
	if (_n >= to_compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=( Fixed const & to_compare ) const {
	if (_n <= to_compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==( Fixed const & to_compare ) const {
	if (_n == to_compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=( Fixed const & to_compare ) const {
	if (_n != to_compare.getRawBits())
		return true;
	return false;
}

Fixed	Fixed::operator+( Fixed const & sum ) const {
	Fixed	copy;
	copy.setRawBits(_n + sum.getRawBits());
	return copy;
}

Fixed	Fixed::operator-( Fixed const & sum ) const{
	Fixed	copy;
	copy.setRawBits(_n - sum.getRawBits());
	return copy;
}

Fixed	Fixed::operator*( Fixed const & sum ) const{
	Fixed	copy(this->toFloat() * sum.toFloat());
	return copy;
}

Fixed	Fixed::operator/( Fixed const & sum ) const{
	Fixed	copy(this->toFloat() / sum.toFloat());
	return copy;
}

Fixed &	Fixed::operator++( void ) {
	_n = _n + 1;
	return *this;
}

Fixed	Fixed::operator++( int incr ) {
	if (!incr)
		incr = 1;
	Fixed	copy = *this;
	_n = _n + incr;
	return copy;
}

Fixed &	Fixed::operator--( void ) {
	_n = _n - 1;
	return *this;
}

Fixed	Fixed::operator--( int decr ) {
	if (!decr)
		decr = 1;
	Fixed	copy = *this;
	_n = _n - decr;
	return copy;
}

int	Fixed::getRawBits( void ) const {
	return _n;
}

void	Fixed::setRawBits( int const raw ) {
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

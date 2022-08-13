/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:26:13 by vguttenb          #+#    #+#             */
/*   Updated: 2022/08/13 14:37:47 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ): x(0), y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::~Point( void ) {
	std::cout << "Default destructor called" << std::endl;
}

Point::Point( Point & to_copy ): x(to_copy.getX()), y(to_copy.getY()) {
	std::cout << "Copy constructor called" << std::endl;
	//*this = to_copy;
}

Point::Point( Fixed const & nx, Fixed const & ny ): x(nx), y(ny) {
	std::cout << "2 Fixed constructor called" << std::endl;
	//this->x.setRawBits(nx.getRawBits());
	//this->y.setRawBits(ny.getRawBits());
}

Point &	Point::operator=( Point const & to_assign ) {
	std::cout << "You can't reassign this class as its variable are consts" << std::endl;
	(void)to_assign;
//	this->~Point();
//	return Point(to_assign);
//	this->x = to_assign.getX();
//	this->y = to_assign.getY();
	//*this = to_assign;
	return *this;
}

Fixed const &	Point::getX( void ) const {
	return this->x;
}

Fixed const &	Point::getY( void ) const {
	return this->y;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:26:13 by vguttenb          #+#    #+#             */
/*   Updated: 2022/08/13 17:05:00 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ): x(0), y(0) {
}

Point::~Point( void ) {
}

Point::Point( Point & to_copy ): x(to_copy.getX()), y(to_copy.getY()) {
}

Point::Point( Fixed const & nx, Fixed const & ny ): x(nx), y(ny) {
}

Point &	Point::operator=( Point const & to_assign ) {
	std::cout << "Point class error: You can't reassign this class as its variable are consts" << std::endl;
	(void)to_assign;
	return *this;
}

Fixed const &	Point::getX( void ) const {
	return this->x;
}

Fixed const &	Point::getY( void ) const {
	return this->y;
}

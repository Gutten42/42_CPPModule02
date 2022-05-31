/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:45:35 by vguttenb          #+#    #+#             */
/*   Updated: 2022/05/31 18:23:04 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"


Point *	intersecX( Point const & p1, Point const & p2, Fixed const x) {
		std::cout << "p1 is " << p1.getX() << "x and " << p1.getY() << "y" << std::endl;
		std::cout << "p2 is " << p2.getX() << "x and " << p2.getY() << "y" << std::endl;
		std::cout << "x is " << x << std::endl;
		if (p1.getY() == p2.getY())
			return new Point(x, p1.getY());
		if (p1.getX() == p2.getX())
			return NULL;
		Fixed	slope = ( p1.getY() - p2.getY() ) / ( p1.getX() - p2.getX() );
		Fixed	incr = p1.getY() - slope * p1.getX();
		std::cout << "I have calculated a slope of " << slope << " and an incr of " << incr << std::endl;
		return new Point(x, Fixed(slope * x + incr));
}

Point *	intersecY( Point const & p1, Point const & p2, Fixed const y) {
		std::cout << "p1 is " << p1.getX() << "x and " << p1.getY() << "y" << std::endl;
		std::cout << "p2 is " << p2.getX() << "x and " << p2.getY() << "y" << std::endl;
		std::cout << "y is " << y << std::endl;
		if (p1.getX() == p2.getX())
			return new Point(p1.getX(), y);
		if (p1.getY() == p2.getY())
			return NULL;
		Fixed	slope = ( p1.getY() - p2.getY() ) / ( p1.getX() - p2.getX() );
		Fixed	incr = p1.getY() - slope * p1.getX();
		std::cout << "I have calculated a slope of " << slope << " and an incr of " << incr << std::endl;
		return new Point(Fixed((y - incr) / slope), y);
}

/*Point *	intersec( Point const & p1, Point const & p2, Fixed const x, Fixed const y ) {
	
	Fixed	slope = ( p1.getX() - p2.getX() ) / ( p1.getY() - p2.getY() );
	Fixed	incr = p1.getY() - slope * p1.getX();
	
	std::cout << "p1 is " << p1.getX() << "x and " << p1.getY() << "y" << std::endl;
	std::cout << "p2 is " << p2.getX() << "x and " << p2.getY() << "y" << std::endl;
	std::cout << "x is " << x << " and y is " << y << std::endl;
	std::cout << "I have calculated a slope of " << slope << " and an incr of " << incr << std::endl;
	if (x != 0)
		return new Point(x, Fixed(slope * x + incr));
	return new Point(Fixed((y - incr) / slope), y);
}*/

// bool	within( Fixed const & av, Fixed const & bv, Fixed const & cv, Fixed const & pv ) {
	
// 	int		coinc = 0;

// 	if (pv >= Fixed::min(av, bv) && pv <= Fixed::max(av, bv))
// 		coinc++;
// 	if (pv >= Fixed::min(bv, cv) && pv <= Fixed::max(bv, cv))
// 		coinc++;
// 	if (pv >= Fixed::min(cv, av) && pv <= Fixed::max(cv, av))
// 		coinc++;
// 	if (coinc < 2)
// 		return false;
// 	return true; 
// }

bool	inside( Fixed const & v1, Fixed const & v2, Fixed const & pv ) {
	if (pv >= Fixed::min(v1, v2) && pv <= Fixed::max(v1, v2))
		return true;
	return false;
}

bool	inside_strict( Fixed const & v1, Fixed const & v2, Fixed const & pv ) {
	std::cout << "I'm inside_strict and I'm goin to check if " << pv << " is between " << v1 << " and " << v2 << std::endl;
	if (pv > Fixed::min(v1, v2) && pv < Fixed::max(v1, v2))
		return true;
	return false;
}

bool	checkX( Point const & a, Point const & b, Point const & c, Point const & point ) {
	
	Point* p1;
	Point* p2;

	if (inside(a.getX(),b.getX(), point.getX())) {
		p1 = intersecX(a, b, point.getX());
		if (inside(b.getX(),c.getX(), point.getX()))
			p2 = intersecX(b, c, point.getX());
		else if (inside(c.getX(),a.getX(), point.getX()))
			p2 = intersecX(c, a, point.getX());
		else {
			delete p1;
			return false;
		}
	}
	else if (inside(b.getX(),c.getX(), point.getX())) {
		p1 = intersecX(b, c, point.getX());
		if (inside(c.getX(),a.getX(), point.getX()))
			p2 = intersecX(c, a, point.getX());
		else {
			delete p1;
			return false;
		}
	}
	else
		return false;
	if (!p1 || !p2 || !inside_strict(p1->getY(), p2->getY(), point.getY())) {
		delete p1;
		delete p2;
		return false;
	}
	delete p1;
	delete p2;
	return true;
	
}

bool	checkY( Point const & a, Point const & b, Point const & c, Point const & point ) {
	
	Point* p1;
	Point* p2;

	if (inside(a.getY(),b.getY(), point.getY())) {
		p1 = intersecY(a, b, point.getY());
		if (inside(b.getY(),c.getY(), point.getY()))
			p2 = intersecY(b, c, point.getY());
		else if (inside(c.getY(),a.getY(), point.getY()))
			p2 = intersecY(c, a, point.getY());
		else {
			delete p1;
			return false;
		}
	}
	else if (inside(b.getY(),c.getY(), point.getY())) {
		p1 = intersecY(b, c, point.getY());
		if (inside(c.getY(),a.getY(), point.getY()))
			p2 = intersecY(c, a, point.getY());
		else {
			delete p1;
			return false;
		}
	}
	else
		return false;
	if (!p1 || !p2 || !inside_strict(p1->getX(), p2->getX(), point.getX())) {
		delete p1;
		delete p2;
		return false;
	}
	delete p1;
	delete p2;
	return true;
	
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	
/*	if (!within(a.getX(),b.getX(), c.getX(), point.getX()))
		return false;
	if (!within(a.getY(),b.getY(), c.getY(), point.getY()))
		return false;*/
	std::cout << "Point is on coords " << point.getX() << " and " << point.getY() << std::endl;
	if (!checkX(a, b, c, point) || !checkY(a, b, c, point))
		return false;
	return true;
}

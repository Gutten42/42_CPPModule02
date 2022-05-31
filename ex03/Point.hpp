/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:26:16 by vguttenb          #+#    #+#             */
/*   Updated: 2022/05/31 18:20:17 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class	Point {
	
public:

	Point( void );
	~Point( void );

	Point( Point & to_copy );
	Point( Fixed const & nx, Fixed const & ny );
	
	Point & operator=( Point const & to_assign );
	
	Fixed const &	getX( void ) const;
	Fixed const &	getY( void ) const;

private:

	Fixed const x;
	Fixed const y;
	
} ;

#endif

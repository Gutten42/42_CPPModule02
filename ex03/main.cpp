/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:17:27 by vgutten           #+#    #+#             */
/*   Updated: 2022/05/31 18:28:20 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int main( void ) {
	
	Point a( Fixed( 0 ), Fixed( 0 ));
	Point b( Fixed( 3 ), Fixed( 300 ));
	Point c( Fixed( 3 ), Fixed( -300 ));
	Point point( Fixed( 2.9f ), Fixed( 288.9f ));
	
	if (bsp(a, b, c, point))
		std::cout << "Yes, the point was inside of the triangle" << std::endl;
	else
		std::cout << "No, the point was not inside of the triangle" << std::endl;
	return 0;
}

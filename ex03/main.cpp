/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgutten <vgutten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:17:27 by vgutten           #+#    #+#             */
/*   Updated: 2022/05/31 16:27:55 by vgutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int main( void ) {
	
	Point a( Fixed( 0 ), Fixed( 0 ));
	Point b( Fixed( 3 ), Fixed( 3 ));
	Point c( Fixed( 2 ), Fixed( 0 ));
	Point point( Fixed( 3 ), Fixed( 3 ));
	
	if (bsp(a, b, c, point))
		std::cout << "Yes, the point was inside of the triangle" << std::endl;
	else
		std::cout << "No, the point was not inside of the triangle" << std::endl;
	return 0;
}

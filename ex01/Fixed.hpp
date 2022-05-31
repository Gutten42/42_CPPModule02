/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgutten <vgutten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:19:10 by vgutten           #+#    #+#             */
/*   Updated: 2022/05/30 13:14:28 by vgutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class	Fixed {
	
public:

	Fixed( void );
	~Fixed( void );

	Fixed( Fixed const & to_copy );
	Fixed( int const n );
	Fixed( float const n );
	
	Fixed &	operator=( Fixed const & to_assign );

	int	getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int	toInt( void ) const;

private:

	int	_n;
	static const int frac;

} ;

std::ostream &	operator<<( std::ostream & o, Fixed const & output );

#endif
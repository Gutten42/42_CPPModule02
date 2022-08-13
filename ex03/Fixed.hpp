/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:19:10 by vgutten           #+#    #+#             */
/*   Updated: 2022/08/13 17:18:46 by vguttenb         ###   ########.fr       */
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
	bool	operator>( Fixed const & to_compare ) const;
	bool	operator<( Fixed const & to_compare ) const;
	bool	operator>=( Fixed const & to_compare ) const;
	bool	operator<=( Fixed const & to_compare ) const;
	bool	operator==( Fixed const & to_compare ) const;
	bool	operator!=( Fixed const & to_compare ) const;

	Fixed	operator+( Fixed const & sum ) const;
	Fixed	operator-( Fixed const & sum ) const;
	Fixed	operator*( Fixed const & sum ) const;
	Fixed	operator/( Fixed const & sum ) const;

	Fixed &	operator++( void ) ;
	Fixed	operator++( int incr ) ;
	Fixed &	operator--( void ) ;
	Fixed	operator--( int decr ) ;

	int	getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int	toInt( void ) const;

	static int &	max( int & a, int & b ) ;
	static int &	min( int & a, int & b ) ;
	
	static const Fixed &	max( Fixed const & a, Fixed const & b ) ;
	static const Fixed &	min( Fixed const & a, Fixed const & b ) ;

private:

	int	_n;
	static const int frac;

} ;

std::ostream &	operator<<( std::ostream & o, Fixed const & output );

#endif

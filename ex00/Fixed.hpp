/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:19:10 by vgutten           #+#    #+#             */
/*   Updated: 2022/08/13 15:00:06 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

class	Fixed {
	
public:

	Fixed( void );
	~Fixed( void );

	Fixed( Fixed const & to_copy );
	
	Fixed &	operator=( Fixed const & to_assign );

	int	getRawBits( void ) const;
	void	setRawBits( int const raw );

private:

	int	_n;
	static const int frac;

} ;

#endif

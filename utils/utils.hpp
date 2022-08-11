/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:39:53 by ebeiline          #+#    #+#             */
/*   Updated: 2022/08/11 15:39:22 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
 #define UTILS_HPP

namespace ft
{
	// enable if
	template< bool B, class T = void>
	struct enable_if {};
 
	template< class T>
	struct enable_if<true, T> { typedef T type; };


	// choose
	template <bool flag, class IsTrue, class IsFalse>
	struct choose {};

	template <class IsTrue, class IsFalse>
	struct choose<true, IsTrue, IsFalse>
	{
		typedef IsTrue type;
	};

	template <class IsTrue, class IsFalse>
	struct choose<false, IsTrue, IsFalse>
	{	
		typedef IsFalse type;
	};
	
	
} // namespace ft

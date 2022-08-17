/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:39:53 by ebeiline          #+#    #+#             */
/*   Updated: 2022/08/17 13:24:48 by ebeiline         ###   ########.fr       */
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
	
	// is_integral
	template <class T> struct is_integral{ static const bool value = false; };
	template <> struct is_integral<bool> { static const bool value = true; };
	template <> struct is_integral<char> { static const bool value = true; };
	template <> struct is_integral<wchar_t> { static const bool value = true; };
	template <> struct is_integral<signed char> { static const bool value = true; };
	template <> struct is_integral<short int> { static const bool value = true; };
	template <> struct is_integral<int> { static const bool value = true; };
	template <> struct is_integral<long int> { static const bool value = true; };
	template <> struct is_integral<long long int> { static const bool value = true; };
	template <> struct is_integral<unsigned char> { static const bool value = true; };
	template <> struct is_integral<unsigned short int> { static const bool value = true; };
	template <> struct is_integral<unsigned int> { static const bool value = true; };
	template <> struct is_integral<unsigned long int> { static const bool value = true; };
	template <> struct is_integral<unsigned long long int> { static const bool value = true; };
	
} // namespace ft

#endif // UTILS_HPP
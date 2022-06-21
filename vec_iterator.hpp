/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:19:09 by ebeiline          #+#    #+#             */
/*   Updated: 2022/06/21 18:29:48 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ITERATOR_HPP
	#define VEC_ITERATOR_HPP

namespace ft
{
	template <typename T> 
	class vector_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef T							value_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef std::ptrdiff_t				difference_type;
			
			
	}
} // namespace ft



#endif // VEC_ITERATOR_HPP
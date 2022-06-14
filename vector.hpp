/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:52:31 by ebeiline          #+#    #+#             */
/*   Updated: 2022/06/14 16:00:58 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

namespace ft
{
	template < class T, class Alloc = allocator<T> > class vector
	{
		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef value_type*										pointer;
			typedef const value_type*								const_pointer;
			// typedef V_iterator<value_type, false>					iterator;
			// typedef V_iterator<value_type, true>					const_iterator;
			// typedef ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;
		private:
				
	}
}
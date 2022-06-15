/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:52:31 by ebeiline          #+#    #+#             */
/*   Updated: 2022/06/15 20:10:18 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
	#define FT_VECTOR_HPP

#include <iostream>
#include <stdexcept>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > class vector
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
			size_type _size;
			size_type _capacity;
			pointer _p;
			Alloc _alloc;

		public:

			// default constructor
			explicit vector (const allocator_type& alloc = allocator_type())
				: _size(0), _capacity(0)
			{
				_alloc = alloc;
				_p = _alloc.allocate(0);
			}
			
			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
				 : _size(n), _capacity(0)
			{
				_alloc = alloc;
				_p = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_p[i], val);
			}

			// range constructor
			// template <class InputIterator> vector (InputIterator first, InputIterator last,
            //      const allocator_type& alloc = allocator_type())
			// {
				
			// }

			// copy constructor
			// vector (const vector& x)
			// {
				
			// }

			// destructor
			// ~vector(void) 
			// {
			// 	clear();
			// 	_alloc.deallocate(_start, capacity());
			// }

			// capacity functions
			size_type size(void) const { return this->_size; }
			size_type max_size (void) const { return _alloc.max_size(); }
			size_type capacity (void) const { return this->_capacity; }
			bool empty (void) const { return this->_size == 0; }
			
	}
}

#endif // FT_VECTOR_HPP
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:52:31 by ebeiline          #+#    #+#             */
/*   Updated: 2022/07/15 18:29:34 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
	#define FT_VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include <vec_iterator.hpp>
#include <reverse_iterator.hpp>

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
			typedef const value_type*								const_vecointer;
			typedef V_iterator<value_type, false>					iterator;
			typedef V_iterator<value_type, true>					const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;

		private:
			size_type _size;
			size_type _capacity;
			pointer _vec;
			Alloc _alloc;

		public:

			// default constructor
			explicit vector (const allocator_type& alloc = allocator_type())
				: _size(0), _capacity(0)
			{
				_alloc = alloc;
				_vec = _alloc.allocate(0);
			}
			
			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
				 : _size(n), _capacity(0)
			{
				_alloc = alloc;
				_vec = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_vec[i], val);
			}

			// range constructor
			template <class InputIterator> vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
				 : _capacity(0)
			{
				_size = last - first;
				_vec = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_vec[i], *(first + i));
			}

			// copy constructor
			vector (const vector& other)
			: _size(other._size), _capacity(other._capacity), _alloc(other._alloc)
			{
				_vec = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_vec[i], other._vec[i]);
			}

			// destructor
			~vector(void) 
			{
				clear();
				_alloc.deallocate(_vec, capacity());
			}

			// iterators

			iterator begin(){ return iterator(this->_vec); }
			const iterator begin() const { return const_iterator(this->_vec); }

			iterator end(){ return iterator(this->_vec + this->_size); }
			const iterator end() const { return const_iterator(this->_vec + this->_size); }

			reverse_iterator rbegin(){ return reverse_iterator(end()); }
			const reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
			
			reverse_iterator rend(){ return reverse_iterator(begin()); }
			const reverse_iterator rend() const { return const_reverse_iterator(begin()); }

			// capacity functions
			size_type size(void) const { return this->_size; }
			size_type max_size (void) const { return _alloc.max_size(); }
			size_type capacity (void) const { return this->_capacity; }
			bool empty (void) const { return this->_size == 0; }
			
			//void resize (size_type n, value_type val = value_type())
			
			// void reserve (size_type n)
			
			// modifiers

			
			// template <class InputIterator>
  			// void assign (InputIterator first, InputIterator last)
			
			// void assign (size_type n, const value_type& val)

			// void push_back (const value_type& val)

			// void pop_back()

			// iterator insert (iterator position, const value_type& val)

   			// void insert (iterator position, size_type n, const value_type& val)

    		// template <class InputIterator>
    		// void insert (iterator position, InputIterator first, InputIterator last)

			// iterator erase (iterator position)
			
			// iterator erase (iterator first, iterator last)	

			// void swap (vector& x);

			// void clear();

	}
}

#endif // FT_VECTOR_HPP
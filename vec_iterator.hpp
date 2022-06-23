/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:19:09 by ebeiline          #+#    #+#             */
/*   Updated: 2022/06/23 13:55:55 by ebeiline         ###   ########.fr       */
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
			typedef	T												value_type;
			typedef	std::size_t										size_type;
			typedef long int										difference_type;

			typedef typename choose<is_const, const T &, T &>::type	reference;
			typedef typename choose<is_const, const T *, T *>::type	pointer;
			typedef T*												elem_ptr;
			
		private:
			elem_ptr												_val;

		public:
			// default constructors
			vector_iterator(void): _val(NULL) {}
			vector_iterator(elem_ptr val) : _val(val) {}

			// copy constructors
			vector_iterator(const vector_iterator<T, false>& other) {_val = other.getVal}
			
			// destructor
			~vector_iterator() {}
			
			// assignment operator
			vector_iterator& operator=(const vector_iterator& other)
			{
				if (this != &other)
					_val = other._val;
				return *this;
			}

			// getter
			elem_ptr getVal(void) const {return _val;}
			
	}
} // namespace ft



#endif // VEC_ITERATOR_HPP
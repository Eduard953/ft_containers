/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:19:09 by ebeiline          #+#    #+#             */
/*   Updated: 2022/07/14 18:07:41 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ITERATOR_HPP
	#define VEC_ITERATOR_HPP

namespace ft
{	
	template <typename T, bool B> 
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
			
			// Operator overloads
			reference operator*(void) const {return *_val;}
			pointer operator->(void) const {return _val;}
			
			vector_iterator& operator++() { _val++;	return *this;}
			vector_iterator& operator--() { _val--;	return *this;}
			vector_iterator operator++(int) { vector_iterator tmp(*this); ++(*this); return tmp;}
			vector_iterator operator--(int) { vector_iterator tmp(*this); --(*this); return tmp;}

			bool operator<(const vector_iterator& other) const {return _val < other._val;}
			bool operator>(const vector_iterator& other) const {return _val > other._val;}
			bool operator<=(const vector_iterator& other) const {return _val <= other._val;}
			bool operator>=(const vector_iterator& other) const {return _val >= other._val;}
			bool operator==(const vector_iterator& other) const {return _val == other._val;}
			bool operator!=(const vector_iterator& other) const {return _val != other._val;}

			difference_type operator-(const vector_iterator& other) const {return _val - other._val;}
			
			vector_iterator operator-(const int n) const {return vector_iterator(_val - n);}
			vector_iterator operator+(const int n) const {return vector_iterator(_val + n);}

			vector_iterator& operator-=(const int n) {_val -= n; return *this;}
			vector_iterator& operator+=(const int n) {_val += n; return *this;}

			reference operator[](const int n) const {return _val[n];}
			
			friend vector_iterator operator+(const int n, vector_iterator other) {return vector_iterator(other._val + n);}
			
	}
} // namespace ft



#endif // VEC_ITERATOR_HPP
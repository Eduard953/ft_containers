/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:08:16 by ebeiline          #+#    #+#             */
/*   Updated: 2022/08/17 14:04:49 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_REVERSE_ITERATOR_HPP
	#define  FT_REVERSE_ITERATOR_HPP

#include "vec_iterator.hpp"

namespace ft
{
	template<class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
		protected:
			iterator_type _current;
		public:
			// default constructor
			reverse_iterator() : _current() {}

			// initialization constructor
			explicit reverse_iterator(iterator_type it): _current(it) {}
			
			// copy constructor
			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& other)
  				: _current(other.base()) {}

			// member functions
			iterator_type base() const { return _current; }
			
			reference operator*() const {
				iterator_type tmp = _current;
				return *--tmp;
			  }

			reverse_iterator operator+(difference_type n) const {
				return reverse_iterator(_current - n);
			}

			reverse_iterator operator++() {
				--_current;
				return *this;
			}

			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				--_current;
				return tmp;
			}
			
			reverse_iterator operator+=(difference_type n) {
				_current -= n;
				return *this;
			}
			
			reverse_iterator operator-(difference_type n) const {
				return reverse_iterator(_current + n);
			}
			
			reverse_iterator operator--() {
				++_current;
				return *this;
			}

			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				++_current;
				return tmp;
			}

			reverse_iterator operator-=(difference_type n) {
				_current += n;
				return *this;
			}

			pointer operator->() const {
				return &(operator*());
			}
			
			reference operator[](difference_type n) const {
				return *(*this + n);
			}
	};
	
	// nonmember functions
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() == rhs.base();
	}
	
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return !(lhs == rhs);
	}

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() > rhs.base();
	}

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() < rhs.base();
	}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() >= rhs.base();
	}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() <= rhs.base();
	}

	template <class Iterator>
 	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& rev_it) {
		return reverse_iterator<Iterator>(rev_it.base() - n);
	}

	template <class Iterator>
  	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs,
    		const reverse_iterator<Iterator>& rhs)
			{ return rhs.base() - lhs.base(); }
	
} // namespace ft

#endif //  FT_REVERSE_ITERATOR_HPP
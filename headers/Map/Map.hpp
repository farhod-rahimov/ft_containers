#ifndef MAP_HPP
# define  MAP_HPP

#include <memory>

#include "BidirectionalIteratorMap.hpp"
#include "utils.hpp"

namespace ft {
	// template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair <const Key,T> > >
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair <Key,T> > >
	class map {
	public:
				typedef 			Key													key_type;
				typedef 			T													mapped_type;
				typedef 			ft::pair<key_type, mapped_type>						value_type;
				// typedef 			ft::pair<const key_type, mapped_type>				value_type;

				typedef 			Compare												key_compare;
				// typedef 			class value_compare									value_compare;
				
				typedef 			Alloc 												allocator_type;
				typedef typename	allocator_type::reference 							reference;
				typedef typename	allocator_type::const_reference 					const_reference;
				typedef typename	allocator_type::pointer 							pointer;
				typedef typename	allocator_type::const_pointer 						const_pointer;
				
				typedef 			ft::BidirectionalIteratorMap<Key, T>				iterator;
				typedef 			ft::BidirectionalIteratorMap<Key, T const>			const_iterator;
				// typedef 			ft::BidirectionalIteratorMap<value_type>			reverse_iterator;
				// typedef 			ft::BidirectionalIteratorMap<value_type const>		const_reverse_iterator;

				typedef 			std::ptrdiff_t										difference_type;
				typedef 			size_t												size_type;

	private:
				class value_compare : std::binary_function<value_type, value_type, bool> {
				friend class map<key_type, mapped_type, key_compare, allocator_type>;
				protected:
					Compare _comp;
					value_compare (Compare c) : _comp(c) {}  // constructed with map's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return _comp(x.first, y.first);
					}
				};

		// INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION  //
	public:
				
				explicit map (const key_compare& comp = key_compare(), 
							const allocator_type& alloc = allocator_type()) {
					this->_allocator = alloc;
					this->_comp = comp;
					this->_size = 0;
					this->_root = new BinaryTree<key_type, mapped_type>;
					this->_root->setLastElementFlag();
					this->_root->_lh = this->_root->createFirstElemet(this->_root);
				};

				map (iterator first, iterator last, const key_compare& comp = key_compare(), 
						const allocator_type& alloc = allocator_type()) {
					this->_allocator = alloc;
					this->_comp = comp;
					this->_size = 0;
					this->_root = new BinaryTree<key_type, mapped_type>;
					this->_root->setLastElementFlag();
					this->_root->_lh = this->_root->createFirstElemet(this->_root);
					
					for (; first != last; first++) {
						this->insert(*first);
					}
				};
				
				map (const map & src) {
					this->_root = nullptr;
					*this = src;
				};
			
				virtual ~map() {
					// change change change change change change change change change change change change change 
				};

				map & operator = (const map & src) {
				if (this != &src) {
					if (this->_root != nullptr)
						delete this->_root;
					this->_allocator = src._allocator;
					this->_comp = src._comp;
					this->_size = 0;
					this->_root = new BinaryTree<key_type, mapped_type>;
					this->_root->setLastElementFlag();
					this->_root->_lh = this->_root->createFirstElemet(this->_root);
					
					for (iterator it = src.begin(); it != src.end(); it++) {
						this->insert(*it);
					}
				}
				return (*this);
			};

		// ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS //
				
				iterator begin() {
					BinaryTree<key_type, mapped_type> *tmp = this->_root;

					while (tmp && tmp->_lh && !tmp->_lh->isFirstElement()) {
						tmp = tmp->_lh;
					}
					return (iterator(*tmp));
				};
				
				// const_iterator begin() const {
				// 	BinaryTree<key_type, mapped_type> *tmp = this->_root;

				// 	while (tmp && tmp->_lh && !tmp->_lh->isFirstElement()) {
				// 		tmp = tmp->_lh;
				// 	}
				// 	return (const_iterator(*tmp));
				// };

				iterator end() {
					BinaryTree<key_type, mapped_type> *tmp = this->_root;

					while (!tmp->isLastElement()) {
						tmp = tmp->_rh;
					}
					return (iterator(*tmp));
				};

				// const_iterator end() const {
				// 	BinaryTree<key_type, mapped_type> *tmp = this->_root;

				// 	while (!tmp->isLastElement()) {
				// 		tmp = tmp->_rh;
				// 	}
				// 	return (const_iterator(*tmp));
				// };

				// iterator rbegin() const {};    // uncomment  uncomment  uncomment  uncomment  uncomment  uncomment 
				// iterator rend() const {}; //  uncomment  uncomment  uncomment  uncomment  uncomment  uncomment 	

		// CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY //

				bool empty() const {
					return (!this->_size);
				};

				size_type size() const {
					return (this->_size);
				};

				size_type max_size() const {
					return (this->_allocator.max_size() / sizeof(BinaryTree<key_type, mapped_type>)); // not sure
				};

		// ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS //
				
				mapped_type& operator[] (const key_type& k) {
					BinaryTree<key_type, mapped_type> *tmp = this->_root;
					iterator ret;
					
					if (this->_size == 0)
					{
						ret = (this->insert(ft::make_pair<key_type, mapped_type>(k, mapped_type()))).first;
						return (ret->second);
					}
					while (tmp) {
						if (this->_comp(k, tmp->_value->first) && tmp->_lh && !tmp->_lh->isFirstElement()) {
							tmp = tmp->_lh;
						}
						else if (this->_comp(tmp->_value->first, k) && tmp->_rh && !tmp->_rh->isLastElement()) {
							tmp = tmp->_rh;
						}
						else if (!this->_comp(tmp->_value->first, k) && !this->_comp(k, tmp->_value->first)) {
							break;
						}
						else {
							ret = (this->insert(ft::make_pair<key_type, mapped_type>(k, mapped_type()))).first;
							return (ret->second);
						}
					}
					return (tmp->_value->second);
				};

		// MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS //
				
				ft::pair<iterator,bool> insert (const value_type& val) {
					if (this->_size == 0) {
						this->_root->_value->first = val.first;
						this->_root->_value->second = val.second;
						this->_root->removeLastElementFlag();
						this->_root->_rh = this->_root->createLastElemet(this->_root);
						this->_root->_lh = this->_root->createFirstElemet(this->_root);
						this->_size++;
						return (ft::make_pair<iterator, bool>((*this->_root), true));
					}

					BinaryTree<key_type, mapped_type> *tmp = this->_root;

					while (tmp) {
						if (this->_comp(val.first, tmp->_value->first) && tmp->_lh && !tmp->_lh->isFirstElement()) {
							tmp = tmp->_lh;
						}
						else if (this->_comp(val.first, tmp->_value->first) && tmp->_lh && tmp->_lh->isFirstElement()) {
							tmp->_lh->removeFirstElementFlag();
							tmp->_lh->_value->first = val.first;
							tmp->_lh->_value->second = val.second;
							tmp->_lh->_lh = tmp->createFirstElemet(tmp->_lh);
							tmp = tmp->_lh;
							break ;
						}
						else if (this->_comp(val.first, tmp->_value->first) && !tmp->_lh) {
							tmp->_lh = new BinaryTree<key_type, mapped_type>(val, tmp);
							tmp = tmp->_lh;
							break ;
						}
						else if (this->_comp(tmp->_value->first, val.first) && tmp->_rh && !tmp->_rh->isLastElement()) {
							tmp = tmp->_rh;
						}
						else if (this->_comp(tmp->_value->first, val.first) && tmp->_rh && tmp->_rh->isLastElement()) {
							tmp->_rh->removeLastElementFlag();
							tmp->_rh->_value->first = val.first;
							tmp->_rh->_value->second = val.second;
							tmp->_rh->_rh = tmp->createLastElemet(tmp->_rh);
							tmp = tmp->_rh;
							break ;
						}
						else if (this->_comp(tmp->_value->first, val.first) && !tmp->_rh ) {
							tmp->_rh = new BinaryTree<key_type, mapped_type>(val, tmp);
							tmp = tmp->_rh;
							break ;
						}
						else {
							return (ft::make_pair<iterator, bool>(*tmp, false));
						}
					}
					this->_size++;
					return (ft::make_pair<iterator, bool>(*tmp, true));
				};

				iterator insert (iterator position, const value_type& val) {
					static_cast<void>(position);
					return (this->insert(val).first);
				};

				void insert (iterator first, iterator last) {
					for (; first != last; first++) {
						this->insert(*first);
					}
				};

				// void erase (iterator position) {
				// 	static_cast<void>(position);

				// 	// std::cout << position._binary_tree->_value->first;
				// 	// return ;
				// 	// if (this->_comp(position->_binary_tree->_value->first, this->_root)) {
				// 	// 	if (position->_binary_tree->_value->parent && position->_binary_tree->_rh 
				// 	// 		&& !position->_binary_tree->_rh->isLastElement) {

				// 	// 	}
				// 	// }
				// };

				// size_type erase (const key_type& k) {

				// };

				// void erase (iterator first, iterator last) {

				// };

				void swap (map& x) {
					allocator_type tmp_allocator = this->_allocator;
					key_compare tmp_comp = this->_comp;
					size_type tmp_size = this->_size;
					BinaryTree<key_type, mapped_type> *tmp_btree = this->_root;
					
					this->_allocator = x._allocator;
					this->_comp = x._comp;
					this->_size = x._size;
					this->_root = x._root;

					x._allocator = tmp_allocator;
					x._comp = tmp_comp;
					x._size = tmp_size;
					x._root = tmp_btree;
				};

				// void clear() {
					
				// };

		// OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS  //

				key_compare key_comp() const {
					return (this->_comp);
				};

				value_compare value_comp() const {
					return (value_compare(key_compare()));
				};

		// OPERATIONS OPERATIONS OPERATIONS OPERATIONS OPERATIONS OPERATIONS OPERATIONS OPERATIONS OPERATIONS OPERATIONS //

				iterator find (const key_type& k) {
					BinaryTree<key_type, mapped_type> *tmp = this->_root;
					iterator ret = this->end();

					while (tmp) {
						if (this->_comp(k, tmp->_value->first) && tmp->_lh && !tmp->_lh->isFirstElement()) {
							tmp = tmp->_lh;
						}
						else if (this->_comp(tmp->_value->first, k) && tmp->_rh && !tmp->_rh->isLastElement()) {
							tmp = tmp->_rh;
						}
						else if (!this->_comp(tmp->_value->first, k) && !this->_comp(k, tmp->_value->first)) {
							ret = iterator(*tmp);
							break;
						}
						else
							return (ret);
					}
					return (ret);
				};

				const_iterator find (const key_type& k) const {
					return (const_iterator(this->find(k)));
				};

				size_type count (const key_type& k) const {
					BinaryTree<key_type, mapped_type> *tmp = this->_root;

					while (tmp) {
						if (this->_comp(k, tmp->_value->first) && tmp->_lh && !tmp->_lh->isFirstElement()) {
							tmp = tmp->_lh;
						}
						else if (this->_comp(tmp->_value->first, k) && tmp->_rh && !tmp->_rh->isLastElement()) {
							tmp = tmp->_rh;
						}
						else if (!this->_comp(tmp->_value->first, k) && !this->_comp(k, tmp->_value->first)) {
							return (1);
						}
						else
							return (0);
					}
					return (0);
				};

				iterator lower_bound (const key_type& k) {
					iterator it = this->begin();
					for (; it != this->end(); it++) {
						if (!this->_comp(it->first, k))
							break ;
					}
					return (it);
				};

				// const_iterator lower_bound (const key_type& k) const {

				// };

				iterator upper_bound (const key_type& k) {
					iterator it = this->begin();
					for (; it != this->end(); it++) {
						if (this->_comp(k, it->first))
							break ;
					}
					return (it);
				};

				// const_iterator upper_bound (const key_type& k) const {

				// };

				// pair<const_iterator,const_iterator> equal_range (const key_type& k) const {

				// };

				pair<iterator,iterator>	equal_range (const key_type& k) {
					iterator lb = this->lower_bound(k);
					iterator ub = this->upper_bound(k);

					return (make_pair<iterator, iterator>(lb, ub));
				};

				allocator_type get_allocator() const {
					return (this->_allocator);
				};



	private:
				allocator_type	        				_allocator;
				key_compare		        				_comp;
				size_type		        				_size;
				BinaryTree<key_type, mapped_type>		*_root;
	};

};

#endif
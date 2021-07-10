#ifndef MAP_HPP
# define  MAP_HPP

#include <memory>

#include "BidirectionalIteratorMap.hpp"
#include "BidirectionalReverseIteratorMap.hpp"
#include "utils.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair <Key const,T> > >
	class map {
	public:
				typedef 			Key																key_type;
				typedef 			T																mapped_type;
				typedef 			ft::pair<key_type const, mapped_type>							value_type;

				typedef 			Compare															key_compare;
				
				typedef 			Alloc 															allocator_type;
				typedef typename	allocator_type::reference 										reference;
				typedef typename	allocator_type::const_reference 								const_reference;
				typedef typename	allocator_type::pointer 										pointer;
				typedef typename	allocator_type::const_pointer 									const_pointer;
				
				typedef 			ft::BidirectionalIteratorMap<Key, T>							iterator;
				typedef 			ft::BidirectionalIteratorMapConst<Key, T>						const_iterator;
				typedef 			ft::BidirectionalReverseIteratorMap<Key, T>						reverse_iterator;
				typedef 			ft::BidirectionalReverseIteratorMapConst<Key, T>				const_reverse_iterator;

				typedef 			std::ptrdiff_t													difference_type;
				typedef 			size_t															size_type;

	private:
				class value_compare : std::binary_function<value_type, value_type, bool> {
				friend class map<key_type, mapped_type, key_compare, allocator_type>;
				protected:
					Compare _comp;
					value_compare (Compare c) : _comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return _comp(x.first, y.first);
					}
				};

	public:

		// INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION  //
				
				explicit map (const key_compare& comp = key_compare(), 
							const allocator_type& alloc = allocator_type()) {
					this->_allocator = alloc;
					this->_comp = comp;
					this->_size = 0;
					this->_root = new BinaryTree<key_type const, mapped_type>;
					this->_root->setLastElementFlag();
					this->_root->_lh = this->_root->createFirstElemet(this->_root);
					this->_root->_rh = nullptr;
				};

				map (iterator first, iterator last, const key_compare& comp = key_compare(), 
						const allocator_type& alloc = allocator_type()) {
					this->_allocator = alloc;
					this->_comp = comp;
					this->_size = 0;
					this->_root = new BinaryTree<key_type const, mapped_type>;
					this->_root->setLastElementFlag();
					this->_root->_lh = this->_root->createFirstElemet(this->_root);
					this->_root->_rh = nullptr;
					
					for (; first != last; first++) {
						this->insert(*first);
					}
				};
				
				map (const map & src) {
					this->_root = new BinaryTree<key_type const, mapped_type>;
					*this = src;
				};
			
				virtual ~map() {
					this->clear();
					delete (this->_root->_lh);
					delete (this->_root->_rh);
					delete (this->_root);
				};

				map & operator = (const map & src) {
				if (this != &src) {
					if (this->_size) {
						this->clear();
					}
					this->_allocator = src._allocator;
					this->_comp = src._comp;
					this->_size = 0;
					for (const_iterator it = src.begin(); it != src.end(); it++) {
						this->insert(*it);
					}
				}
				return (*this);
			};

		// ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS //
				
				iterator begin() {
					BinaryTree<key_type const, mapped_type> *tmp = this->_root;

					if (this->_size == 0)
						return (this->end());
					while (tmp && tmp->_lh && !tmp->_lh->isFirstElement()) {
						tmp = tmp->_lh;
					}
					return (iterator(*tmp));
				};
				
				const_iterator begin() const {
					BinaryTree<key_type const, mapped_type> *tmp = this->_root;

					while (tmp && tmp->_lh && !tmp->_lh->isFirstElement()) {
						tmp = tmp->_lh;
					}
					return (const_iterator(*tmp));
				};

				iterator end() {
					BinaryTree<key_type const, mapped_type> *tmp = this->_root;

					while (tmp && !tmp->isLastElement()) {
						tmp = tmp->_rh;
					}
					return (iterator(*tmp));
				};

				const_iterator end() const {
					BinaryTree<key_type const, mapped_type> *tmp = this->_root;

					while (tmp && !tmp->isLastElement()) {
						tmp = tmp->_rh;
					}
					return (const_iterator(*tmp));
				};

				reverse_iterator rbegin()  {
					BinaryTree<key_type const, mapped_type> *tmp = this->_root;

					while (tmp && tmp->_rh && !tmp->_rh->isLastElement()) {
						tmp = tmp->_rh;
					}
					return (reverse_iterator(*tmp));
				};
				
				const_reverse_iterator rbegin() const {
					BinaryTree<key_type const, mapped_type> *tmp = this->_root;

					while (tmp && tmp->_rh && !tmp->_rh->isLastElement()) {
						tmp = tmp->_rh;
					}
					return (const_reverse_iterator(*tmp));
				};

				reverse_iterator rend() {
					BinaryTree<key_type const, mapped_type> *tmp = this->_root;

					while (tmp && !tmp->isFirstElement()) {
						tmp = tmp->_lh;
					}
					return (reverse_iterator(*tmp));
				};

				const_reverse_iterator rend() const {
					BinaryTree<key_type const, mapped_type> *tmp = this->_root;

					while (tmp && !tmp->isFirstElement()) {
						tmp = tmp->_lh;
					}
					return (const_reverse_iterator(*tmp));
				};

		// CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY //

				bool empty() const {
					return (!this->_size);
				};

				size_type size() const {
					return (this->_size);
				};

				size_type max_size() const {
					return (this->_allocator.max_size() / sizeof(BinaryTree<key_type const, mapped_type>));
				};

		// ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS //
				
				mapped_type& operator[] (const key_type& k) {
					BinaryTree<key_type const, mapped_type> *tmp = this->_root;
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
						this->_allocator.construct(this->_root->_value, val);
						this->_root->removeLastElementFlag();
						if (this->_root->_rh) {}
							delete this->_root->_rh;
						if (this->_root->_lh)
							delete this->_root->_lh;
						this->_root->_rh = this->_root->createLastElemet(this->_root);
						this->_root->_lh = this->_root->createFirstElemet(this->_root);
						this->_size++;
						return (ft::make_pair<iterator, bool>((*this->_root), true));
					}

					BinaryTree<key_type const, mapped_type> *tmp = this->_root;

					while (tmp) {
						if (this->_comp(val.first, tmp->_value->first) && tmp->_lh && !tmp->_lh->isFirstElement()) {
							tmp = tmp->_lh;
						}
						else if (this->_comp(val.first, tmp->_value->first) && tmp->_lh && tmp->_lh->isFirstElement()) {
							tmp->_lh->removeFirstElementFlag();
							tmp->_allocator.construct(tmp->_lh->_value, val);
							tmp->_lh->_lh = tmp->createFirstElemet(tmp->_lh);
							tmp = tmp->_lh;
							break ;
						}
						else if (this->_comp(val.first, tmp->_value->first) && !tmp->_lh) {
							tmp->_lh = new BinaryTree<key_type const, mapped_type>(val, tmp);
							tmp = tmp->_lh;
							break ;
						}
						else if (this->_comp(tmp->_value->first, val.first) && tmp->_rh && !tmp->_rh->isLastElement()) {
							tmp = tmp->_rh;
						}
						else if (this->_comp(tmp->_value->first, val.first) && tmp->_rh && tmp->_rh->isLastElement()) {
							tmp->_rh->removeLastElementFlag();
							tmp->_allocator.construct(tmp->_rh->_value, val);
							tmp->_rh->_rh = tmp->createLastElemet(tmp->_rh);
							tmp = tmp->_rh;
							break ;
						}
						else if (this->_comp(tmp->_value->first, val.first) && !tmp->_rh ) {
							tmp->_rh = new BinaryTree<key_type const, mapped_type>(val, tmp);
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

				void erase (iterator position) {
					char side;
					BinaryTree<key_type const, mapped_type> *erase_el = this->_private_find(position->first, &side);
					BinaryTree<key_type const, mapped_type> *tmp;
					if (erase_el == nullptr || this->_size == 0)
						return ;

					this->_size -= 1;
					if (this->_size == 0) {
						tmp = this->_root;
						this->_root = this->_root->_lh;
						this->_root->_rh = tmp->_rh;
						this->_root->_parent = nullptr;
						delete tmp;
						return ;
					}
					else if (!this->_comp(position->first, this->_root->_value->first) 
						&& !this->_comp(this->_root->_value->first, position->first)) { // deleting root
						if (this->_root->_rh && !this->_root->_rh->isLastElement()) {
							erase_el = this->_root;
							this->_root = this->_root->_rh;
							this->_root->_parent = nullptr;
							tmp = this->_root;
							while (tmp->_lh)
								tmp = tmp->_lh;
							tmp->_lh = erase_el->_lh;
							if (tmp->_lh)
								tmp->_lh->_parent = tmp;
							delete erase_el;
						}
						else if (!this->_root->_rh || this->_root->_rh->isLastElement()) {
							erase_el = this->_root;
							this->_root = this->_root->_lh;
							tmp = this->_root;
							while (tmp->_rh)
								tmp = tmp->_rh;
							tmp->_rh = erase_el->_rh;
							if (tmp->_rh)
								tmp->_rh->_parent = tmp;
							delete erase_el;
						}
						return ;
					}
					else if (this->_comp(position->first, this->_root->_value->first)) {
						if (side == 'l') {
							if (!erase_el->_rh) { // situation 1, 2
								erase_el->_parent->_lh = erase_el->_lh;
								if (erase_el->_lh)
									erase_el->_lh->_parent = erase_el->_parent;
								delete erase_el;
							}
							else if (!erase_el->_lh || erase_el->_lh->isFirstElement()) { // situation 3, 4
								erase_el->_parent->_lh = erase_el->_rh;
								if (erase_el->_rh)
									erase_el->_rh->_parent = erase_el->_parent;
								tmp = erase_el->_rh;
								while (tmp->_lh)
									tmp = tmp->_lh;
								tmp->_lh = erase_el->_lh;
								if (tmp->_lh)
									tmp->_lh->_parent = tmp;
							}
							else if (erase_el->_lh && erase_el->_rh) { // situation 5
								erase_el->_parent->_lh = erase_el->_rh;
								if (erase_el->_rh)
									erase_el->_rh->_parent = erase_el->_parent;
								tmp = erase_el->_rh;
								while (tmp->_lh)
									tmp = tmp->_lh;
								tmp->_lh = erase_el->_lh;
								if (tmp->_lh)
									tmp->_lh->_parent = tmp;
								delete erase_el;
							}
						}
						else if (side == 'r') {
							if (!erase_el->_rh) { // situation 6
								erase_el->_parent->_rh = erase_el->_lh;
								if (erase_el->_lh)
									erase_el->_lh->_parent = erase_el->_parent;
								delete erase_el;
							}
							else if (!erase_el->_lh || erase_el->_lh->isFirstElement()) { // situation 7
								erase_el->_parent->_rh = erase_el->_rh;
								if (erase_el->_rh)
									erase_el->_rh->_parent = erase_el->_parent;
								tmp = erase_el->_rh;
								while (tmp->_lh)
									tmp = tmp->_lh;
								tmp->_lh = erase_el->_lh;
								if (tmp->_lh)
									tmp->_lh->_parent = tmp;
								delete erase_el;
							}
							else if (erase_el->_lh && erase_el->_rh) { // situation 8
								erase_el->_parent->_rh = erase_el->_rh;
								if (erase_el->_rh)
									erase_el->_rh->_parent = erase_el->_parent;
								tmp = erase_el->_rh;
								while (tmp->_lh)
									tmp = tmp->_lh;
								tmp->_lh = erase_el->_lh;
								if (tmp->_lh)
									tmp->_lh->_parent = tmp;
								delete erase_el;
							}
						}
						return ;
					}
					else {
						if (side == 'l') {
							if (!erase_el->_rh) { // situation 1
								erase_el->_parent->_lh = erase_el->_lh;
								if (erase_el->_lh)
									erase_el->_lh->_parent = erase_el->_parent;
								delete erase_el;
							}
							else if (!erase_el->_lh) { // situation 2
								erase_el->_parent->_lh = erase_el->_rh;
								if (erase_el->_rh)
									erase_el->_rh->_parent = erase_el->_parent;
								delete erase_el;
							}
							else if (erase_el->_lh && erase_el->_rh) { // situation 3
								erase_el->_parent->_lh = erase_el->_rh;
								if (erase_el->_rh)
									erase_el->_rh->_parent = erase_el->_parent;
								tmp = erase_el->_rh;
								while (tmp->_lh)
									tmp = tmp->_lh;
								tmp->_lh = erase_el->_lh;
								if (tmp->_lh)
									tmp->_lh->_parent = tmp;
								delete erase_el;
							}
						}
						else if (side == 'r') {
							if ((!erase_el->_rh || erase_el->_rh->isLastElement()) && erase_el->_lh) { // situation 4
								erase_el->_parent->_rh = erase_el->_lh;
								if (erase_el->_lh)
									erase_el->_lh->_parent = erase_el->_parent;
								tmp = erase_el->_lh;
								while (tmp->_rh)
									tmp = tmp->_rh;
								tmp->_rh = erase_el->_rh;
								if (tmp->_rh)
									tmp->_rh->_parent = tmp;
								delete erase_el;
							}
							else if ((!erase_el->_rh || erase_el->_rh->isLastElement()) && !erase_el->_lh) { // situation 4
								erase_el->_parent->_rh = erase_el->_rh;
								if (erase_el->_rh)
									erase_el->_rh->_parent = erase_el->_parent;
								delete erase_el;
							}
							else if (!erase_el->_lh) { // situatin 5
								erase_el->_parent->_rh = erase_el->_rh;
								if (erase_el->_rh)
									erase_el->_rh->_parent = erase_el->_parent;
								delete erase_el;
							}
							else if (erase_el->_lh && erase_el->_rh) {
								erase_el->_parent->_rh = erase_el->_rh;
								tmp = erase_el->_rh;
								if (erase_el->_rh)
									erase_el->_rh->_parent = erase_el->_parent;
								while (tmp->_lh)
									tmp = tmp->_lh;
								tmp->_lh = erase_el->_lh;
								if (tmp->_lh)
									tmp->_lh->_parent = tmp;
								delete erase_el;
							}
						}
						return ;
					}
				};

				size_type erase (const key_type& k) {
					iterator it = this->find(k);
					if (it == this->end())
						return (0);
					this->erase(it);
					return (1);
				};

				void erase (iterator first, iterator last) {
					size_type n = 0;
					for (iterator tmp = first; tmp != last; tmp++) {
						n++;
					}
					for (; n-- > 0; first++) {
						this->erase(first);
					}
				};

				void swap (map& x) {
					allocator_type tmp_allocator = this->_allocator;
					key_compare tmp_comp = this->_comp;
					size_type tmp_size = this->_size;
					BinaryTree<key_type const, mapped_type> *tmp_btree = this->_root;
					
					this->_allocator = x._allocator;
					this->_comp = x._comp;
					this->_size = x._size;
					this->_root = x._root;

					x._allocator = tmp_allocator;
					x._comp = tmp_comp;
					x._size = tmp_size;
					x._root = tmp_btree;
				};

				void clear() {
					while (this->_size)
						this->erase(this->_root->_value->first);
				};

		// OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS OBSERVERS  //

				key_compare key_comp() const {
					return (this->_comp);
				};

				value_compare value_comp() const {
					return (value_compare(key_compare()));
				};

		// OPERATIONS OPERATIONS OPERATIONS OPERATIONS OPERATIONS OPERATIONS OPERATIONS OPERATIONS OPERATIONS OPERATIONS //

				iterator find (const key_type& k) {
					BinaryTree<key_type const, mapped_type> *tmp = this->_root;
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
					BinaryTree<key_type const, mapped_type> *tmp = this->_root;

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

				const_iterator lower_bound (const key_type& k) const {
					const_iterator it = this->begin();
					for (; it != this->end(); it++) {
						if (!this->_comp(it->first, k))
							break ;
					}
					return (it);
				};

				iterator upper_bound (const key_type& k) {
					iterator it = this->begin();
					for (; it != this->end(); it++) {
						if (this->_comp(k, it->first))
							break ;
					}
					return (it);
				};

				const_iterator upper_bound (const key_type& k) const {
					const_iterator it = this->begin();
					for (; it != this->end(); it++) {
						if (this->_comp(k, it->first))
							break ;
					}
					return (it);
				};

				pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
					const_iterator lb = this->lower_bound(k);
					const_iterator ub = this->upper_bound(k);

					return (make_pair<const_iterator, const_iterator>(lb, ub));
				};

				pair<iterator,iterator>	equal_range (const key_type& k) {
					iterator lb = this->lower_bound(k);
					iterator ub = this->upper_bound(k);

					return (ft::make_pair<iterator, iterator>(lb, ub));
				};

				allocator_type get_allocator() const {
					return (this->_allocator);
				};

	private:
				allocator_type	        					_allocator;
				key_compare		        					_comp;
				size_type		        					_size;
				BinaryTree<key_type const, mapped_type>		*_root;

				BinaryTree<key_type const, mapped_type>		*_private_find(key_type const & k, char *side) {
					BinaryTree<key_type const, mapped_type> *tmp = this->_root;
					
					while (tmp) {
						if (this->_comp(k, tmp->_value->first) && tmp->_lh && !tmp->_lh->isFirstElement()) {
							tmp = tmp->_lh;
							*side = 'l';
						}
						else if (this->_comp(tmp->_value->first, k) && tmp->_rh && !tmp->_rh->isLastElement()) {
							*side = 'r';
							tmp = tmp->_rh;
						}
						else if (!this->_comp(tmp->_value->first, k) && !this->_comp(k, tmp->_value->first)) {
							return (tmp);
						}
						else {
							return (nullptr);
						}
					}
					return (nullptr);
				};
	};
};

#endif
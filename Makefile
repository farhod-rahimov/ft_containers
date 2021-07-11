COMPILE = clang++ -Wall -Wextra -Werror -std=c++98

all:		
				@ echo '--------------------------------------------------------------------'
				@ echo 'Available commands:	make test_vector, make test_stack, make test_map,'
				@ echo '			make test_iterator_traits, make test_reverse_iterator,'
				@ echo '			make test_enable_if, make test_is_integral'
				@ echo '--------------------------------------------------------------------'
vector:
				@ echo '--------------------------------------------------------------------'
				@ echo 'compiling ./tests/main_vector-ft.cpp into binary file vector_ft.test'
				@ cd ./tests && $(COMPILE) -c main_vector_stl.cpp && $(COMPILE) -o vector_stl.test main_vector_stl.o
				@ echo 'compiling ./tests/main_vector_stl.cpp into binary file vector_stl.test'
				@ cd ./tests && $(COMPILE) -c main_vector_ft.cpp && $(COMPILE) -o vector_ft.test main_vector_ft.o

stack:
				@ echo '--------------------------------------------------------------------'
				@ echo 'compiling ./tests/main_stack-ft.cpp into binary file stack_ft.test'
				@ cd ./tests && $(COMPILE) -c main_stack_stl.cpp && $(COMPILE) -o stack_stl.test main_stack_stl.o
				@ echo 'compiling ./tests/main_stack_stl.cpp into binary file stack_stl.test'
				@ cd ./tests && $(COMPILE) -c main_stack_ft.cpp && $(COMPILE) -o stack_ft.test main_stack_ft.o

map:
				@ echo '--------------------------------------------------------------------'
				@ echo 'compiling ./tests/main_map-ft.cpp into binary file map_ft.test'
				@ cd ./tests && $(COMPILE) -c main_map_ft.cpp && $(COMPILE) -o map_ft.test main_map_ft.o
				@ echo 'compiling ./tests/main_map_stl.cpp into binary file map_stl.test'
				@ cd ./tests && $(COMPILE) -c main_map_stl.cpp && $(COMPILE) -o map_stl.test main_map_stl.o
iterator_traits:
				@ echo '--------------------------------------------------------------------'
				@ echo 'compiling ./tests/main_iterator_traits.cpp into binary file iterator_traits.test'
				@ cd ./tests && $(COMPILE) -c main_iterator_traits.cpp && $(COMPILE) -o iterator_traits.test main_iterator_traits.o

reverse_iterator:
				@ echo '--------------------------------------------------------------------'
				@ echo 'compiling ./tests/main_reverse_iterator.cpp into binary file reverse_iterator.test'
				@ cd ./tests && $(COMPILE) -c main_reverse_iterator.cpp && $(COMPILE) -o reverse_iterator.test main_reverse_iterator.o

enable_if:
				@ echo '--------------------------------------------------------------------'
				@ echo 'compiling ./tests/main_enable_if.cpp into binary file enable_if.test'
				@ cd ./tests && $(COMPILE) -c main_enable_if.cpp && $(COMPILE) -o enable_if.test main_enable_if.o

is_integral:
				@ echo '--------------------------------------------------------------------'
				@ echo 'compiling ./tests/main_is_integral.cpp into binary file is_integral.test'
				@ cd ./tests && $(COMPILE) -c main_is_integral.cpp && $(COMPILE) -o is_integral.test main_is_integral.o

test_vector:	vector
				@ echo '--------------------------------------------------------------------'
				@ echo 'redirecting the result of executing vector_ft.test to ft.output'
				@ ./tests/vector_ft.test > ./tests/ft.output
				@ echo 'redirecting the result of executing vector_ft.test to stl.output'
				@ ./tests/vector_stl.test > ./tests/stl.output
				@ echo '--------------------------------------------------------------------'
				@ echo 'running diff ft.output stl.output'
				@ echo '--------------------------------------------------------------------'
				@ diff ./tests/ft.output ./tests/stl.output ; cd ../

test_stack:		stack
				@ echo '--------------------------------------------------------------------'
				@ echo 'redirecting the result of executing stack_ft.test to ft.output'
				@ ./tests/stack_ft.test > ./tests/ft.output
				@ echo 'redirecting the result of executing stack_ft.test to stl.output'
				@ ./tests/stack_stl.test > ./tests/stl.output
				@ echo '--------------------------------------------------------------------'
				@ echo 'running diff ft.output stl.output'
				@ echo '--------------------------------------------------------------------'
				@ diff ./tests/ft.output ./tests/stl.output ; cd ../
				

test_map:		map
				@ echo '--------------------------------------------------------------------'
				@ echo 'redirecting the result of executing map_ft.test to ft.output'
				@ ./tests/map_ft.test > ./tests/ft.output
				@ echo 'redirecting the result of executing map_ft.test to stl.output'
				@ ./tests/map_stl.test > ./tests/stl.output
				@ echo '--------------------------------------------------------------------'
				@ echo 'running diff ft.output stl.output'
				@ echo '--------------------------------------------------------------------'
				@ diff ./tests/ft.output ./tests/stl.output ; cd ../

test_iterator_traits: iterator_traits
				@ echo '--------------------------------------------------------------------'
				@ echo 'redirecting the result of executing iterator_traits.test to ft.output'
				@ ./tests/iterator_traits.test > ./tests/ft.output
				@ echo '--------------------------------------------------------------------'
				@ echo 'running cat ft.output'
				@ echo '--------------------------------------------------------------------'
				@ cat ./tests/ft.output ; cd ../

test_reverse_iterator: reverse_iterator
				@ echo '--------------------------------------------------------------------'
				@ echo 'redirecting the result of executing reverse_iterator.test to ft.output'
				@ ./tests/reverse_iterator.test > ./tests/ft.output
				@ echo '--------------------------------------------------------------------'
				@ echo 'running cat ft.output'
				@ echo '--------------------------------------------------------------------'
				@ cat ./tests/ft.output ; cd ../

test_enable_if: enable_if
				@ echo '--------------------------------------------------------------------'
				@ echo 'redirecting the result of executing enable_if.test to ft.output'
				@ ./tests/enable_if.test > ./tests/ft.output
				@ echo '--------------------------------------------------------------------'
				@ echo 'running cat ft.output'
				@ echo '--------------------------------------------------------------------'
				@ cat ./tests/ft.output ; cd ../

test_is_integral: is_integral
				@ echo '--------------------------------------------------------------------'
				@ echo 'redirecting the result of executing is_integral.test to ft.output'
				@ ./tests/is_integral.test > ./tests/ft.output
				@ echo '--------------------------------------------------------------------'
				@ echo 'running cat ft.output'
				@ echo '--------------------------------------------------------------------'
				@ cat ./tests/ft.output ; cd ../

all_test:		test_vector test_stack test_map test_iterator_traits test_reverse_iterator

clean:
				@ cd ./tests ; rm *.o *.output ; cd ../

fclean:			clean
				@ cd ./tests ; rm *.test ; cd ../


re:				fclean all

.PHONY:			all clean fclean re test_vector test_stack test_map
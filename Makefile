COMPILE = clang++ -Wall -Wextra -Werror -std=c++98

all:		
				@ echo '--------------------------------------------------------------------'
				@ echo 'Available commands: make test_vector, make test_stack, make test_map'
				@ echo '--------------------------------------------------------------------'
vector:
				@ echo '--------------------------------------------------------------------'
				@ echo 'compiling ./tests/main_vector_ft into binary file vector_ft.test'
				@ cd ./tests && $(COMPILE) -c main_vector_stl.cpp && $(COMPILE) -o vector_stl.test main_vector_stl.o
				@ echo 'compiling ./tests/main_vector_stl into binary file vector_stl.test'
				@ cd ./tests && $(COMPILE) -c main_vector_ft.cpp && $(COMPILE) -o vector_ft.test main_vector_ft.o

stack:
				@ echo '--------------------------------------------------------------------'
				@ echo 'compiling ./tests/main_stack_ft into binary file stack_ft.test'
				@ cd ./tests && $(COMPILE) -c main_stack_stl.cpp && $(COMPILE) -o stack_stl.test main_stack_stl.o
				@ echo 'compiling ./tests/main_stack_stl into binary file stack_stl.test'
				@ cd ./tests && $(COMPILE) -c main_stack_ft.cpp && $(COMPILE) -o stack_ft.test main_stack_ft.o

map:
				@ echo '--------------------------------------------------------------------'
				@ echo 'compiling ./tests/main_map_ft into binary file map_ft.test'
				@ cd ./tests && $(COMPILE) -c main_map_ft.cpp && $(COMPILE) -o map_ft.test main_map_ft.o
				@ echo 'compiling ./tests/main_map_stl into binary file map_stl.test'
				@ cd ./tests && $(COMPILE) -c main_map_stl.cpp && $(COMPILE) -o map_stl.test main_map_stl.o

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

all_test:		test_vector test_stack test_map

clean:
				@ cd ./tests ; rm *.o *.output ; cd ../

fclean:			clean
				@ cd ./tests ; rm *.test ; cd ../


re:				fclean all

.PHONY:			all clean fclean re test_vector test_stack test_map
HW3: prog_assign_3.o shortest_path.o
	gcc -g prog_assign_3.o shortest_path.o -o HW3
prog_assign_3.o: prog_assign_3.c shortest_path.h
	gcc -g -c prog_assign_3.c
shortest_path.o: shortest_path.c shortest_path.h
	gcc -g -c shortest_path.c
clean: 
	rm *.o HW3
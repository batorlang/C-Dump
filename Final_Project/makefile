project: main.o bst.o dll.o node.o tnode.o
	gcc main.o bst.o dll.o node.o tnode.o -o project
main.o: main.c
	gcc -c main.c
bst.o: bst.c
	gcc -c bst.c
dll.o: dll.c
	gcc -c dll.c
node.o: node.c
	gcc -c node.c
tnode.o: tnode.c
	gcc -c tnode.c
clean:
	rm -f project main.o bst.o dll.o node.o tnode.o
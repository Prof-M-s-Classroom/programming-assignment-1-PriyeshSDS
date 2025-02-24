void addWaypointAtBeginning(T& data):
Adds a new waypoint at the beginning by creating a new node and setting that newnodes Next value to the current head and the heads prev value to the newnode, then sets head to newNode. This is O(1) beause all the commands are constant time. 

void addWaypointAtEnd(T& data):
Adds a new waypoint at the end by creating a new node and setting its previous value to tail and setting the current tails next value to newNode then sets the tail to newNode. This is also O(1) because all the commands are constant time.

void addWaypointAtIndex(int index, T& data):
Adds a new waypoint at a specific index by create a new node and then using the get method to get the current node at index and sets a pointer to it called temp, then sets the newNodes next to temp and Newnodes prev to temps prev, temps prev nexts is set to Newnode and lastly temps prev is set to newNode. This function is O(N) because calling the get method is O(N) since it uses a for loop that could go rhough the whole length. 

void removeWaypointAtBeginning():


[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

void addWaypointAtBeginning(T& data):
Adds a new waypoint at the beginning by creating a new node and setting that newnodes Next value to the current head and the heads prev value to the newnode, then sets head to newNode. This is O(1) beause all the commands are constant time. 

void addWaypointAtEnd(T& data):
Adds a new waypoint at the end by creating a new node and setting its previous value to tail and setting the current tails next value to newNode then sets the tail to newNode. This is also O(1) because all the commands are constant time.

void addWaypointAtIndex(int index, T& data):
Adds a new waypoint at a specific index by create a new node and then using the get method to get the current node at index and sets a pointer to it called temp, then sets the newNodes next to temp and Newnodes prev to temps prev, temps prev nexts is set to Newnode and lastly temps prev is set to newNode. This function is O(N) because calling the get method is O(N) since it uses a for loop that could go through the whole length. 

void removeWaypointAtBeginning():Removes waypoint at Begining by setting head to head next and having that head prev be null, and having a temporary node to head and deleteing that head,this is O(1)

void removeWaypointAtEnd(): This is also O(1) and has a similar setup to remove at Beginning by gettignt the curretn tail and having a temp pointer at it and then set tail to tail prev, and settign the next of that to null and delete the temp 

void removeWaypointAtIndex(int index): Remove the Node at a index by getting the Node at that index and the previous node and sets the preiovus nodes next to del next and sets the preiovus nodes next prev to temp, then delete del, this is O(n) because get waypoint 

void traverseForward(): uses a while loop and sets a temp node to head, this is O(n) because it loop till the next is null

void traverseBackward(): uses a while loop and sets temp node to tail, this is O(n) because it loop till the prev is null

Node<T>* getWaypoint(int index): set temp node to head and uses a for loop till index and temp is temp next, then return temp this is O(n) 

void setWaypoint(int index, T& data): this uses getWaypoint at index so its O(n) and then sets its data to the given data.

void print(): set Node current to head and while current exists use the current nodes pritn method and then current is currrent next. this is O(n)

[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

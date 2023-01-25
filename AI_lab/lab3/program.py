import random

def show(room):
    print(room)

print("Vacuum cleaner agent")
print("Enter the dimension of the room")
dim = int(input())

rows, cols = (dim, dim)
room = [[0]*cols]*rows

x=0
y=0

while x<dim:
    while y<dim:
        room[x][y] = random.choice([0,1])
        y = y + 1
    x = x + 1 
    y = 0
    
print("Initial state of rooms")
show(room)

x=0
y=0
while x<dim:
    while y<dim:
        if room[x][y] == 1:
            print("Vacuum cleaner in position ",x,y)
            room[x][y] = 0
            print("Cleaned",x,y)
        y = y + 1
    x = x + 1 
    y = 0

print("All rooms have been cleaned")
show(room)

def main(): 
    #Start of the program confirms user activations
    answer = input("Start drone? type yes or no") 
    #if user agrees it gathers how many loops the program will perform
    if answer == "yes":
        string_loops = input("How many loops?")  
        #it turns the users string into a interger that the program can handle
        num_loops = int(string_loops)  
        #this starts the main program and gives the argument loop numbers 
        onstart(num_loops) 
        #this is if the user did not mean to activate the drone
    elif answer == "no": 
        print("ok") 
#the main program
def onstart(num_loops): 
    #sets 4 states the loop can be
    num_states = 4 
    #psudocode making the drone altitute 100m
    drone_altitude = 100 
    #sets the current state to 0 as numbers start at 0 in python
    current_state = 0 
    #these are the x y coordinates and are set to 0 like a normal x y plane
    x = 0 
    y = 0 
    #this if statement checks if the drone altitude is 100 and if it isn't it will set it to 100
    if drone_altitude != 100: 
        drone_altitude = 100 

        #this is the  main loop that sets the x y coordinates
    for i in range(num_loops): 
        #this code sets the 4 states the loop can be in
        current_state = (current_state + 1) % num_states 

#these if statements add or remove to the x or y coordinates depending on the state
#the i interger is used as it is based off the number of loops and it slowly increases-
#-needed for the spiral pattern.
        if current_state == 0: 
            x = x + i 
        elif current_state == 1: 
            y = y + i 
        elif current_state == 2: 
            x = x - i 
        elif current_state == 3: 
            y = y - i 
        #gives the user the x, y corodinates
        print(f"{x}, {y}") 
#calls the entire function, python thing where if this line wasn't there the whole code wouldn't run
main() 
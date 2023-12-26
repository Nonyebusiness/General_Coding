class GameObject:
    name = ""
    appearance = ""
    feel = ""
    smell = ""

    def __init__(self, name, appearance, feel, smell):
        self.name = name
        self.appearance = appearance
        self.feel = feel
        self.smell = smell

    def look(self):
        return f"You look at the {self.name}. {self.appearance}\n"

    def touch(self):
        return f"You touch the {self.name}. {self.feel}\n"

    def sniff(self):
        return f"You sniff the {self.name}. {self.smell}\n"

game_object = GameObject("Knife", "Sharp and metalic", "Feel metalic and cold", "odourless")


class Room:

    escape_code = 0
    game_objects = []

    def __init__(self, escape_code, game_objects):
        self.escape_code = escape_code
        self.game_objects = game_objects
    
    def check_code(self, code):
        return self.escape_code == code
    
    def get_game_object_names(self):
        names = []
        for object in self.game_objects:
            names.append(object.name)
        return names

class Game:

    def __init__(self):
        self.attempts = 0
        objects = self.create_objects()
        self.room = Room(111, objects)


    def create_objects(self):
        return [
            GameObject(
                "Note",
                "It says that the sum of all digits is 1/3 the number on the pen",
                "it feels like paper",
                "its just paper what smell would there be to it"
            ),
            GameObject(
                "Pen",
                "It has the letter 12 written on the side",
                "it feels like pen",
                "its just pen what smell would there be to it"
            ),
            GameObject(
                "Bag",
                "It has 3 empty slots, possibly trhe number of digits in the code",
                "it feels like bag",
                "its just bag what smell would there be to it"
            ),

        ]

    def take_turn(self):
        prompt = self.get_room_prompt()
        selection = int(input(prompt))
        if selection >= 1 and selection <= 5:
            self.select_object(selection - 1)
            self.take_turn()
        else:
            is_code_correct = self.guess_code(selection)
            if is_code_correct:
                print("you won")
            elif self.attempts == 3:
                    print("you lost")
            else:
                print(f"wrong, you ahve  {self.attempts}/3 used ")
                self.take_turn()
    
    def get_room_prompt(self):
        prompt = "Enter the code or choose an item to interact with\n"
        names = self.room.get_game_object_names()
        index = 1
        for name in names:
            prompt += f"{index}. {name}\n"
            index += 1
        return prompt


    def select_object(self, index):
        selected_object = self.room.game_objects[index]
        prompt = self.get_object_interaction_string(selected_object.name)
        interaction = input(prompt)
        clue = self.interact_with_object(selected_object, interaction)
        print(clue)
        

        
    def get_object_interaction_string(self, name):
        return f"How to you wanna interact with {name}? \n1. Look\n2. Touch\n3. Smell\n"
    
    def interact_with_object(self, object, interaction):
        if interaction == "1":
            return object.look()
        elif interaction == "2":
            return object.touch()
        elif interaction == "3":
            return object.sniff()
    
    def guess_code(self, code):
        if self.room.check_code(code):
            return True
        else:
            self.attempts += 1
            return False
        


game = Game()
game.take_turn()


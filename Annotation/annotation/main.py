# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press ⌘F8 to toggle the breakpoint


def decode(message_file):
    try:
        with open(message_file, 'r') as file:
            print("Opening file")
            # Build our dictionary
            my_dictionary = {}
            for line in file:
                number_as_string, word = line.split()
                number = int(number_as_string)
                my_dictionary[number] = word

            # Our pyramid logic
            current_blocks = 1
            solution = ""
            pyramid_location = 0
            while pyramid_location < len(my_dictionary):
                pyramid_location += current_blocks
                solution += (my_dictionary[pyramid_location] + " ")
                current_blocks += 1
        # Remove extra white space at the end of the last word
        solution = solution[:-1]
        return solution
    except FileNotFoundError:
        print("Error opening file")


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print(decode("coding_qual_input.txt"))

# See PyCharm help at https://www.jetbrains.com/help/pycharm/

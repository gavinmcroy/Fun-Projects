# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.
def create_staircase1(nums):
    step = 1
    subsets = []
    while len(nums) != 0:
        if len(nums) >= step:
            subsets.append(nums[0:step])
            nums = nums[step:]
            step += 1
        else:
            return False

    return subsets

def create_staircase(nums):
    step = 1
    subsets = []
    while len(nums) != 0:
        if len(nums) >= step:
            subsets.append(nums[0:step])
            nums = nums[step:]
            step += 1
        else:
            return False

    return subsets


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press ⌘F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    variable = []
    for x in range(1,301):
        variable.append(x)

    subset = create_staircase1(variable)
    subset1 = create_staircase(variable)
    print(subset1)
    print(subset)

# See PyCharm help at https://www.jetbrains.com/help/pycharm/

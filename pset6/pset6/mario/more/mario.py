from cs50 import *

def main():
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break
    for i in range(1,height + 1):
        spaces = height - i

        print(" " * spaces, end="")
        print("#" * i, end="")
        print("  ", end="")
        print("#" * i)


if __name__ == "__main__":
    main()
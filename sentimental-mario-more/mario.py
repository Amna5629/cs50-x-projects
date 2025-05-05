def main():
    while True:
        try:
            height = int(input("Height: "))
            if 1 <= height <= 8:
                grid(height)
                break
            else:
                print("Please enter a number between 1 and 8.")
        except ValueError:
            print("Invalid input. Please enter a number.")

def grid(height):
    for i in range(1, height + 1):
        # Print leading spaces for left-aligned pyramid
        print(" " * (height - i), end="")

        # Print left-aligned pyramid
        print("#" * i, end="")

        # Print space between pyramids
        print("  ", end="")

        # Print right-aligned pyramid
        print("#" * i)

if __name__ == "__main__":
    main()

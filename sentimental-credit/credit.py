def main():
    card_number = input("Number: ")

    if not card_number.isdigit():
        print("INVALID")
        return

    if is_valid(card_number):
        card_type = get_card_type(card_number)
        print(card_type)
    else:
        print("INVALID")

def is_valid(card_number):
    total_sum = 0
    reversed_digits = card_number[::-1]

    for i, digit in enumerate(reversed_digits):
        n = int(digit)

        if i % 2 == 1:
            n *= 2
            if n > 9:
                n -= 9

        total_sum += n

    return total_sum % 10 == 0

def get_card_type(card_number):
    length = len(card_number)

    if length == 15 and (card_number.startswith("34") or card_number.startswith("37")):
        return "AMEX"
    elif length == 16 and card_number.startswith(("51", "52", "53", "54", "55")):
        return "MASTERCARD"
    elif (length == 13 or length == 16) and card_number.startswith("4"):
        return "VISA"
    else:
        return "INVALID"

if __name__ == "__main__":
    main()

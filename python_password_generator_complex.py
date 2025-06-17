import random
import string
import re

def generate_password(length=12, use_uppercase=True, use_digits=True, use_special=True):
    lower = string.ascii_lowercase
    upper = string.ascii_uppercase if use_uppercase else ""
    digits = string.digits if use_digits else ""
    special = string.punctuation if use_special else ""

    all_characters = lower + upper + digits + special
    if not all_characters:
        raise ValueError("Musíte povolit alespoň jeden typ znaků.")

    # Zajištění rozmanitosti znaků
    password = [
        random.choice(lower),
        random.choice(upper) if use_uppercase else "",
        random.choice(digits) if use_digits else "",
        random.choice(special) if use_special else ""
    ]

    password += random.choices(all_characters, k=length - len(password))
    random.shuffle(password)

    return "".join(password)

def check_password_strength(password):
    length_criteria = len(password) >= 12
    uppercase_criteria = bool(re.search(r'[A-Z]', password))
    lowercase_criteria = bool(re.search(r'[a-z]', password))
    digit_criteria = bool(re.search(r'\d', password))
    special_criteria = bool(re.search(r'[!@#$%^&*(),.?":{}|<>]', password))

    score = sum([length_criteria, uppercase_criteria, lowercase_criteria, digit_criteria, special_criteria])

    if score == 5:
        return "Velmi silné heslo ✅"
    elif score == 4:
        return "Silné heslo ✅"
    elif score == 3:
        return "Středně silné heslo ⚠️"
    else:
        return "Slabé heslo ❌"

# Uživatelský vstup
length = int(input("Zadejte délku hesla: "))
use_uppercase = input("Použít velká písmena? (ano/ne): ").strip().lower() == "ano"
use_digits = input("Použít čísla? (ano/ne): ").strip().lower() == "ano"
use_special = input("Použít speciální znaky? (ano/ne): ").strip().lower() == "ano"

try:
    password = generate_password(length, use_uppercase, use_digits, use_special)
    print(f"Generované heslo: {password}")
    print(f"Síla hesla: {check_password_strength(password)}")
except ValueError as e:
    print(e)
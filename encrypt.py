# encrypt.py
import os

def encrypt_file(file_path, key):
    with open(file_path, 'r') as file:
        content = file.read()
    encrypted_content = ''.join(chr(ord(char) + key) for char in content)
    with open(file_path, 'w') as file:
        file.write(encrypted_content)


file_path = 'C:\Users\CRS\Desktop\test.txt'
key = 123
encrypt_file(file_path, key)

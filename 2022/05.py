import os
import hashlib

def get_input(file_name):
    file_path = os.path.join("2022", f"{file_name}.in")
    arr = []

    try:
        with open(file_path, 'r') as file:
            for line in file:
                row = [word.strip() for word in line.split('|')]
                arr.append(row)
    except FileNotFoundError:
        print(f"Failed to open file: {file_path}")
    
    return arr

def sha256(input_string):
    sha256_hash = hashlib.sha256()
    sha256_hash.update(input_string.encode('utf-8'))
    return sha256_hash.hexdigest()

def solve(arr):
    for row in arr:
        data = "|".join(row[:-1])
        hash_code = row[-1]
        generated_code = sha256(data)
        print(generated_code, generated_code==hash_code)
    print("\nRES:: " + "" + "\n")

if __name__ == "__main__":
    arr = get_input("05")
    solve(arr)

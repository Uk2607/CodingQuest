import os
import hashlib

def get_input(file_name):
    file_path = os.path.join("2022", f"{file_name}.in")
    arr = []

    try:
        with open(file_path, 'r') as file:
            for line in file:
                row = [word.strip() for word in line.split('|')]  # Description|Index|PrevHashCode|NewHashCode
                arr.append(row)
    except FileNotFoundError:
        print(f"Failed to open file: {file_path}")
    
    return arr

def sha256(input_string):
    sha256_hash = hashlib.sha256()
    sha256_hash.update(input_string.encode('utf-8'))
    return sha256_hash.hexdigest()

def mine(des, idx, curr_hash):
    new_hash = ""
    while True:
        new_hash = sha256(des+"|"+str(idx)+"|"+curr_hash)
        if new_hash.startswith("000000"):
            break
        idx+=1
    return [des, idx, curr_hash, new_hash]


def generate_code(arr, idx):
    for i in range(idx, len(arr)):
        print(i)
        prev_hash = arr[i-1][-1]
        arr[i] = mine(arr[i][0], 0, prev_hash)
    return arr

def solve(arr):
    idx = -1
    for i, row in enumerate(arr):
        data = "|".join(row[:-1])
        hash_code = row[-1]
        generated_code = sha256(data)
        if (generated_code!=hash_code):
            idx = i
            break
    arr = generate_code(arr, idx)

    print("\nRES:: " + str(arr[-1]) + "\n")

if __name__ == "__main__":
    arr = get_input("05")
    solve(arr)

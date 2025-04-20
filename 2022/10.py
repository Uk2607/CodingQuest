from PIL import Image

image_path = '2022/010-inputdata-327485957345.png'
image = Image.open(image_path)
image = image.convert('RGB')

pixels = list(image.getdata())
red_channel_binary = [format(pixel[0], '08b') for pixel in pixels]
grouped_binary = [red_channel_binary[i:i + 8] for i in range(0, len(red_channel_binary), 8)]

new_binary_list = []
for group in grouped_binary:
    lsb = ''.join(binary[-1] for binary in group)
    new_binary_list.append(lsb)

decoded_message = ''
for binary in new_binary_list:
    if len(binary) == 8:
        ascii_value = int(binary, 2)
        decoded_message += chr(ascii_value)

print(decoded_message)

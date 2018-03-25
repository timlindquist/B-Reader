from Tkinter import *
import time
import serial

braille = {
   '!': '001110',
   '?': '001011',
   '.': '001101',
   ';': '001010',
   ':': '001100',
   '-': '000011',
   ',': '001000',
   '\'': '000010',
   '"': '000100',
   ' ': '000000',
   'a': '100000',
   'b': '101000',
   'c': '110000',
   'd': '110100',
   'e': '100100',
   'f': '111000',
   'g': '111100',
   'h': '101100',
   'i': '011000',
   'j': '011100',
   'k': '100010',
   'l': '101010',
   'm': '110010',
   'n': '110110',
   'o': '100110',
   'p': '111010',
   'q': '111110',
   'r': '101110',
   's': '011010',
   't': '011110',
   'u': '100011',
   'v': '101011',
   'w': '011101',
   'x': '110011',
   'y': '110111',
   'z': '100111'
}

ser = serial.Serial('/dev/cu.usbmodem1411')

def send_text():
   print 'sending...'
   i = 0
   string = T.get('1.0', END)
   string = string.strip().lower();
   for char in string:
       character_to_send = braille[char]
       for i, peg in enumerate(character_to_send):
           byte_to_send = (int(peg) << 7) | i
           print char,
	   print format(byte_to_send, '08b')
           ser.write([byte_to_send])
       #T.tag_add('here', '1.' + str(i), '1.' + str(i + 1))
       #T.tag_config('here', background='yellow', foreground='black')
       time.sleep(1.0/float(S.get())) # wait before showing the next character
       #T.tag_delete('here')
       i += 1
       character_to_send = braille[' ']
       for i, peg in enumerate(character_to_send):
           byte_to_send = (int(peg) << 7) | i
           print format(byte_to_send, '08b')
           ser.write([byte_to_send])
       time.sleep(0.15)


root = Tk()
root.title('Blind Kindle')

L = Label(root, text='Enter text to send: ')
L.pack()

T = Text(root, height=20, width=100)
T.pack()


B = Button(root, text='Send', command=send_text)
B.pack()

S = Scale(root, from_=1, to=4, orient=HORIZONTAL)
S.pack();

root.mainloop()


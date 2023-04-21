from tkinter import *
from tkinter import colorchooser
import serial
import time

root = Tk()
root.title("LED Color Picker")
root.geometry("300x150")
root.resizable(False, False)

def color():
    mycolor = colorchooser.askcolor()[0]
    r = str(mycolor[0])
    g = str(mycolor[1])
    b = str(mycolor[2])
    while len(r) < 3:
        r = f"0{r}"
    while len(g) < 3:
        g = f"0{g}"
    while len(b) < 3:
        b = f"0{b}"        
    assembly = f"{r}{g}{b}"
    print(assembly)
    c= Canvas(root, width=300, height=100)
    c.place(x=150, y=150, anchor=CENTER)
    my_label = Label(root, text=assembly, fg="grey", font=("Arial", 16))
    my_label.place(x=150, y=90, anchor=CENTER)
    s = serial.Serial("COM10", 9600, timeout = 2)
    print(assembly)
    s.write(bytes(assembly,'utf-8'))
    print(assembly)

def anim():
    s = serial.Serial("COM10", 9600, timeout = 2)
    s.write(bytes("555555555",'utf-8'))

 
my_button = Button(root, text="LED COLOR", command=color, font=("Arial", 15), width=11, height=1).pack(pady=15)
RGB = Button(root, text="LED COLOR", command=anim, font=("Arial", 15), width=11, height=1).pack(pady=15)

root.mainloop()
from tkinter import *
from tkinter import colorchooser
import serial

root = Tk()
root.title("LED Color Picker")
root.geometry("300x130")
root.resizable(False, False)

def anim():
    anim = "555555555"
    s = serial.Serial("COM10", 9600, timeout = 2)
    print(anim)
    s.write(bytes(anim,'utf-8'))
    print("Success")

def anim2():
    anim2 = "444444444"
    s = serial.Serial("COM10", 9600, timeout = 2)
    print(anim2)
    s.write(bytes(anim2,'utf-8'))
    print("Success")

def anim3():
    anim2 = "333333333"
    s = serial.Serial("COM10", 9600, timeout = 2)
    print(anim2)
    s.write(bytes(anim2,'utf-8'))
    print("Success")

def anim4():
    anim2 = "666666666"
    s = serial.Serial("COM10", 9600, timeout = 2)
    print(anim2)
    s.write(bytes(anim2,'utf-8'))
    print("Success")


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

my_button = Button(root, text="LED COLOR", command=color, font=("Arial", 12), width=11, height=1)
my_button.place(x=3, y=23)
my_button2 = Button(root, text="AN1", command=anim, font=("Arial", 10), width=4, height=1)
my_button2.place(x=120, y=25)
my_button3 = Button(root, text="AN2", command=anim2, font=("Arial", 10), width=4, height=1)
my_button3.place(x=165, y=25)
my_button4 = Button(root, text="AN3", command=anim3, font=("Arial", 10), width=4, height=1)
my_button4.place(x=210, y=25)
my_button5 = Button(root, text="AN4", command=anim4, font=("Arial", 10), width=4, height=1)
my_button5.place(x=255, y=25)

root.mainloop() 
import random, sys, os, time, wave
from tkinter import *
from tkinter.ttk import *
from winsound import *

def clicked():
	global Harambes
	global tk_Harambes
	Harambes+=1
	tk_Harambes.set("Times Target has been clicked: " + str(Harambes))
	PlaySound('gunsound.wav', SND_ASYNC)

root = Tk()

Harambes = 0
tk_Harambes = StringVar()
tk_Harambes.set("Times Target has been clicked: " + str(Harambes))

img = PhotoImage(file="Harambe.gif")
Harambe_button = Button(root, image=img, command=clicked)
Harambe_button.pack()
label = Label(root, textvariable=tk_Harambes, font=("Helvetica", 16))
label.pack()
root.mainloop()




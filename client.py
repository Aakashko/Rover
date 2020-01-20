#!/usr/bin/python           
import socket
import sys

s = socket.socket()
host = "192.168.43.190"
port = 80
s.connect((host, port))
move=""
move=raw_input("specify the movement:")
while(move!="stop."):
	if((move=="w." or move=="a." or move=="s." or move=="d." or move=="stop.")!=0):
		s.send(move.encode())
	else:	
		print("error")
	move=raw_input("specify the movement:")
s.send(move.encode())
s.close()
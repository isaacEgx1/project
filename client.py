import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("127.0.0.1", 4433))

while True:
    msg = input("Client: ")
    client.send(msg.encode())

    data = client.recv(1024)
    print("Server:", data.decode())

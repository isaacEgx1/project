import socket 
import threading

def handle_client(conn,addr):
    print(f"new connection by {addr}")

    while True:
        client_msg = conn.recv(2048).decode()
        if not client_msg:
            break
        if client_msg.lower() == "exit":
            print(f"connection with {addr} closed by client")
            break 
        print(f"message from {addr} : {client_msg}" )
        server_msg = input("You : ")
        conn.send(server_msg.encode())
        if server_msg.lower() == "exit":
            print(f"connection with {addr} closed by server")
            break
    conn.close()
    print(f"connection with {addr} ended")

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("localhost", 4433))
s.listen(5)
print("server is listening on port 4433")

while True:
    conn , addr = s.accept()
    t = threading.Thread(target=handle_client, args=(conn,addr))
    t.start()


# 💬 minitalk

## Description
**minitalk** is a small communication program that uses UNIX signals to send and receive messages between a client and a server.

## Usage
1. Clone the repo on your machine.
2. Open two terminal windows and on one of them run `make`, then `./server`.
3. On the other window run `./client PID MESSAGE`: the PID has been printed on the server's window and the message is just some text contained inside of "" in case there are spaces.
4. The server will stay open waiting to receive messages until you close the terminal or press CTRL + C.

## Grade
I only the Bonus part partially so I got **115**.

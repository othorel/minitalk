# 🛰️ Minitalk - C Project for Signal-Based Communication

<p align="center">
  <img src="https://github.com/leogaudin/42_project_badges/raw/main/badges/minitalk_bonus.webp" />
</p>

Welcome to **Minitalk**, a C project that implements a communication system between a **server** and a **client** using Unix signals (`SIGUSR1` and `SIGUSR2`). The goal of this project is to transmit messages from the client to the server bit by bit, improving understanding of inter-process communication and Unix signal handling.

---

<p align="center">
  <img src="https://raw.githubusercontent.com/42ProjectBadges/main/badges/42-42badge.png" />
</p>

---
## 📋 Project Overview

| **Category**               | **Functions**                                                                                                                                 |
|----------------------------|------------------------------------------------------------------------------------------------------------------------------------------------|
| **Communication**           | `send_message`, `receive_message`                                                                                                              |
| **Signal Handling**         | `signal_handler`, `setup_signal_handlers`                                                                                                       |
| **Client & Server Logic**   | `client`, `server`                                                                                                                              |

---

## 🚀 Key Features

1. **Signal-Based Communication**:
   - Implement communication between a client and a server using Unix signals (`SIGUSR1` and `SIGUSR2`), transmitting each character as a sequence of bits.

2. **Send Messages Bit by Bit**:
   - The client sends messages to the server, encoding each character in binary and transmitting it using signals one bit at a time.

3. **Server Receiving Messages**:
   - The server listens for signals, accumulates the bits, and reconstructs the message once all 8 bits of a character are received.

4. **Efficient Signal Management**:
   - Efficient signal handling using Unix signal functions such as `signal()`, with proper error handling and memory management.

---

## 🗂️ File Structure

| **File**                | **Description**                                                                                           |
|-------------------------|-----------------------------------------------------------------------------------------------------------|
| `Makefile`              | Automates the compilation process. Run `make` to generate the `client` and `server` executables.           |
| `minitalk.h`            | Header file with function prototypes and necessary includes.                                               |
| `minitalk_bonus.h`      | Header file with function prototypes and necessary includes.                                               |
| `client.c`              | Implementation of the client, responsible for sending the message.                                         |
| `server.c`              | Implementation of the server, responsible for receiving and displaying the message.                        |
| `client_bonus.c`        | Implementation of the client, responsible for sending the message.                                         |
| `server_bonus.c`        | Implementation of the server, responsible for receiving and displaying the message.                        |

---

## 🔧 Compilation Instructions

Use the **Makefile** to compile the project.

- **Compile the project:**
  ```bash
  make

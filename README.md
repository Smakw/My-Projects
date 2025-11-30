# Automated Lighting- Arduino project
# Overview

This project demonstrates communication between two Arduino boards to control LEDs using button input. When a button on one Arduino is pressed, the second Arduino receives the signal and changes the state of its LED. This project was created for a lab assignment focused on understanding Arduino communication, wiring, and embedded systems programming.

# Features
  Two Arduino boards connected together

  One board sends a signal when its button is pressed

  The other board receives the signal and changes an LED state

  Reliable communication using Arduino libraries

  Clear demonstration of embedded input/output behavior


# How It Works (Step-by-Step Explanation)
1. Project Goal
   
The purpose of this project is to show how two microcontrollers can communicate. When the user presses a button on Arduino A, it sends a signal to Arduino B, which then toggles or updates its LED.

This assignment focuses on:

Microcontroller communication
Digital input/output
Basic embedded system design
Correct wiring with shared ground

2. Hardware Setup
Components
2 Arduino boards (Uno R3, Uno R4, etc.)
2 LEDs
2 Resistors (220Ω recommended)
1–2 Pushbuttons
Jumper wires
Shared GND connection between both Arduinos

Wiring Summary

Sender Arduino (with button):

Button → digital input pin

Internal pull-up/pull-down used depending on code

When pressed, the Arduino sends a “1”

When released, it sends a “0”

Receiver Arduino (with LED):

LED → a digital output pin

Turns on/off depending on what it receives

Both Arduinos share:

Ground

Communication lines (I2C)

3. Code Logic
Sender Arduino (Button Board)

Reads from the button pin

If pressed → sends the value “1”

If not pressed → sends the value “0”

Repeats continuously

Receiver Arduino (LED Board)

Listens for incoming data

Reads one byte (“1” or “0”)

If “1” is received → LED turns ON

If “0” is received → LED turns OFF

The communication ensures both boards stay synchronized.

4. Testing Procedure

To test the system:

Upload sender code to Arduino A

Upload receiver code to Arduino B

Connect both boards physically (ground + data lines)

Press the button → observe LED on second board

Release the button → LED changes back

Everything should respond immediately.

Results

The project successfully demonstrates:

Correct wiring between two Arduinos

Real-time communication

Button state changes controlling a remote LED

Stable and reliable signal handling

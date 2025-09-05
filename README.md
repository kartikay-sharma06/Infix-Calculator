# Infix Expression Calculator

A simple C++ infix calculator that evaluates arithmetic expressions using stack data structures. This project demonstrates how to parse and evaluate expressions while respecting operator precedence.

# Overview

This calculator reads infix arithmetic expressions directly from user input. It supports the following operators:

Addition +

Subtraction -

Multiplication *

Division /

Operator precedence is handled correctly, meaning multiplication and division are executed before addition and subtraction. Division by zero is prevented, and only supported operators are processed.

Expressions must end with one of the following characters:

=

;

E or e

This flexible termination allows multiple expressions in a single run.

# Features

Stack-based evaluation with numStack and opStack

Handles operator precedence (+, -, *, /)

Prevents division by zero

Supports multiple calculations per session

Interactive mode – asks user if they want to continue

# Example Usage

Input:  12+3*4; 
Output: Result: 24  

Input:  20/5+7=  
Output: Result: 11  

es# Secure Authentication Module for OS

## Project Overview
This project simulates a secure authentication mechanism similar
to those used in operating systems. The system demonstrates how
user authentication and security controls are handled at the OS level.

## Planned Features
- User registration
- Login authentication
- OTP-based verification
- Session management
- Account lockout after multiple failed attempts
- Security audit logging

## Technologies Used
- C++ Programming Language
- VS Code
- MinGW / GCC Compiler
- Windows API

## Operating System Concepts Used
- Authentication and Authorization
- User Session Management
- Access Control
- Security Logging
- Account Locking Mechanism

## Goal for Day 1
- Create GitHub repository
- Define project scope and objectives
- Prepare base documentation for the project

---

## Day 2 – Basic Menu Implementation

On Day 2, a basic menu-driven interface was implemented.
This menu acts as the entry point of the authentication system,
similar to how an operating system presents login options.

### Features Added
- Displayed main authentication menu
- Options for:
  - User Registration
  - User Login
  - Exit system
- User input handling for menu selection

This forms the foundation for adding authentication logic
in the upcoming stages.

---

## Day 3 – User Registration Module

On Day 3, the user registration functionality was implemented.
This allows new users to create an account by providing a
username and password.

### Features Added
- User registration module
- In-memory storage of user credentials
- Duplicate username detection

### OS Concept Used
- User account creation
- Access control preparation

---

## Day 4 – Login Authentication with OTP (Multi-Factor Authentication)

On Day 4, user login authentication was enhanced by integrating
OTP-based verification. This introduces multi-factor authentication,
which is commonly used in operating systems for improved security.

### Features Added
- User login using username and password
- OTP (One-Time Password) generation
- OTP verification before granting access
- Prevention of unauthorized access

### OS Concepts Used
- Authentication and authorization
- Multi-factor authentication (MFA)
- Secure access control

---

## Final Day – Session Management, Audit Logging and Final Integration

On the final day, all remaining OS-level security features were
integrated into the authentication module. The system now maintains
user sessions, supports secure logout, and records all security events
using audit logs.

### Features Added
- User session management
- Secure logout mechanism
- Security audit logging
- Account lockout after failed attempts
- Full system integration

### OS Concepts Used
- Session management
- Access control
- Security auditing
- Account locking
- System-level authentication workflow


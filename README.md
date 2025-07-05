
## Password Manager (C++ Project)

A secure and beginner-friendly **C++ terminal-based Password Manager**.  
This project allows users to register, log in, and securely store login credentials (website, username, password) in an encrypted vault using simple XOR encryption, stored as JSON files.

##  Features

-  User Registration & Login
-  Encrypted credential vault using XOR cipher
-  Per-user credential storage in `.json` files
-  Add, View, and Delete saved website credentials
-  Clean CLI menu-based UI
-  Modular C++ file structure

---

##  Technologies Used

- C++17
- [nlohmann/json](https://github.com/nlohmann/json) (for JSON file storage)
- File I/O (`fstream`)
- XOR-based reversible encryption

---

##  Project Structure

```
PasswordManager/
├── main.cpp                # Entry point and main menu
├── auth.cpp / auth.h       # User registration and login
├── vault.cpp / vault.h     # Vault functions (add, view, delete)
├── utils.cpp / utils.h     # Helper functions (hashing, masking, etc.)
├── json.hpp                # nlohmann JSON library
└── vault_<username>.json   # Per-user encrypted credential file
```

---

##  How to Compile & Run

###  Compile:
```bash
g++ main.cpp auth.cpp vault.cpp utils.cpp -o manager
```

### ▶ Run:
```bash
./manager
```

---

##  Sample Output

```text
========= Password Manager =========
1. Register
2. Login
3. Exit
Enter your choice: 2
Enter username: xyz
Enter password: ****
Login successful!

Vault Menu for xyz:
1. Add a new credential
2. View all saved credentials
3. Delete a credential
4. Logout
```

---

##  How It Works

- Passwords and usernames are XOR-encrypted with a simple key.
- All credentials are stored in a per-user `.json` file.
- On login, the correct user’s vault is loaded and decrypted.
- JSON format allows easy expansion and parsing of vault contents.

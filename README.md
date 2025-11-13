# learning-c
just me learning basic c 
I just want to learn the basics and make a few small programs 
  (most of my code is private this is not all I made in C)

If you want to try running some of the very simple programs I made you will need to have GTK installed on your system since I made a program to make a simple window with a few buttons to play around with it  

There's also a new GUI calculator using gtk and css for the style

Here are the instructions to install GCC & GTK on Linux, MacOs and Windows:

---

### **For Linux (Ubuntu/Debian-based):**

#### **Install GCC:**
1. **Update your package list**:
   ```bash
   sudo apt update
   ```

2. **Install GCC**:
   ```bash
   sudo apt install build-essential
   ```
   This will install GCC along with other essential development tools.

3. **Verify GCC installation**:
   ```bash
   gcc --version
   ```
   This will display the installed version of GCC.
   If it says "unknown command" you will have to try installing it another way

#### **Install GTK:**
1. **Install GTK development libraries**:
   To install GTK 3 (the most commonly used version and the only one we need here):
   ```bash
   sudo apt install libgtk-3-dev
   ```

2. **Verify GTK installation** (for GTK 3):
   ```bash
   pkg-config --cflags --libs gtk+-3.0
   ```
---

### **For Arch Linux:**

1. **Update your package database**:
   ```bash
   sudo pacman -Syu
   ```

2. **Install GCC**:
   ```bash
   sudo pacman -S base-devel
   ```
   The `base-devel` package group includes GCC and other essential tools for development.

3. **Verify GCC installation**:
   ```bash
   gcc --version
   ```
### 2. **Install GTK**

1. **Install GTK 3 (most commonly used)**:
   ```bash
   sudo pacman -S gtk3
   ```

3. **Verify GTK installation**:
   For GTK 3, you can check the installation with:
   ```bash
   pkg-config --cflags --libs gtk+-3.0
   ```

  **After Installation:**

Once installed, you can compile programs that use GTK with GCC. Here’s an example:

```bash
gcc `pkg-config --cflags gtk+-3.0` my_program.c -o my_program `pkg-config --libs gtk+-3.0`
```

This will compile `my_program.c` using the GTK 3 libraries.

dm my discord (im.awsum) if you run into issues

--- 

### **For MacOs:**

#### **Install GCC:**
1. **Install Xcode Command Line Tools**:
   ```bash
   xcode-select --install
   ```

2. **Verify GCC installation**:
   ```bash
   gcc --version
   ```

#### **Install GTK:**
1. **Install Homebrew** (if you don't have it installed):
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. **Install GTK using Homebrew**:
   For GTK 3:
   ```bash
   brew install gtk+3
   ```

3. **Verify GTK installation**:
   ```bash
   pkg-config --cflags --libs gtk+-3.0
   ```

---

## **For Windows** 

*sigh*
Not only is your operating system closed-source but it's also bloated, filled with a bunch of ads, has a ton of included spyware and it's not even free.  I won't type a single line of code for this operating system.  With all the time it took to scroll down this page it probably took away one of your victory royale...  I guess your bloated operating system supports Fortnite... You should go back to playing that instead of trying to run code made for the superior Unix like operating systems.  

---
# I'd like to point out that *I use* ~~FreeBSD~~ *Arch btw*...

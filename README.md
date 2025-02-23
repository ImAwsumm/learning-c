# learning-c
just me learning basic c 
I just want to learn the basics and make a few small programs 
  (most of my code is private this is not all I made in C)

If you want to try running some of the very simple programs I made you will need to have GTK installed on your system since I made a program to make a simple window with a few buttons to play around with it  

Here are the instructions to install GCC & GTK on Linux, MacOs and Windows:


### 1. **For Linux (Ubuntu/Debian-based):**

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

#### **Install GTK:**
1. **Install GTK development libraries**:
   To install GTK 3 (the most commonly used version and the only one we need here):
   ```bash
   sudo apt install libgtk-3-dev
   ```

   For GTK 4,: (Optional)
   ```bash
   sudo apt install libgtk-4-dev
   ```

2. **Verify GTK installation** (for GTK 3):
   ```bash
   pkg-config --cflags --libs gtk+-3.0
   ```

---

### 2. **For MacOs:**

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

   For GTK 4 ( you won't need it here)
   ```bash
   brew install gtk4
   ```

3. **Verify GTK installation**:
   ```bash
   pkg-config --cflags --libs gtk+-3.0
   ```

---

### 3. **For Windows**

 No. 
 I guess your operating system supports Fortnite... You should go play that instead of trying to run code.

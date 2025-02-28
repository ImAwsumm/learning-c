# Gtk Window with Buttons and Dynamic Text

I am currently working on making a gui calcultor and this is my basis for it.

A simple GTK application in C that creates a window with two buttons: one to display text when clicked and another to close the window.

## Features: 
*there are very few features*
- **Display Text Button**: Updates the window text when clicked.
- **Close Window Button**: Closes the window when clicked.

## Requirements:
- **GTK 3.0**
    (windows version is **not** coming because windows sucks.)
- **C Compiler**
      - (gcc)

## Installation & Usage:

1. **Install GTK 3.0**:
   ```bash
   sudo apt-get install libgtk-3-dev
   ```
2. **Download the repo**
   ```bash
    git clone https://github.com/ImAwsumm/learning-c.git
   ```
3. **Compile the Code**:
   ```bash
   gcc -o SimpleAwsumWindow makewindow.c $(pkg-config --cflags --libs gtk+-3.0)
   ```

4. **Run the Application**:
   ```bash
   ./SimpleAwsumWindow
   ```

   And "Voila" here you go you just executed my software.

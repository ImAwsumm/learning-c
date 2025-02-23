# Gtk Window with Buttons and Dynamic Text

A simple GTK application in C that creates a window with two buttons: one to display text when clicked and another to close the window.

## Features:
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

2. **Compile the Code**:
   ```bash
   gcc -o gtk_text_window gtk_text_window.c $(pkg-config --cflags --libs gtk+-3.0)
   ```

4. **Run the Application**:
   ```bash
   ./gtk_text_window
   ```

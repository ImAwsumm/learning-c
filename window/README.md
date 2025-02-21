### In order to compile the C code you will have to run this command 
`` gcc `pkg-config --cflags gtk+-3.0` -o window gtk-window.c `pkg-config --libs gtk+-3.0`  `` 
This C program demonstrates how to create a basic GUI (graphical user interface) using the GTK library.


## **Key Features:**
  
  **Window Creation:**.
    - the window is created and is set to a default size of 1920*1080 pixels
    - The window is titled "My First Window" and is set to a default size of 1920 * 1080 pixels
      (*1920x1080 is a very popular screen resolution usually reffered as 1080p*)
      
## **GTK Main Loop:**
   - The `gtk_main()` function starts the main event loop.  This is responsible for the user interactions with the window.  

#### **What does this do?**
This program is to demonstrate how to set up a basic GTK window with C.

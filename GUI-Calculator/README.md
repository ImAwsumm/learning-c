*Publishing my work before the 03/05/2025*

# Awsum-GUI-Calculator
An Awsum Calculator made in C with GTK to have a cool gui 

---
# GTK Calculator
- A simple yet functional calculator built with GTK and C, featuring a classic design.
- Easy to understand source-code

## Features
- Basic arithmetic operations (+, -, *, /)
- Decimal point support
- Error handling for invalid inputs
- Division by zero protection
- Clear function
- User-friendly GUI

Maybe... second on screen keyboard layout 
Save outputs coming soon?

dm ```im.awsum``` on discord for suggestions 

## Dependencies
- GTK 3.0
- GCC compiler
- pkg-config

### Arch Linux
Install GTK3 and build dependencies
```bash
sudo pacman -S gtk3 base-devel
sudo pacman -S gcc pkgconf
sudo pacman -S git
```
Install compiler and development tools

Follow the same instructions to download the code
Dm my discord ``` im.awsum ```

### Ubuntu/Debian/Mint
```bash
sudo apt update
sudo apt-get install libgtk-3-dev
sudo apt install build-essential
sudo apt install pkg-config
sudo apt install git
```

### Fedora
```bash
sudo dnf install gcc
sudo dnf install gtk3-devel
sudo dnf install pkg-config
```
### FreeBSD
```bash
sudo pkg update
sudo pkg install gtk3
sudo pkg install gcc
sudo pkg install pkgconf
```
---

## Building and Running

download with 
```bash
git clone https://github.com/ImAwsumm/GUI-Calculator.git
cd GUI-Calculator
```
compile with 

```bash
gcc GUI-Calculator.c -o calculator $(pkg-config --cflags --libs gtk+-3.0) -lm
```
execute with

```bash
./calculator
```

Make sure you have the libraries installed for the code to compile
If you're running into issues it is likely that you don't have the necessary libraries
(the instructions for installing libraries are above distribition specific).
If your Operating system is not listed you can still install it but you have to find instructions somewhere else

---
## Usage

- Either use the buttons to type or your keyboard
- Use operators (+, -, *, /) for calculations
- Press the 'C' button to clear the input and type new e
equations

## Error Handling
The calculator handles various error cases including; divding by zero, having an Invalid character syntax, sending unrecognized numbers and sending an empty equation
Try breaking it and tell me about the issues you find 
My discord : ``im.awsum``

## License

GPLv3

## Contributing

Feel free to submit issues, fork the repository, and create pull requests for any improvements even if minor.
My discord : ``im.awsum``

## Forking or Modifying 

If you would like to improve something about this code make a pull request and I will review it. 
If it's not accepted then you should make a fork.

this is based on a calculator a friend of mine made in python
[@iambetter27](https://github.com/iambetter27)
Go check it out !

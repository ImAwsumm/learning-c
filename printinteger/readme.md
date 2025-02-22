<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simple C Program</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; background-color: #f4f4f4; }
        h1 { color: #333; }
        pre { background-color: #282c34; color: white; padding: 10px; font-family: monospace; }
        p { font-size: 1.2em; line-height: 1.6; }
    </style>
</head>
<body>

    <h1>Simple C Program</h1>
    
    <pre>
#include <stdio.h>
int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("You entered: %d", number);
    return 0;
}
    </pre>

    <p>This program asks the user to enter an integer and displays it back. It uses <code>printf</code> for output and <code>scanf</code> for input.</p>

</body>
</html>

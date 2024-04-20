/** \file source.cpp
* \brief LAB1-LAB2
* \details This program allows the user to draw various shapes such as horizontal lines, vertical lines, squares, and rectangles.
* \author Mike Kapetanakis 
* \version 1.1 *Fixed
* \date 2024-04-20
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
/**
* \brief Draws a horizontal line of a specified length using the given character.
* @param length The length of the line.
* @param ch The character used to draw the line.
*/
void drawHorizontalLine(const int length, const char ch);

/**
* \brief Draws a vertical line of a specified height using the given character.
* @param height The height of the line.
* @param ch The character used to draw the line.
*/
void drawVerticalLine(const int height, const char ch);

/**
* \brief Draws a square of a specified size using the given character.
* @param size The size (side length) of the square.
* @param ch The character used to draw the square.
*/
void drawSquare(const int size, const char ch);

/**
* \brief Draws a rectangle of a specified height and width using the given character.
* @param height The height of the rectangle.
* @param width The width of the rectangle.
* @param ch The character used to draw the rectangle.
*/
void drawRectangle(const int height, const int width, const char ch);

/**
* \brief Draws a specified number of random shapes.
* @param numShapes The number of shapes to draw.
*/
void drawShapes(const int numShapes);

/**
* \brief Fills arrays with values for shape type, length, and character.
* @param shapeTy Array to store shape types.
* @param shapeLen Array to store shape lengths.
* @param shapeCh Array to store shape characters.
* @param arrSize Size of the arrays.
*/
void initializeArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int arrSize);

/**
* \brief Draws shapes specified in arrays.
* @param shapeTy Array containing shape types.
* @param shapeLen Array containing shape lengths.
* @param shapeCh Array containing shape characters.
* @param arrSize Size of the arrays.
*/
void drawArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int arrSize);

// Constants
const int MAX_SHAPES = 10;

int main() {
    srand(time(NULL)); // Seed for random number generation

    int choice;

    do {
        // Display menu
        cout << "1) Draw a horizontal line\n";
        cout << "2) Draw a vertical line\n";
        cout << "3) Draw a square\n";
        cout << "4) Draw a rectangle\n";
        cout << "5) Draw random shapes\n"; // Added option for drawing random shapes
        cout << "6) Quit\n"; // Updated quit option to 6
        cout << "Enter your Option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int length;
                char ch;
                cout << "Enter length and character: ";
                cin >> length >> ch;
                drawHorizontalLine(length, ch);
                break;
            }
            case 2: {
                int height;
                char ch;
                cout << "Enter height and character: ";
                cin >> height >> ch;
                drawVerticalLine(height, ch);
                break;
            }
            case 3: {
                int size;
                char ch;
                cout << "Enter size and character: ";
                cin >> size >> ch;
                drawSquare(size, ch);
                break;
            }
            case 4: {
                int height, width;
                char ch;
                cout << "Enter height, width, and character: ";
                cin >> height >> width >> ch;
                drawRectangle(height, width, ch);
                break;
            }
            case 5: {
                int numShapes;
                cout << "Enter the number of random shapes to draw: ";
                cin >> numShapes;
                drawShapes(numShapes);
                break;
            }
            case 6:
                cout << "Quitting...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void drawHorizontalLine(const int length, const char ch) {
    for (int i = 0; i < length; ++i) {
        cout << ch;
    }
    cout << endl;
}

void drawVerticalLine(const int height, const char ch) {
    for (int i = 0; i < height; ++i) {
        cout << ch << endl;
    }
}

void drawSquare(const int size, const char ch) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << ch;
        }
        cout << endl;
    }
}

void drawRectangle(const int height, const int width, const char ch) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << ch;
        }
        cout << endl;
    }
}

void drawShapes(const int numShapes) {
    for (int i = 0; i < numShapes; ++i) {
        int shapeType = rand() % 4 + 1;
        int shapeLength = rand() % 16 + 5;
        char shapeCharacter = rand() % 94 + 33; // Printable ASCII characters from 33 to 126

        switch (shapeType) {
            case 1:
                drawHorizontalLine(shapeLength, shapeCharacter);
                break;
            case 2:
                drawVerticalLine(shapeLength, shapeCharacter);
                break;
            case 3:
                drawSquare(shapeLength, shapeCharacter);
                break;
            case 4:
                drawRectangle(shapeLength, shapeLength * 2, shapeCharacter); // Width is twice the length
                break;
        }
    }
}

void initializeArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int arrSize) {
    for (int i = 0; i < arrSize; ++i) {
        shapeTy[i] = rand() % 4 + 1; // Random shape type (1-4)
        shapeLen[i] = rand() % 20 + 1; // Random shape length (1-20)
        shapeCh[i] = rand() % 94 + 33; // Random ASCII character (33-126)
    }
}

void drawArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int arrSize) {
    for (int i = 0; i < arrSize; ++i) {
        switch (shapeTy[i]) {
            case 1:
                drawHorizontalLine(shapeLen[i], shapeCh[i]);
                break;
            case 2:
                drawVerticalLine(shapeLen[i], shapeCh[i]);
                break;
            case 3:
                drawSquare(shapeLen[i], shapeCh[i]);
                break;
            case 4:
                drawRectangle(shapeLen[i], shapeLen[i] * 2, shapeCh[i]); // Width is twice the length
                break;
        }
    }
}

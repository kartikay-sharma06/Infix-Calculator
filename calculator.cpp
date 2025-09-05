#include <iostream>
using namespace std;

#define MAX 100

// Stack for numbers
int numStack[MAX];
int numTop = -1;

// Stack for operators
char opStack[MAX];
int opTop = -1;

// Push and Pop functions
void pushNum(int val) { numStack[++numTop] = val; }
int popNum() { return numStack[numTop--]; }

void pushOp(char op) { opStack[++opTop] = op; }
char popOp() { return opStack[opTop--]; }

// Precedence function
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Apply operation
void applyOp() {
    int b = popNum();
    int a = popNum();
    char op = popOp();

    switch (op) {
        case '+': pushNum(a + b); break;
        case '-': pushNum(a - b); break;
        case '*': pushNum(a * b); break;
        case '/':
            if (b == 0) {
                cout << "Error: division by zero" << endl;
                exit(1);
            }
            pushNum(a / b);
            break;
    }
}

// Reset stacks between calculations
void resetStacks() {
    numTop = -1;
    opTop = -1;
}

int main() {
    cout << "Simple Infix Calculator\n";
    cout << "End each expression with '=', ';', or 'E'.\n";
    cout << "Example: 12+3*4=  (or just 12+3*4;)\n\n";

    while (true) {
        resetStacks();
        cout << "Enter infix expression (end with '=', ';', or 'E'):\n";

        char ch;
        int num = 0;
        bool inNumber = false;

        // Read one expression
        while (true) {
            if (!(cin >> ch)) {
                cout << "\nNo more input. Exiting.\n";
                return 0;
            }

            // Allow multiple end options
            if (ch == '=' || ch == ';' || ch == 'e' || ch == 'E') break;

            if (ch >= '0' && ch <= '9') {   // digit
                num = num * 10 + (ch - '0');
                inNumber = true;
            } else {
                if (inNumber) {             // push number before operator
                    pushNum(num);
                    num = 0;
                    inNumber = false;
                }
                // Basic validation: only accept + - * /
                if (precedence(ch) == 0) {
                    cout << "Error: unsupported operator '" << ch << "'\n";
                    return 1;
                }
                // Handle operator precedence
                while (opTop != -1 && precedence(opStack[opTop]) >= precedence(ch)) {
                    applyOp();
                }
                pushOp(ch);
            }
        }

        if (inNumber) {  // push last number
            pushNum(num);
        }

        // Apply remaining operations
        while (opTop != -1) {
            applyOp();
        }

        // Output result
        cout << "Result: " << popNum() << endl;

        // Ask to continue
        cout << "Do you want to calculate more? (Y/N): ";
        char resp;
        if (!(cin >> resp)) {
            cout << "\nNo more input. Exiting.\n";
            return 0;
        }
        if (resp != 'y' && resp != 'Y') {
            cout << "Goodbye!\n";
            break;
        }

        cout << '\n'; // spacing before next prompt
    }

    return 0;
}

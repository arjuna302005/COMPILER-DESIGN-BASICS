#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>
using namespace std;
int arith_expression_evaluate(const string& arith_expression) {
    stack<int> elements;
    stack<char> operators;

    for (size_t i = 0; i < arith_expression.length(); ++i) {
        if (isspace(arith_expression[i])) {
            continue;
        } else if (isdigit(arith_expression[i])) {
            int val = 0;
            while (i < arith_expression.length() && isdigit(arith_expression[i])) {
                val = val * 10 + (arith_expression[i] - '0');
                i++;
            }
            elements.push(val);
            i--;
        } else if (arith_expression[i] == '(') {
            operators.push(arith_expression[i]);
        } else if (arith_expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int val2 = elements.top();
                elements.pop();
                int val1 = elements.top();
                elements.pop();
                char op = operators.top();
                operators.pop();
                switch (op) {
                    case '+': elements.push(val1 + val2);
                              break;
                    case '-': elements.push(val1 - val2);
                              break;
                    case '*': elements.push(val1 * val2);
                             break;
                    case '/': 
                        if (val2 == 0) throw std::runtime_error("Division by zero");
                        elements.push(val1 / val2); 
                              break;
                }
            }
            if (!operators.empty()) operators.pop();
        } else if (arith_expression[i] == '+' || arith_expression[i] == '-' ||
            arith_expression[i] == '*' || arith_expression[i] == '/') {
            while (!operators.empty() && operators.top() != '(' &&
                   ((arith_expression[i] == '*' || arith_expression[i] == '/') ||
                    (operators.top() != '*' && operators.top() != '/'))) {
                int val2 = elements.top();
                elements.pop();
                int val1 = elements.top();
                elements.pop();
                char op = operators.top();
                operators.pop();
                switch (op) {
                    case '+': elements.push(val1 + val2);
                              break;
                    case '-': elements.push(val1 - val2); 
                              break;
                    case '*': elements.push(val1 * val2); 
                              break;
                    case '/': 
                        if (val2 == 0) throw std::runtime_error("Division by zero");
                        elements.push(val1 / val2); 
                              break;
                }
            }
            operators.push(arith_expression[i]);
        }
    }
    while (!operators.empty()) {
        int val2 = elements.top();
        elements.pop();
        int val1 = elements.top();
        elements.pop();
        char op = operators.top();
        operators.pop();
        switch (op) {
            case '+': elements.push(val1 + val2); break;
            case '-': elements.push(val1 - val2); break;
            case '*': elements.push(val1 * val2); break;
            case '/': 
                if (val2 == 0) throw std::runtime_error("Division by zero");
                elements.push(val1 / val2); 
                break;
        }
    }
    return elements.top();
}

int main() {
    string arith_expression;
    cout<<"\n\t\t--------Task 4 Compiler Design Basics -------";
    cout<<"\n\t\t\tEnter an arithmetic expression to solve  ";
    getline(cin, arith_expression);
    try {
        int result = arith_expression_evaluate(arith_expression);
        cout << "\n\t\t\tOutput of the evaluated expression: " << result << endl;
    } catch (const std::runtime_error& error) {
        cerr << "\n\t\t\tError: " << error.what() << endl;
    }
    return 0;
}

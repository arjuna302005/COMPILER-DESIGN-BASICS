# COMPILER-DESIGN-BASICSMore actions

COMPANY NAME -CODTECH IT SOLUTIONS

NAME -Arjun Ganpati Waghmode

INTERN ID -CT08DK949

DOMAIN NAME -C++ PROGRAMMING

DURATION -8 WEEKS(APRIL 25th to JUNE 25th 2025)

MENTOR -NEELA SANTHOSH KUMAR




🔍 Overview of Arithmetic Expression Evaluator in C++


This C++ program is a basic arithmetic expression evaluator that supports parentheses, operator precedence, and integer arithmetic. It mimics the behavior of a simple calculator.



🧠 Key Learning Objectives


Understand parsing arithmetic expressions.

Learn how to simulate operator precedence using stacks.

Practice the use of standard template library (STL) components like stack.

Handle runtime exceptions (e.g., divide by zero).

Improve program design by using structured and modular logic.

🧩 How It Works: Step-by-Step Explanation


📥 1. Input from the Use
r
getline(cin, arith_expression);
Uses getline() to read an entire line, allowing multi-digit numbers and space handling.

🔄 2. Parsing and Evaluation Function: arith_expression_evaluate

This function is responsible for parsing and evaluating the expression.

🧺 Stacks Used:

stack<int> elements;
stack<char> operators;
elements: Stores integers (operands).

operators: Stores operators and parentheses.

🔍 3. Loop Through Each Character

for (size_t i = 0; i < arith_expression.length(); ++i)
Each character is processed one at a time.

Whitespaces are skipped with isspace.

🔢 4. Handling Numbers (Multi-digit Support)


while (i < arith_expression.length() && isdigit(arith_expression[i]))
Constructs full numbers, not just single digits.

Example: "123" is parsed as one number, not 1, 2, 3.


🧮 5. Handling Parentheses
'(' is pushed directly to the operators stack.

')' triggers evaluation until '(' is found.


while (!operators.empty() && operators.top() != '(')
All operations inside the parenthesis are computed before proceeding.

➕ 6. Handling Operators +, -, *, /

This is where operator precedence logic is implemented.


while (!operators.empty() && operators.top() != '(' &&
       ((arith_expression[i] == '*' || arith_expression[i] == '/') ||
        (operators.top() != '*' && operators.top() != '/')))

        
⚖ Precedence Rules:

* and / have higher precedence than + and -.

This block checks whether the current operator should wait or trigger evaluation.

⚠ 7. Division by Zero Handling


if (val2 == 0) throw std::runtime_error("Division by zero");
Protects against illegal mathematical operations.

Helps maintain program stability and user safety.

🏁 8. Final Evaluation

After the loop ends, remaining operators are evaluated:


while (!operators.empty()) { ... }
Ensures nothing is left behind (especially for expressions without parentheses).

📤 9. Result Output

cout << "\n\t\t\tOutput of the evaluated expression: " << result << endl;
The final result is printed to the user.

Uses try-catch to handle errors gracefully.

💡 Why Use Stacks for Expression Evaluation?

Stacks naturally match how operators and operands behave in mathematical notation.

📦 Operators Stack

Temporarily holds operations until ready to evaluate.

📦 Elements Stack

Accumulates results and operands.

🧠 What Will You Learn From This Code?

How to design expression evaluators.

Importance of operator precedence.

Real-world application of data structures (stack).

How to write robust programs using exception handling.

Improved C++ fluency using STL and parsing techniques.

💬 Enhancements You Can Try


✅ Add support for floating-point numbers.

✅ Add modulo (%) operator.

✅ Convert infix to postfix (Shunting-yard algorithm).

✅ Build a GUI calculator using this backend.

✅ Extend to variables and assignments (like x = 3 + 5).

🎯 Real-World Applications


@@ -183,19 +183,21 @@
 Parse arithmetic expressions

 Use stacks effectively
 
 Handle exceptions

 Implement precedence rules

 Design command-line calculators


 output



 output

 Handle exceptions

 Implement precedence rules

 Design command-line calculators
 
 COMPILER-DESIGN-BASICS

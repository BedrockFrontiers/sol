### Tests Directory

The `tests/` directory contains automated tests for various components of the Sol language implementation. These tests are designed to ensure the correctness and reliability of the language features and functionalities.

#### Structure:

- `lexer_test.sol`: Contains tests for the lexer component, which performs lexical analysis of Sol source code.
- `parser_test.sol`: Includes tests for the parser component, responsible for parsing Sol source code into an abstract syntax tree (AST).
- `compiler_test.sol`: Consists of tests for the compiler component, which translates Sol source code into executable bytecode or machine code.
- `interpreter_test.sol`: Contains tests for the interpreter component, which executes Sol code directly without compilation.

#### Purpose:

- Verify the correct behavior of individual language components.
- Ensure that language constructs are parsed and compiled accurately.
- Validate the execution of Sol code and expected output generation.

#### Usage:

Developers can run the tests using a testing framework or tool compatible with the Sol language. These tests can be executed as part of the continuous integration (CI) pipeline to automatically validate changes and contributions to the Sol language project.

#### Contribution:

Contributors are encouraged to expand the test suite by adding new test cases to cover additional language features, edge cases, and error scenarios. Consistent and comprehensive testing helps maintain the quality and stability of the Sol language implementation. But first, read the [Contributing Guide](../docs/contributing.md)

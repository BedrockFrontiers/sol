# Sol Language Reference

## Table of Contents
1. [Variables and Constants](#variables-and-constants)
2. [Control Flow](#control-flow)
3. [Functions](#functions)
4. [Standard Library](#standard-library)

## 1. Variables and Constants

### Declaration

Variables and constants in Sol are declared using the `store` keyword followed by the variable name and optional type annotation.

Example:

```c
store name = "John"
store mul age = 30
```

### Assignment

Assignment in Sol is performed using the `=` operator.

Example:

```lua
name = "Alice"
age = 25
```

## 2. Control Flow

### If-Else Statements

Sol supports conditional execution using if-else statements.

Example:

```haxe
if (condition) then
  // code to execute if condition is true
else
  // code to execute if condition is false
end
```

### Loops

Sol provides `for` and `while` loops for iterative execution.

Example:

```haxe
for (i = 0; i < 10; i++) do
  // code to execute in each iteration
end
```

## 3. Functions

### Declaration

Functions in Sol are defined using the `fn` keyword followed by the function name and parameter list enclosed in parentheses `()`.

Example:

```rust
fn add(x, y) do
  return x + y
end
```

### Invocation

Functions are invoked using the function name followed by the argument list.

Example:

```lua
result = add(10, 20)
```

## 4. Standard Library

Sol provides a standard library with built-in functions and modules for common tasks.

### IO Module

The IO module provides functions for input and output operations.

Example:

```haxe
import "io"
io.print("Hello, World!")
```

### Math Module

The Math module provides functions for mathematical operations.

Example:

```haxe
import "math"
result = math.pow(2, 3)
```

This reference document provides an overview of the core features and functionalities of the Sol language. For more detailed information, refer to the documentation and examples provided.

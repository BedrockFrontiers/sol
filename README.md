<div align="center">
  <a href="https://github.com/BedrockFrontiers/sol">
    <img src="https://github.com/BedrockFrontiers/sol/blob/main/assets/logos/logo.png" height="150" alt="Sol Programming Language" />
  </a>

  ### The Sol Programming Language
  
  [![License: Apache License 2.0](https://img.shields.io/badge/license-Apache%20License%202.0-blue?style=flat-square)](https://www.apache.org/licenses/LICENSE-2.0)
  [![Development Status](https://img.shields.io/badge/development%20status-Initial%20Stage-red?style=flat-square)](https://github.com/orgs/BedrockFrontiers/projects/1) \
  [![Stars](https://img.shields.io/github/stars/BedrockFrontiers/sol?style=flat-square)](https://github.com/BedrockFrontiers/stargazers)
  [![Code Size](https://img.shields.io/github/languages/code-size/BedrockFrontiers/sol?style=flat-square)](https://github.com/BedrockFrontiers/sol)
  [![Contributors](https://img.shields.io/github/contributors/BedrockFrontiers/sol?style=flat-square)](https://github.com/BedrockFrontiers/sol/graphs/contributors)
  [![Issues](https://img.shields.io/github/issues/BedrockFrontiers/sol?style=flat-square)](https://github.com/BedrockFrontiers/sol/issues) \
  [![Pull Requests](https://img.shields.io/github/issues-pr/BedrockFrontiers/sol?style=flat-square)](https://github.com/BedrockFrontiers/sol/pulls)
  [![Commit Activity](https://img.shields.io/github/commit-activity/t/BedrockFrontiers/sol?style=flat-square)](https://github.com/BedrockFrontiers/sol/commits/main)
  [![Last Commit](https://img.shields.io/github/last-commit/BedrockFrontiers/sol?style=flat-square)](https://github.com/BedrockFrontiers/sol/commits/main) \
  [![Made with Love](https://img.shields.io/badge/made%20with-love-pink?style=flat-square)](https://github.com/BedrockFrontiers/sol/graphs/contributors)
</div>

---

Sol is a programming language focused exclusively on automation, designed to simplify and expedite repetitive tasks and complex processes.

## Key Features

- **Automation Focus:** Sol has been developed with the goal of facilitating the automation of a wide variety of tasks and processes.
  
- **Simple and Intuitive Syntax:** Sol's syntax is designed to be straightforward and easy to understand, enabling developers to create automation scripts quickly.

- **Built-in Libraries:** Sol includes a variety of built-in libraries to facilitate the automation of common tasks, such as file manipulation, network communication, and interaction with external systems.

- **Integration Support:** Sol is compatible with a variety of platforms and services, allowing easy integration with other tools and systems.

## Running Tests with the Shell Script

This guide provides instructions on running tests using the provided shell script. Follow the steps below to execute tests for your Sol programming language project.

### Prerequisites

Before running tests, ensure you have the following:

- The `compile_unit_test.sh` and `compile_all_unit_tests.sh` shell script files on `./cmd/scripts`.
- Test unit files located in the `./tests/units` directory.
- Source code files located in the `pkg` and `utils` directories.

### Instructions

#### Compile single test

1. **Open Terminal**: Launch your terminal application.
2. **Navigate to Project Directory**: Change your current directory to the location of your Sol project.

```bash
cd path/to/your/sol/project
```

3. **Execute Shell Script**: Run the shell script by entering the following command:

```bash
./cmd/scripts/compile_unit_test.sh
```

4. **Enter Test Unit Name**: When prompted, input the name of the test unit file you wish to compile. For example, if your test unit file is named `lexer.test.c`, type `lexer.test.c` and press Enter.

#### Compile all tests

1. **Open Terminal**: Launch your terminal application.
2. **Navigate to Project Directory**: Change your current directory to the location of your Sol project.

```bash
cd path/to/your/sol/project
```

3. **Execute Shell Script**: Run the shell script by entering the following command:

```bash
./cmd/scripts/compile_all_unit_tests.sh
```

#### After steps

> * **Compilation Process**: The shell script will compile the specified test unit file along with all source files found in the `pkg` and `utils` directories.
> * **Verify Compilation**: After compilation, the path to the compiled executable will be displayed. This executable contains the compiled test unit.
> * **Execute Compiled Test**: To run the compiled test, execute the compiled executable from the generated path (`./tests/units/bin`).
> * **Interpret Test Results**: Observe the test output to determine if the tests passed or failed. Any error messages or unexpected behavior indicate test failures.

> [!IMPORTANT]\
> Please refrain from executing the compiled .exe file directly from your terminal. Doing so may lead to inaccurate test results due to dependencies on text files and directory structures.

## Contributing

Before you start contributing, we kindly ask you to take a moment to read our [Contributing Guide](./docs/contributing.md). This guide outlines the process for contributing to Sol, including how to submit bug reports, suggest enhancements, and make code contributions.

By familiarizing yourself with our contributing guidelines, you'll ensure that your contributions align with our project's goals and standards. Additionally, you'll have a clear understanding of how to engage with our community and make meaningful contributions to the project.

Whether you're a seasoned developer or new to open source, we value your input and welcome contributions from individuals of all backgrounds and skill levels. Together, we can make Sol an even better language for automation.

## Trademarks

The Threadmarks feature is a trademark owned by Bedrock Frontiers. All rights reserved.
If you wish to use the Threadmarks name or logo, please refer to our [Trademark Guide](./docs/trademark.md).

## Changelog

To view the complete development history of the Sol Programming Language, please refer to the [Commits History](https://github.com/BedrockFrontiers/sol/commits/main).

## License

This project is licensed under the [Apache License 2.0](./LICENSE).

---

**Note:** For detailed information on the Sol language syntax, features, and standard library, refer to the [Sol Language Reference](./docs/reference.md).

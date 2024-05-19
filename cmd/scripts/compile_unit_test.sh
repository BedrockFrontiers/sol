#!/usr/bin/env bash

# Copyright © 2024 Bedrock Frontiers. All rights reserved.
# This script is subject to the terms and conditions of the Apache License, Version 2.0.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Directories containing source files
PKG_DIR=../../pkg
UTILS_DIR=../../utils
TEST_DIR=../../tests/units
BIN_DIR=$TEST_DIR/bin

# Prompt the user to enter the test unit file name
read -p "Enter the test unit file name (e.g., name.c): " test_file

# Check if the test file exists
if [ ! -f "$TEST_DIR/$test_file" ]; then
   echo "Error: Test file not found."
   read -p "Press Enter to continue..." pause
   exit 1
fi

# Check if the bin directory exists, create it if not
if [ ! -d "$BIN_DIR" ]; then
   mkdir "$BIN_DIR"
fi

echo "Compiling files..."

# Function to compile the source files
compile_sources() {
   src_files=""
   includes_folders=""

   # Loop through each source file in the PKG_DIR and UTILS_DIR
   for file in $(find $PKG_DIR $UTILS_DIR -type f -name "*.c"); do
      src_files="$src_files $file"
   done

   # Loop through each subdirectory in PKG_DIR and UTILS_DIR to gather include folders
   for dir in $(find $PKG_DIR $UTILS_DIR -mindepth 1 -type d); do
      includes_folders+=" -I$dir"
   done

   # If the operating system type indicates Windows ('msys' or 'win32'),
   # set the file extension to '.exe' to ensure compatibility across Windows,
   # macOS, Linux, and other platforms.
   if [[ "$OSTYPE" == "msys" || "$OSTYPE" == "win32" ]]; then
      ext=".exe"
   else
      ext=""
   fi

   # Compile the test file along with all source files
   gcc $TEST_DIR/$test_file $src_files -o $BIN_DIR/${test_file%.c}$ext $includes_folders -no-pie

   # Check if compilation was successful
   if [ $? -eq 0 ]; then
      # Display the path to the compiled executable
      echo "Compilation done! Executable path: $BIN_DIR/${test_file%.c}$ext"
   else
      echo "Error: Compilation failed."
      read -p "Press Enter to continue..." pause
      exit 1
   fi
}

# Call the compile_sources function
compile_sources

# Pause for user to read the message
read -p "Press Enter to continue..." pause
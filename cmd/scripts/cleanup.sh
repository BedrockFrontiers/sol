#!/bin/bash

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

# Array containing the paths of the directories to be checked
directories=("../../tests/units/bin")
echo "Cleaning up..."

# Loop through each element in the array
for dir in "${directories[@]}"; do
	# Check if the directory exists before removing it
	if [ -d "$dir" ]; then
		rm -r "$dir"
		echo "Directory $dir removed."
	fi
done

echo "Done."
read -p "Press Enter to continue..." pause
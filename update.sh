#!/bin/bash

# Function to check internet connectivity
function check_internet() {
    wget -q --spider http://google.com
    if [ $? -eq 0 ]; then
        echo "Internet is available."
        return 0
    else
        echo "No internet connection."
        return 1
    fi
}

# Check for internet connectivity
check_internet
if [ $? -ne 0 ]; then
    exit 1
fi

# Change to the script's directory (repository root)
cd "$(dirname "$0")"

# Check for updates
git fetch
UPSTREAM=${1:-'@{u}'}
LOCAL=$(git rev-parse @)
REMOTE=$(git rev-parse "$UPSTREAM")

# If updates are available, pull them and build
if [ $LOCAL != $REMOTE ]; then
    echo "Pulling updates..."
    git pull
    echo "Navigating to src directory..."
    cd src
    echo "Building the project..."
    cmake --build . -j8
else
    echo "Your repository is up to date."
fi
#!/bin/bash

gcc ./fan/fan-control.c -l wiringPi -o fan/fanC
sudo chmod 777 ./fan/fanC

# Dynamically find the absolute path of fanC
FAN_PATH="$(pwd)/fan/fanC"

FILE="/etc/crontab"
LINE="@reboot root $FAN_PATH &"

# Check if the line exists in the file
sudo grep -qxF "$LINE" "$FILE"

# If the line was not found, add it
if [ $? -ne 0 ]; then
   echo "$LINE" | sudo tee -a "$FILE" > /dev/null
   echo "Line was added."
else
   echo "Line already exists."
fi

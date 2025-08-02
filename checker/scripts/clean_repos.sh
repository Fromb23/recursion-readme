#!/bin/bash

# Get the directory of this script
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$SCRIPT_DIR/.."

LOG_FILE="$ROOT_DIR/logs/repo_timestamps.log"
TEMP_LOG="$ROOT_DIR/logs/repo_timestamps.tmp"
CUTOFF=60  # 24 hours
NOW=$(date +%s)

mkdir -p "$ROOT_DIR/logs"
> "$TEMP_LOG"

while IFS=: read -r USERNAME REPO_DIR TIMESTAMP; do
	# Skip malformed lines
	if [[ -z "$USERNAME" || -z "$REPO_DIR" || -z "$TIMESTAMP" ]]; then
		continue
	fi

	AGE=$((NOW - TIMESTAMP))

	if [ "$AGE" -ge "$CUTOFF" ]; then
		echo "Deleting expired repo: $REPO_DIR (owned by $USERNAME, age: ${AGE}s)"
		rm -rf "$ROOT_DIR/$REPO_DIR"
	else
		echo "$USERNAME:$REPO_DIR:$TIMESTAMP" >> "$TEMP_LOG"
	fi
done < "$LOG_FILE"

mv "$TEMP_LOG" "$LOG_FILE"

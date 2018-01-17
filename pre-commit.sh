#!/usr/bin/env bash
set -eu
exitCode=0
if git rev-parse --verify HEAD >/dev/null 2>&1
then
  against=HEAD
else
  # Empty tree hash
  against=4b825dc642cb6eb9a060e54bf8d69288fbee4904
fi

# Redirect output to stderr.
exec 1>&2
files="$(mktemp)"
lintableFiles="$(mktemp)"

# Add Added, Copied, Modified, Renamed and Type Changed files to list
git diff-index --name-only --diff-filter=ACMRT --cached $against > $files

while read -r file; do
  if [[ $file == *.c || $file == *.h ]]
  then
    echo "$file" >> "$lintableFiles"
  fi
done < "$files"

if [[ -s "$lintableFiles" ]]
then
  clang-format -i $(cat "$lintableFiles")
  exitCode=$?
fi

rm "$files"
rm "$lintableFiles"

exit "$exitCode"

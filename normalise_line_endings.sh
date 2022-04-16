#!/bin/bash

# This is useful for a project that is checked out on windows, but all files are run on a linux machine
# otherwise we run into an issue where windows line endings are seen on the linux side which sometimes
# causes unexpected behavior.

git config core.eol lf
git config core.autocrlf input

git rm --cached --rf .
git reset --hard

git commit -m "Normalise line endings."
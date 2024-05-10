#!/usr/bin/env bash

if [ $# -eq 0 ]; then
    echo "Error: No destination folder specified."
    exit 1
fi

echo "Copy to folder : $1"

pictures=$(find . -iname '*.jpg' -or -iname '*.heic')
for picture in $pictures;
do
	if [[ -e "$1/$(basename "$picture")" ]]; then
		echo "File already exists !"
	else 
		if cp "$picture" "$1"; then
			echo "Copied !"
		else
			echo "Error !"
		fi
	fi
done

echo "Ordering folder $1"
exiftool '-Directory<DateTimeOriginal' -d "$1/%Y/%m/%d" "$1"
echo "Done !"

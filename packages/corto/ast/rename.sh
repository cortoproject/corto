for name in Fast*
do
    newname=ast"$(echo "$name" | cut -c5-)"
    mv "$name" "$newname"
done

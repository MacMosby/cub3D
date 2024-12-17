for file in maps/*.cub; do
    if [ -f "$file" ]; then
        echo "Processing '$file'"
        valgrind -q ./cub3D "$file"
    else
        echo "No .cub files found in the current directory."
        exit 0
    fi
done

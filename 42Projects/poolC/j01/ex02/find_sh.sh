find . -name "*.sh" | cut -d, -f 2 | sed 's/\(\.sh\)$//' | grep -o '[^\/]\+$'

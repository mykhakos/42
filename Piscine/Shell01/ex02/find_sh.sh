find -type f -name "*.sh" | rev | cut -f1 -d '/' | cut -f2- -d '.' | rev

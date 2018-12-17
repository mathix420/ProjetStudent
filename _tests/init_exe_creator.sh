echo "#!/bin/sh\n$1\n\nWrite in $2"
echo "#!/bin/sh\n$1" > $2
find . \( -name '*~' -type f -or -name '#*#' -type f -or -name 'a.out' -type f -or -name 'a.out.dSYM' -type d \) | xargs rm -rf
chmod +x $2

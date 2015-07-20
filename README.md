# CheckMyTags
Analyze any document an looks for unclosed html tags

HOW TO USE:

go to src/ folder and...

1- Modify it if you want

2- Compile it
    (g++ -Wall -o ../bin/checkmytags checkmytags.cpp)

3- configure which tags you want to check in the lookfor.conf, one tag for line, unclosed

4- run it passing the file as first param and the lookfor.conf file as second
    (checkmytags index.html ../lookfor.conf)

    ALSO, you can just run "checkmytags index.html" if there's a lookfor.conf file in the same folder u are runnit it from

5- share


OR

just execute the binary "checkmytags" in the bin folder


REMEMBER, the config file has to be in the same folder you are running the executable from.
Also, you can pass the config file path as second argument.

checkmytags PATH/OF/HTML/TO/ANALYZE PATH/OF/CONFIG/FILE

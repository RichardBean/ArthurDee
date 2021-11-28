# ArthurDee

C code for deciphering the Arthur Dee manuscript.

The "dee2.history" file is a Bash history list of commands tried in the deciphering process.

The critical line is line 2691

2691  cat dee2 | tr ' ' '\n' | awk '{print length,$0}' | sort -nr | awk '{print $2}' | while read w; do echo $w; cat lat.words | ./ptestfix $w | head -1 ; done   > ptestfix.top

The first part before the "while" produces a list of ciphertext words in descending order of length, then "ptestfix" uses the ordinary Porta table to check
what the most popular Latin word corresponding to that word was. Then repeated patterns became evident in the file "ptestfix.top" (29 August, 17:32 AEDT).

The process is summarized in the file "dee-solving.txt".

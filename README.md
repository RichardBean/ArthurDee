# Solving an alchemical cipher in a shared notebook of John and Arthur Dee

C code for deciphering the Arthur Dee manuscript for the paper ["Solving an alchemical cipher in a shared notebook of John and Arthur Dee" by Bean, Lang and Piorko, from Proceedings of Histocrypt 2022](https://doi.org/10.3384/ecp188388).

A [Google Sheets illustration of the decipherment](https://docs.google.com/spreadsheets/d/1SIB59QxKms1ka8KCQtXwLYEOujf7tI5a/edit?usp=sharing&ouid=116745699215337849405&rtpof=true&sd=true) is available.

[The Conversation](https://theconversation.com/deciphering-the-philosophers-stone-how-we-cracked-a-400-year-old-alchemical-cipher-167900) and [Atlas Obscura](https://www.atlasobscura.com/articles/medieval-alchemist-secret-code) have articles about the manuscript and the process.

The "dee2.history" file is a Bash history list of commands tried in the deciphering process.

The critical line is line 2691

2691  cat dee2 | tr ' ' '\n' | awk '{print length,$0}' | sort -nr | awk '{print $2}' | while read w; do echo $w; cat lat.words | ./ptestfix $w | head -1 ; done   > ptestfix.top

The first part before the "while" produces a list of ciphertext words in descending order of length, then "ptestfix" uses the ordinary Porta table to check
what the most popular Latin word corresponding to that word was. Then repeated patterns became evident in the file "ptestfix.top" (29 August, 17:32 AEDT).

The process is summarized in the file "dee-solving.txt".

As part of a programming assignemnt under the Cryptography course of Stanford I have made a module in C++ 
to perform file encryption in chunks rather than as a whole, in order to allow large video files to be authenticated,
verified and played chunk by chunk rather than the video playing only after all chunks are authenticated. I used a collison
ressitant hash function for the same(SHA 256). The file to be hashed needs to be stored in the same folder as the program 
and a hashes.txt file is created which has the hash of each chunk of 1KB.

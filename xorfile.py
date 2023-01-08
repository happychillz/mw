#!/usr/bin/python3
import sys

def main():
    if len(sys.argv) < 2:
        print("Usage:  ./xorfile.py <file.exe>")
        exit()

    b = bytearray(open(sys.argv[1], 'rb').read())
    for x in range(len(b)):
        b[x] ^= 0x77

    open('internet_explorer.blob', 'wb').write(b)

if __name__ == '__main__':
    main()

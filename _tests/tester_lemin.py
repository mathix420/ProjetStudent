#!/usr/bin/python3

from math import ceil

file = open("res", "r")
file_map = open("map", "r")

out = 0;

count = 0;

map = file_map.read()

output = file.read()

max = int(map.split("#Here is the number of lines required: ")[1].split("##start")[0])

for line in output.split('\n'):
    if "NEW PATH ::" in line and int(line.split(' ')[-1]) <= max + 1:
        out += (max - int(line.split(' ')[-1])) + 2
        count += 1

file.close()
file_map.close()

print()
print(out, "ants passed on", map.split('\n')[0], "needed with", count, "path")
if (out < int(map.split('\n')[0])):
    print(ceil((int(map.split('\n')[0]) - out) / count), "more step needed to pass them all")
elif out > int(map.split('\n')[0]):
    print("Better than generator")

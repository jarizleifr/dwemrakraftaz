# Penultima Map Converter version 1.0
#
# This converter searches for Tiled Map Editor .CSV files
# and converts them to binary data files.

import os
import math
import csv

def main():
    for root, dirs, files in os.walk("./csv"):
        for filename in files:
            # Initialize empty lists
            tiles = []

            # Map width and height
            map_width = 0
            map_height = 0

            success = False
            
            try:
                csvfile = open("csv\\" + filename, 'r')
                success = True

            except IOError:
                print("File read error! File " + filename + ".csv not found in directory!")
                
            # If current file was found successfully, parse it
            if (success == True):
                mapreader = csv.reader(csvfile, delimiter=',')
                i = 0
                for row in mapreader:
                    i = i + 1
                    for column in row:
                        # Convert data to integer format
                        data = int(column)
                        # Tiled Map Editor uses -1 for cells not containing any tiles
                        # If -1 found, default it to 0 instead, so we can use unsigned integers in c++
                        
                        data = data - 384;
                        
                        if (data < 0):
                            data = 0
                            
                        if (data >= 96):
                            data = math.floor((data - 96) / 2) + 96

                        tiles.append(data)

                map_width = len(row)
                map_height = i
                csvfile.close()

                # If all map files were processed successfully, write data to binary file
                filename = filename[0:-4]
                binfile = open("output\\" + filename + ".map", 'wb')
                last_x_pos = map_width - 1
                last_y_pos = map_height - 1
                binfile.write(last_x_pos.to_bytes(1, byteorder='little'))
                binfile.write(last_y_pos.to_bytes(1, byteorder='little'))
                for y in range(0, map_height):
                    for x in range(0, map_width):
                        binfile.write(tiles[x + y * map_width].to_bytes(1, byteorder = 'little'))
                binfile.close()
                
                print("Map file " + filename + ".map created successfully!")

if __name__ == "__main__":
    main()
